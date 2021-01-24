#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>
#include <fstream>

#include <ctime> // для функции time()
#include <cstdlib> // для функций rand() и srand()

#include "battleship.hpp"

static Player* human = new Player(true);
static Player* computer = new Player(false);

static int shotResult = 0;
static bool humanMove = true;
static bool doubleMove = false;
static Coords shot{ 1, 1 };
static Coords aiShot{ 100, 100 };

static string path = "mySaves.txt";
static fstream fs;

static Texture texture_background, texture_ship, texture_damaged, texture_dead, texture_miss, texture_aim;



void menu()
{
	char choice = '0';
	while (choice != 'q')
	{
		system("cls");
		cout << "\nНовая игра:                               '1'" << endl;
		cout << "Продолжить:                               '2'" << endl;
		cout << "Выход:                                    'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
			setByDefault();
			human->initializeFleet();
			theGame();
			continue;
		case '2':
			setByDefault();
			fastLoadGame();
			theGame();
			continue;
		default:
			continue;
		}
	}
	delete human;
	delete computer;
}
void setByDefault()
{
	delete computer;
	delete human;
	computer = new Player(false);
	human = new Player(true);
	shotResult = 0;
	humanMove = true;
	doubleMove = false;
	Coords shot{ 1, 1 };
	Coords aiShot{ 100, 100 };
}
void fastSaveGame()
{
	fs.open(path, ios::out | ios::trunc); // Очищает файл
	fs.close();

	fs.open(path, fstream::in | fstream::out | fstream::app); // Файл открыт на чтение и на запись

	if (!fs.is_open()) cout << "Не удалось открыть файл!" << endl;
	else
	{
		cout << "Saving..." << endl;
		fs.clear();
		fs << *human;
		fs << *computer;

		fs << "\n" << shotResult << " " << humanMove << " " << doubleMove << " " << shot << aiShot;

		fs.close();
	}
	Sleep(500);
}
void fastLoadGame()
{
	fs.open(path, fstream::in | fstream::out | fstream::app);
	system("cls");
	if (!fs.is_open()) cout << "Не удалось открыть файл!" << endl;
	else
	{
		cout << "Loading..." << endl;
		fs >> *human;
		fs >> *computer;

		fs >> shotResult >> humanMove >> doubleMove >> shot >> aiShot;

		fs.close();
	}
	Sleep(800);
	system("cls");
	cout << "Ваш наводящий ужас флот вернулся в бой!\n";
	human->showInfo();
	Sleep(1800);
	cout << "\nСтрашная армада бездушной машины рвётся, чтобы уничтожить вас!\n";
	computer->showInfo(true);
}
void bfAim(RenderWindow& battleship, float teamStartPosition, int stepL, int stepN, Texture texture)
{
	Sprite spriteAim(texture);
	spriteAim.setScale(step / 220, step / 220);

	spriteAim.move( (teamStartPosition + step * (stepL - 1)) - (step / 10), (startOne + step * (stepN - 1)) - (step / 12)        );
	battleship.draw(spriteAim);
}
void showGameInfo()
{
	system("cls");
	cout << "Ваш флот:\n";
	human->showInfo();
	cout << "\nФлот соперника:\n";
	computer->showInfo(true);
}
void setColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void drawNet(RenderWindow& battleship, float first, float second, int step)
{
	VertexArray lines(LinesStrip, 44);
	bool add = false;

	for (int i = 0; i < 21; i++)
	{
		lines[i].position = Vector2f(first, second);

		if (i % 2 != 0)
		{
			second = add ? second - step * 10 : second + step * 10;
			add = !add;
			continue;
		}
		first += step;
	}
	first -= step;
	for (int i = 21; i < 42; i++)
	{
		lines[i].position = Vector2f(first, second);

		if (i % 2 != 0)
		{
			first = add ? first + step * 10 : first - step * 10;
			add = !add;
			continue;
		}
		second += step;
	}
	lines[42].position = Vector2f(first, second);
	second -= step * 10;
	lines[43].position = Vector2f(first, second);

	battleship.draw(lines);
}
int rnd(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void theGame()
{
	ContextSettings settings;
	settings.antialiasingLevel = 4;


	//texture.loadFromFile("C:\\dev\\SFML_Tutorial\\images\\tiles.png");
	texture_background.loadFromFile("images\\background.jpg");
	texture_aim.loadFromFile("images\\aim.png");
	texture_miss.loadFromFile("images\\miss.png");
	texture_ship.loadFromFile("images\\ship.png");
	texture_damaged.loadFromFile("images\\damaged.png");
	texture_dead.loadFromFile("images\\dead.png");

	Sprite sprite_background(texture_background); // Создание спрайтов

	RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");


	Sleep(1000);
	computer->InitializeRandomFleet();


	// Главный цикл приложения: выполняется, пока открыто окно
	while (battleship.isOpen())
	{
		if (!humanMove) // Ход компа
		{
			Sleep(rnd(400, 1300));
			aiShot = computer->aiAim(human->getMap());
			shotResult = human->takeShot(aiShot); // 0 - (не попал) 1 - (подбил) 2 - (уничтожил) 3 - (ошибочный выстрел в уже уничтоженную клетку)
			system("cls");

			if (shotResult == 1 || shotResult == 2)
			{
				human->updateShipData(aiShot);
				doubleMove = !doubleMove;
			}
			else doubleMove = false;
			
			showGameInfo();

			if (shotResult != 3) humanMove = doubleMove ? humanMove : !humanMove;
			else cout << "Если напечатано это, значит что-то пошло не так!!!" << endl;
		}

		// Обрабатываем события в цикле
		Event event;
		while (battleship.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				system("cls");
				fastSaveGame(); // Закрывая окно - происходит быстрое сохранение ткрущей игры
				battleship.close();
				return;
			}

			// Была ли нажата клавиша на клавиатуре?
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Left && shot.L > 1) shot.L--;
				else if (event.key.code == Keyboard::Right && shot.L < 10) shot.L++;
				else if (event.key.code == Keyboard::Up && shot.N > 1) shot.N--;
				else if (event.key.code == Keyboard::Down && shot.N < 10) shot.N++;
				else if (event.key.code == Keyboard::Enter && humanMove) // Ход человека
				{
					shotResult = computer->takeShot(shot); // 0 - (не попал) 1 - (подбил) 2 - (уничтожил) 3 - (ошибочный выстрел в уже уничтоженную клетку)
					system("cls");

					if (shotResult == 1 || shotResult == 2)
					{
						computer->updateShipData(shot);
						doubleMove = !doubleMove;
					}
					else doubleMove = false;
					showGameInfo();
					if (shotResult != 3) humanMove = doubleMove ? humanMove : !humanMove;
					else cout << "Сюда уже стреляли! Стреляйте не сюда!" << endl;
				}
				else if (event.key.code == Keyboard::Escape)
				{
					fastSaveGame();
					battleship.close();
				}
		}
		battleship.clear(Color::White);
		battleship.draw(sprite_background);
		//computer->drawSquare(battleship, startOne, aiShot.N, aiShot.L);

		//battleship.clear(Color::Black); // Установка цвета фона

		drawNet(battleship, startOne, startOne, (int)step);
		drawNet(battleship, startTwo, startOne, (int)step);

		human->drawFleet(battleship, startOne);
		human->drawBattlefield(battleship, startOne);

		//computer->drawFleet(battleship, startTwo);
		computer->drawBattlefield(battleship, startTwo);


		bfAim(battleship, startTwo, shot.L, shot.N, texture_aim);
		bfAim(battleship, startOne, aiShot.L, aiShot.N, texture_aim);
		//bfPtr(battleship, startTwo, shot.L, shot.N);
		//bfPtr(battleship, startOne, aiShot.L, aiShot.N, Color::Red);

		//human->drawSquare(battleship, startOne, aim.L, aim.N, Color::Magenta);
		


		battleship.display(); // Отрисовка окна
		if (human->getMyFleet().size() == 0)
		{
			break;
		}
		else if (computer->getMyFleet().size() == 0)
		{
			break;
		}


	}
	system("cls");
}

