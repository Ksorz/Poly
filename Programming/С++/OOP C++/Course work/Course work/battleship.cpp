#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <vector>
#include <string>
#include <Windows.h>

#include "battleship.hpp"

using namespace std;
using namespace sf;

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








void Ship::showInfo() const
{
	string alive = isAlive ? "Да" : "Нет";
	cout << "X: " << x << "\nY: " << y << "\nЕщё в строю: " << alive << " (прочность " << life << "/" << size << ")" << endl;
}
void BigShip::showInfo() const
{
	string alive = isAlive ? "Да" : "Нет";
	cout << "X: " << x << "\nY: " << y << "\nЕщё в строю: " << alive << " (прочность " << life << "/" << size << ")" << endl;
	string sailing = isHorizontal() ? "Вдоль горизонта" : "В горизонт";
	if (isAlive) cout << "Плывёт: " << sailing << endl;
	else cout << "Куда плыл пока не припыл: " << sailing << endl;
}
void Ship::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	RectangleShape rectangle(Vector2f(step, step));
	rectangle.move(teamStartPosition + (step * (x - 1)), startOne + (step * (y - 1))); 
	rectangle.setFillColor(isAlive ? Color::Green : Color::Red);
	battleship.draw(rectangle); 
}
void BigShip::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	for (int i = 0; i < size; i++)
	{
		RectangleShape rectangle(Vector2f(step, step));
		// Здесь задаём смещение относительно стартовой позиции (teamStartPosition) 
		// И условно изображаем большой корабль относильно его направления (isHorizontal)
		if (isHorizontal()) rectangle.move(teamStartPosition + (step * (x - 1)) + (step * i), startOne + (step * (y - 1))); // перемещаем
		else rectangle.move(teamStartPosition + (step * (x - 1)), startOne + (step * (y - 1)) + (step * i)); // перемещаем
		rectangle.setFillColor(deckIsOk[i] ? Color::Green : Color::Red); // Цвет относительно того, разрушена ли палуба
		battleship.draw(rectangle);
	}
}



/*
bool Battlefield::isPlaceAvailable(Ship& ship) const
{
	for (int i = 0; i < 3; i++) // Проверка полей вокруг начальных координат (включая координаты ship)
		for (int j = 0; j < 3; j++) if (isBound[ship.x + (i - 1)][ship.y + (j - 1)]) return false;
	
	// ship.getSize() - 1 -- количество циклов доп. проверок (равно кол-ву доп. палуб)
	for (int i = 0; i < ship.getSize() - 1; i++) // В случае корабля с 1 палубой, этот цикл будет пропущен
		for (int j = 0; j < 3; j++)
		{
			// Условно проверяем по 3 дополнительных поля на каждую палубу
			if (ship.isHorizontal()) if (isBound[ship.x + 2][ship.y + (j - 1)]) return false;
			else if (isBound[ship.x + (j - 1)][ship.y - 2]) return false;
		}
	return true;
}
*/

bool Battlefield::isPlaceAvailable(Ship& ship) const
{
	if (isBound[ship.x][ship.y]) return false;

	for (int i = 1; i < ship.getSize(); i++)
		{
			if (ship.isHorizontal()) if (isBound[ship.x + i][ship.y]) return false;
			else if (isBound[ship.x][ship.y - i]) return false;
		}
	return true;
}
void Battlefield::boundPlace(Ship& ship)
{
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) isBound[ship.x + (i - 1)][ship.y + (j - 1)] = true;

	for (int i = 1; i < ship.getSize(); i++) // В случае корабля с 1 палубой, этот цикл будет пропущен
		for (int j = 0; j < 3; j++)
		{
			if (ship.isHorizontal()) isBound[ship.x + (i + 1)][ship.y + (j - 1)] = true;
			else isBound[ship.x + (j - 1)][ship.y - (i + 1)] = true;
		}
}