ostream& operator<<(ostream& os, const Ship& s)
{
	os << s.name << " " << s.horizontal << " " << s.getSize() << " " << s.getDamagedSize() << "\n";
	for (auto& item : s.decksPos) os << item;
	for (auto& item : s.damaged) os << item;
	os << "\n";
	return os;
}
istream& operator>>(istream& is, Ship& s)

{
	int deckSize, damagedSize;
	Coords cd;
	is >> s.name >> s.horizontal >> deckSize >> damagedSize;

	for (int i = 0; i < deckSize; i++)
	{
		is >> cd;
		s.decksPos.push_back(cd);
	}
	for (int i = 0; i < damagedSize; i++)
	{
		is >> cd;
		s.damaged.push_back(cd);
	}
	return is;
}
ostream& operator<<(ostream& os, const Battlefield& bf)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++) os << bf.map[i][j] << " ";

	for (int i = 0; i < 4; i++) os << bf.limit[i] << " ";
	os << "\n";
	return os;
}
istream& operator>>(istream& is, Battlefield& bf)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++) is >> bf.map[i][j];

	for (int i = 0; i < 4; i++) is >> bf.limit[i];
	return is;
}
ostream& operator<<(ostream& os, const Player& p)
{
	os << p.isHuman << " " << p.getFleetSize() << " " << p.aiMemorySize() << "\n";
	for (auto& item : p.fleet) os << item;
	for (auto& item : p.aiEvilMemory) os << item;
	os << "\n";

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++) os << p.map[i][j] << " ";

	for (int i = 0; i < 4; i++) os << p.limit[i] << " ";
	os << "\n";

	return os;
}
istream& operator>>(istream& is, Player& p)
{
	int fleetSize, aiMemorySize;
	is >> p.isHuman >> fleetSize >> aiMemorySize;

	for (int i = 0; i < fleetSize; i++)
	{
		Ship sh;
		is >> sh;;
		p.fleet.push_back(sh);
	}
	for (int i = 0; i < aiMemorySize; i++)
	{
		Coords cd;
		is >> cd;
		p.aiEvilMemory.push_back(cd);
	}

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++) is >> p.map[i][j];

	for (int i = 0; i < 4; i++) is >> p.limit[i];
	return is;
}


Ship::Ship(int LScale, int NScale, string name, int size, bool horiz) : name(name), horizontal(horiz)
{
	for (int i = 0; i < size; i++)
	{
		if (horiz) decksPos.push_back(Coords{ LScale, NScale + i });
		else decksPos.push_back(Coords{ LScale + i, NScale });
	}
}

void Ship::showInfo() const
{
	bool isAlive = decksPos.size();
	string alive = isAlive ? "Да" : "Нет";
	string sailing = isHorizontal() ? "Вдоль горизонта" : "В горизонт";

	cout << name << " (";
	for (int i = 0; i < getSize(); i++)
	{
		cout << (char)(64 + decksPos[i].N) << decksPos[i].L;
		if(i + 1 != getSize()) cout << ", ";
	}
	cout << ") Ещё в строю: " << alive << " (прочность " << decksPos.size() << ")" << endl;

	if (isAlive) cout << "Плывёт: " << sailing << endl;
	else cout << "Куда плыл, пока не припыл: " << sailing << endl;
}
void Ship::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	for (int i = 0; i < decksPos.size(); i++)
	{
		bfAim(battleship, teamStartPosition, decksPos[i].N, decksPos[i].L, texture_ship);


	}
}


bool Battlefield::isPlaceAvailable(int letterVal, int numberVal, int size, bool horiz)
{
	if (map[letterVal][numberVal] || letterVal < 1 || letterVal > 10 || numberVal < 1 || numberVal > 10) return false;
	if (size > 1)
	{
		if (horiz) return isPlaceAvailable(letterVal, numberVal + 1, size - 1, horiz);
		else return isPlaceAvailable(letterVal + 1, numberVal, size - 1, horiz);
	}
	return true;
}
void Battlefield::boundPlace(Ship& ship)
{
	int L, N;
	for (int i = 0; i < ship.getSize(); i++)
	{
		L = ship.getDecks()[i].L;
		N = ship.getDecks()[i].N;

		map[L][N] = ship.getSize() + 1;
		for (int j = -1; j < 2; j++)
		{
			if (map[L + 1][N + j] < 1) map[L + 1][N + j] = 1;
			if (map[L + 0][N + j] < 1) map[L + 0][N + j] = 1;
			if (map[L - 1][N + j] < 1) map[L - 1][N + j] = 1;
		}			
	}
}
Battlefield::Battlefield()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 || i == 11 || j == 0 || j == 11) map[i][j] = 9; // Заграничные области помечены как подбитые
			else map[i][j] = 0;
		}
}
int Battlefield::takeShot(Coords LN) // Возвращает: 0 - (не попал) 1 - (подбил) 2 - (уничтожил) 3 - (ошибочный выстрел в уже уничтоженную клетку)
{
	int result = 0;
	if (map[LN.N][LN.L] > 1 && map[LN.N][LN.L] < 6) // Диапозод значаний кораблей
	{
		result = 1; // подбито
		if (map[LN.N][LN.L] == 2) result = 2; // уничтожено
	}
	else if (map[LN.N][LN.L] < 2) map[LN.N][LN.L] = 9; // промах
	else if (map[LN.N][LN.L] > 5) result = 3; // уже стреляли сюда зачем еще стрелять то?
	return result;
}
void Battlefield::showSimpleBoundMap() const
{
	setColor(Red, LightCyan);

	cout << "     ";
	for (int i = 0; i < 10; i++) cout << (char)('A' + i) << "  ";
	cout << "\n" << setfill(' ') << setw(36) << "\n";

	for (int i = 1; i < 11; i++)
	{
		setColor(Red, LightCyan);
		cout << setfill(' ') << setw(2 - (int)(i / 10)) << i << "   ";
		setColor(Black, LightCyan);
		for (int j = 1; j < 11; j++)
		{
			if (map[i][j])
			{
				if (map[i][j] > 6) setColor(LightRed, LightCyan);
				else if (map[i][j] > 1) setColor(Blue, LightCyan);
				else setColor(White, LightCyan);
				cout << map[i][j] - 1 << "  ";
				setColor(Black, LightCyan);
			}
			else cout << map[i][j] << "  ";
		}
		if (i != 10) cout << endl;
	}
	cout << "\n" << setfill(' ') << setw(36) << "\n";
	setColor(White, Black);
	cout << "\n";
}
void Battlefield::drawBattlefield(RenderWindow& battleship, float teamStartPosition) const
{
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 11; j++)
		{
			if (map[i][j] == 7 || map[i][j] == 8) bfAim(battleship, teamStartPosition, j, i, texture_damaged);
			// else if (map[i][j] == 6) drawSquare(battleship, teamStartPosition, i, j, Color::White);
			//else if (map[i][j] == 8) drawSquare(battleship, teamStartPosition, i, j, Color::Red);
			else if (map[i][j] == 9) bfAim(battleship, teamStartPosition, j, i, texture_miss);
			if (map[i][j] == 8)  bfAim(battleship, teamStartPosition, j, i, texture_dead);
			//else if (map[i][j] == 9) drawSquare(battleship, teamStartPosition, i, j, Color::Cyan);
		}
	
}
void Battlefield::drawSquare(RenderWindow& battleship, float teamStartPosition, int L, int N, Color color) const
{
	RectangleShape rectangle(Vector2f(step, step));
	rectangle.move(teamStartPosition + step * (N - 1), startOne + step * (L - 1));
	rectangle.setFillColor(color);
	battleship.draw(rectangle);
}