void Player::menu()
{
	char choice = '0';
	while (choice != 'q')
	{
		cout << "\nНовая игра:                               '1'" << endl;
		cout << "Продолжить:                               '2'" << endl;
		cout << "Загрузить:                                '3'" << endl;
		cout << "Выход:                                    'Q'" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
			initializeFleet();
		case '2':

		case '3':
			
		default:
			continue;
		}
	}
}
void Player::initializeFleet()
{
	char choice = '0';
	//ShipID listOfShips[4] { {"Плот", 4},{"Шлюпка", 3},{"Лодка", 2},{"Катер", 1} };
	system("cls");

	//for (int i = 0; i < 10; i++)
	while(choice != 'q')
	{
		cout << "Разместите Ваш могучий флот:\n\n";
		for (int i = 0; i < 4; i++)	
			if (limit[i] > 0) cout << i + 1 << ": " << names[i] << " (" << limit[i] << " шт.)\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls");
			placeShip(names[0], 1, limit[0]);
			continue;
		case '2':
			system("cls");
			placeShip(names[1], 2, limit[1]);
			continue;
		case '3':
			system("cls");
			placeShip(names[2], 3, limit[2]);
			continue;
		case '4':
			system("cls");
			placeShip(names[3], 4, limit[3]);
			continue;
		default:
			//i--;
			continue;
		}
	}
}
Ship Player::placeShip(string name, int size, int& lim)
{
	int x, y;

	cout << "Размещаем " << name << "\n\n";
	setCoords(x, y);

	if (size > 1)
	{
		bool vh;
		char choice = '0';

		cout << "\n1: Горизонтально\n2: Вертикально" << endl;
		while (true)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
				vh = false;
				cout << "Nen11111111" << endl;
				break;
			case '2':
				vh = true;
				cout << "nen2" << endl;
				break;
			default:
				cout << "Ошибочка, ещё раз пробуйте" << endl;
				continue;
			}
			if (choice == '1' || choice == '2') break;
		}
		BigShip newShip(x, y, size, vh);

		if (isPlaceAvailable(newShip)) // Если всё ок и корабль тут разместить можно
		{
			system("cls");
			cout << "На поле (" << x << " : " << y;
			if (vh) cout << ") горизонтально ";
			else cout << ") вертикально ";
			cout << " размещён: " << name << "\n\n";

			lim--;
			fleet.push_back(newShip);
			boundPlace(newShip);

			__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
			return newShip;
		}
		system("cls");
		cout << "Невозможно разместить корабль здесь. Попробуйте снова\n\n";
		__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
		return placeShip(name, size, lim);
	}
	Ship newShip(x, y, size);
	if (isPlaceAvailable(newShip)) // Если всё ок и корабль тут разместить можно
	{
		system("cls");
		cout << "На поле (" << x << " : " << y << ") размещён: " << name << "\n\n";

		lim--;
		fleet.push_back(newShip);
		boundPlace(newShip);

		__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
		return newShip;
	}
	system("cls");
	cout << "Невозможно разместить корабль здесь. Попробуйте снова\n\n";
	__Test_checkIsBound(); // ----------------------------------------------
	return placeShip(name, size, lim);
}
void Player::setCoords(int& X, int& Y)
{
	string userInput;
	cout << "Задайте координаты: " << endl;

	getline(cin >> ws, userInput); // Пользователь вводит строку
	userInput.erase(std::remove(userInput.begin(), userInput.end(), ' '), userInput.end()); // Удаляем из неё пробелы

	Y = (char)userInput[1] - '0'; // Рассматриваем первый ...
	X = letterTointX((char)userInput[0]); // ... и второй символы, преобразуем их в int

	if (X > 0 && X < 11 && Y > 0 && Y < 11) { x = X; y = Y; } // Если результат в пределах диапозона, тогда всё ок
	else
	{
		system("cls");
		cout << "Ошибочка, попробуйте снова" << endl;
		setCoords(X, Y); // Рекурсивно исправляем ошибку, пока не будет введено корректное значение
	}
}
int Player::letterTointX(char letter)
{
	// 'A' = 65  ...  'J' = 74
	// 'a' = 97  ...  'j' = 106
	/*enum LetterID
	{
		A = 'A', B, C, D, E, F, G, H, I, J,
		a = 'a', b, c, d, e, f, g, h, i, j
	};*/

	return (int)letter - 96 > 0 ? (int)letter - 96 : (int)letter - 64;
}