void Player::initializeFleet()
{
	char choice = '0';
	//ShipID listOfShips[4] { {"Плот", 4},{"Шлюпка", 3},{"Лодка", 2},{"Катер", 1} };
	system("cls"); showSimpleBoundMap();
	bool idRandAvail = true;
	//for (int i = 0; i < 10; i++)
	while(getFleetSize() < 10)
	{
		 // костыль
		cout << "Разместите Ваш могучий флот:\n\n";
		for (int i = 0; i < 4; i++)	
			if (limit[i]) cout << i + 1 << ": " << names[i] << " (" << limit[i] << " шт.)\n";
		if (idRandAvail) cout << "5: Разместить случайно\n";
			
		cin >> choice;
		switch (choice)
		{
		case '1':
			idRandAvail = false;
			system("cls"); showSimpleBoundMap();
			if (!limit[0]) continue;
			placeShip(names[0], 1, limit[0]);
			continue;
		case '2':
			idRandAvail = false;
			system("cls"); showSimpleBoundMap();
			if (!limit[1]) continue;
			placeShip(names[1], 2, limit[1]);
			continue;
		case '3':
			idRandAvail = false;
			system("cls"); showSimpleBoundMap();
			if (!limit[2]) continue;
			placeShip(names[2], 3, limit[2]);
			continue;
		case '4':
			idRandAvail = false;
			system("cls"); showSimpleBoundMap();
			if (!limit[3]) continue;
			placeShip(names[3], 4, limit[3]);
			continue;
		case '5':
			isHuman = false;
			human->InitializeRandomFleet();
			isHuman = true;
			system("cls"); showSimpleBoundMap();
			continue;
		default:
			//i--;
			continue;
		}
		Sleep(2000);
	}
}
void Player::InitializeRandomFleet()
{
	int size, lim;

	for (int i = 0; i < 4; i++)
	{
		size = i + 1;
		lim = limit[i];

		for (int j = 0; j < lim; j++)
		{
			placeShip(names[i], size, limit[i]);
		}
	}
}
void Player::placeShip(string name, int size, int& lim)
{
	int x, y;

	if (isHuman)
	{
		cout << "Размещаем " << name << "\n\n";
		setCoords(x, y);
	}
	else { x = rnd(); y = rnd(); } // комп пытается задать координаты
	
	if (!isPlaceAvailable(x, y))
	{
		if (isHuman)
		{
			system("cls"); showSimpleBoundMap();
			cout << "Невозможно разместить корабль здесь. Попробуйте снова\n\n";
			cout << endl;
		}
		return placeShip(name, size, lim);
	}
	if (size > 1)
	{
		string toBool;
		bool horiz;

		if (isHuman)
		{
			cout << "\n1: Вертикально\n2: Горизонтально" << endl;
			getline(cin >> ws, toBool);
			horiz = (int)(char)toBool[0] - '0' - 1;
		}
		else horiz = rnd(0, 1); // комп пытается выбрать направление

		if (isPlaceAvailable(x, y, size, horiz)) // Если всё ок и корабль тут разместить можно
		{
			
			lim--;
			fleet.push_back(Ship{ x, y, name, size, horiz});
			boundPlace(fleet[fleet.size() - 1]);

			if (isHuman)
			{
				system("cls"); showSimpleBoundMap(); 
				cout << "На полях (" << (char)(64 + y) << x;
				for (int i = 1; i < fleet[fleet.size() - 1].getSize(); i++)
				{
					cout << ", ";
					if (horiz) cout << (char)(64 + y + i) << x;
					else cout << (char)(64 + y) << x + i;
				}
				cout << ") размещён: " << name << "\n\n";
			}
			return;
		}
		if (isHuman)
		{
			system("cls"); showSimpleBoundMap();
			cout << "Невозможно разместить корабль здесь. Попробуйте снова\n\n";
			cout << endl;
		}
		return placeShip(name, size, lim);
	}
	if (isPlaceAvailable(x, y, size, true)) // Если всё ок и корабль тут разместить можно
	{
		lim--;
		fleet.push_back(Ship{ x, y, name, size });
		boundPlace(fleet[fleet.size() - 1]);

		if (isHuman)
		{
			system("cls"); showSimpleBoundMap();
			cout << "На поле (" << (char)(64 + y) << x << ") размещён: " << name << "\n\n";
		}
		return;
	}
	if (isHuman)
	{
		system("cls"); showSimpleBoundMap();
		cout << "Невозможно разместить корабль здесь. Попробуйте снова\n\n";
		cout << endl;
	}
	return placeShip(name, size, lim);
}
void Player::setCoords(int& X, int& Y)
{
	string userInput;
	cout << "Задайте координаты: " << endl;

	getline(cin >> ws, userInput); // Пользователь вводит строку
	userInput.erase(std::remove(userInput.begin(), userInput.end(), ' '), userInput.end()); // Удаляем из неё пробелы

	if ((char)userInput[1] - '0' == 1 && (char)userInput[2] - '0' == 0) X = 10;
	else X = (char)userInput[1] - '0'; // Рассматриваем первый ...
	Y = letterTointY((char)userInput[0]); // ... и второй символы, преобразуем их в int

	if (X > 0 && X < 11 && Y > 0 && Y < 11) { x = X; y = Y; } // Если результат в пределах диапозона, тогда всё ок
	else
	{
		system("cls"); showSimpleBoundMap();
		cout << "Ошибочка, попробуйте снова" << endl;
		setCoords(X, Y); // Рекурсивно исправляем ошибку, пока не будет введено корректное значение
	}
}
int Player::letterTointY(char letter)
{
	return (int)letter - 96 > 0 ? (int)letter - 96 : (int)letter - 64;
}

void Player::updateShipData(const Coords LN) // Функцию нужно (и имеет смысл) вызывать только если было попадание в корабль
{
	for (auto itShip = getMyFleet().begin(); itShip != getMyFleet().end(); ++itShip) // Перемещаемся по вектору кораблей
	{
		for (auto itDeck = itShip->getDecks().begin(); itDeck != itShip->getDecks().end(); ++itDeck) // В каждом корабле по палубам
		{
			if (itDeck->L == LN.N && itDeck->N == LN.L) // Если нашли палубу в которую было попадание...
			{
				removeShipDeck(*itShip, itDeck, LN); // ... Удаляем её из корабля
				removeShipIfDead(itShip); // Если это была последняя палуба на корабле, удаляем корабль
				return; // Функция выполнила свою цель, возвращаемся
			}
		}
	}
}
void Player::removeShipDeck(Ship& ship, vector<Coords>::iterator& iterator, const Coords LN)
{// эта хрень должна работать...
	getMap()[iterator->L][iterator->N] = 7; // Указываем в ячеёке карты значение подбитой палубы корабля
	ship.getDamagedDecks().push_back(*iterator);
	ship.getDecks().erase(iterator); // Удаляем палубу
	for (auto& deck : ship.getDecks()) getMap()[deck.L][deck.N]--; // Изменяем на карте значения палуб данного корабля (т.к. он стал меньше на 1)
}
void Player::removeShipIfDead(vector<Ship>::iterator& iterator)
{
	if (iterator->getSize() == 0)
	{
		for (auto& deadDeck : iterator->getDamagedDecks())
		{
			getMap()[deadDeck.L][deadDeck.N] = 8;
		}
		getMyFleet().erase(iterator);
	}

}
void Player::showInfo(bool hideLocations)
{
	cout << "Кораблей: " << getMyFleet().size() << "\n\n";

	for (auto& ship : getMyFleet())
	{
		cout << ship.getName();
		if (!hideLocations)
		{
			cout << ". Палуб живо: -" << ship.getSize() << "- " << " (";
			for (int i = 0; i < ship.getSize(); i++)
			{
				cout << (char)(64 + ship.getDecks()[i].N) << ship.getDecks()[i].L;
				if (i + 1 != ship.getSize()) cout << ", ";
			}
			cout << ")";
		}
		cout << "\n";
	}
}

Coords Player::aiAim(int map[12][12])
{
	/*
	// Анализ памяти
	for (auto it = getAiEvilMemory().begin(); it != getAiEvilMemory().end(); ++it) // Пройдемся по его памяти
	{ // Если корабль ещё не потоплен   
		aiBoundAroundWhenHit(map, *it);
		if (map[it->N][it->L] == 8) // 2 (значит это была последняя палуба, корабль будет убит); 3, 4, 5 (попадание по палубе, нужно продолжать стрелять рядом)
		{
			aiBoundAroundWhenKill(map, *it);
			getAiEvilMemory().erase(it);
			--it;
		}
	}
	*/
	bool clearAiEvilMemory = false;
	for (auto& item : getAiEvilMemory())
	{
		aiBoundAroundWhenHit(map, item);
		if (map[item.N][item.L] == 8)
		{
			aiBoundAroundWhenKill(map, item);
			clearAiEvilMemory = true;
		}
	}
	if (clearAiEvilMemory) getAiEvilMemory().clear();


	Coords shotHere;
	if (getAiEvilMemory().size() > 0) shotHere = aiEvilPlan(map); // Если комп помнит что подбил корабль, то он разработает страшный план!
	else shotHere = { rnd(), rnd() };


	while (map[shotHere.N][shotHere.L] > 5) // Случайно выбираем поле, пока его значение не будет ниже 5 (т.е. пустое поле или корабль)
	{ // 7 (подбит) 8 (убит) 9 (промах)
		shotHere.L = rnd();
		shotHere.N = rnd();
	}
	// Далее кординаты уже не могут указывать на поле со значением больше 5
	if (map[shotHere.N][shotHere.L] > 1) // Комп попал в какой-то корабль
	{
		//bool clearAiEvilMemory = false;
		//cout << "We are in his memory!" << endl;
		getAiEvilMemory().push_back(shotHere); // Комп запоминает координаты подбитого корабля
		//for (auto it = getAiEvilMemory().begin(); it != getAiEvilMemory().end(); ++it) // Пройдемся по его памяти
		//{ // Если корабль ещё не потоплен   
		//	aiBoundAroundWhenHit(map, shotHere);
		//	if (map[it->N][it->L] == 2) // 2 (значит это была последняя палуба, корабль будет убит); 3, 4, 5 (попадание по палубе, нужно продолжать стрелять рядом)
		//	{
		//		aiBoundAroundWhenKill(map, shotHere);
		//		clearAiEvilMemory = true;
		//	}
		//	//cout << "\nLetter: " << it->L << "\nNumber: " << it->N << endl;
		//}
		 // Если злая машина разнесла корабль, она забудет о нём
	}
	return shotHere;
}
Coords Player::aiEvilPlan(int map[12][12])
{
	//cout << "We are inside of his thoughts!" << endl;
	vector<Coords> possiblePositions;
	//Coords& last = getAiEvilMemory()[getAiEvilMemory().size() - 1];

	for (auto& item : getAiEvilMemory())
	{
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				//cout << "Deep deep inside" << endl;
				if (map[item.N + i][item.L + j] < 6)
				{
					//cout << getRandTen(0, possiblePositions.size());

					possiblePositions.push_back(Coords{ item.L + j, item.N + i });
				}
			}
	}
	//cout << "\nChoice: " << "L: " << possiblePositions[ccccc].L << "\nN: " << possiblePositions[ccccc].N << endl;
	//cout << possiblePositions.size() << " << POSPOSlen ---- CHOICE >> " << ccccc << endl;
	return possiblePositions[rnd(0, possiblePositions.size() - 1)];
}
void Player::aiBoundAroundWhenHit(int map[12][12], Coords shotHere)
{
	if (map[shotHere.N + 1][shotHere.L + 1] < 2) map[shotHere.N + 1][shotHere.L + 1] = 6;
	if (map[shotHere.N - 1][shotHere.L + 1] < 2) map[shotHere.N - 1][shotHere.L + 1] = 6;
	if (map[shotHere.N + 1][shotHere.L - 1] < 2) map[shotHere.N + 1][shotHere.L - 1] = 6;
	if (map[shotHere.N - 1][shotHere.L - 1] < 2) map[shotHere.N - 1][shotHere.L - 1] = 6;
}
void Player::aiBoundAroundWhenKill(int map[12][12], Coords shotHere)
{
	if (map[shotHere.N][shotHere.L + 1] < 2) map[shotHere.N][shotHere.L + 1] = 6;
	if (map[shotHere.N][shotHere.L - 1] < 2) map[shotHere.N][shotHere.L - 1] = 6;
	if (map[shotHere.N + 1][shotHere.L] < 2) map[shotHere.N + 1][shotHere.L] = 6;
	if (map[shotHere.N - 1][shotHere.L] < 2) map[shotHere.N - 1][shotHere.L] = 6;
}







