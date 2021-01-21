#pragma once
using namespace std;
using namespace sf;

static float y = 450; // Масштаб
static float x = y * 1.8f;
static float step = y / 15.0f;
static float startOne = step * 3;
static float startTwo = step * 15;
//static RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");

/*

Мои вопросы:

1) Имеет ли смысл так часто как я использовать inline в классах?
2) Можно ли сделать так, чтобы Player и Ship (не связанные родственными связями) наследовали один и тот же экземпляр класса Battlefield
3) Удаление экземпляров класса, имеющих поля const, из вектора приводит к ошибке. Почему? 

*/







enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void setColor(ConsoleColor text, ConsoleColor background);
void drawNet(RenderWindow& battleship, float first, float second, int step);



struct ShipID
{
	string name;
	int number;
	const int size = 5 - number;
};



struct Coords
{
	int L, N; // Letter, Number
};



// =====================================================================================================
class Ship
{
	string name = "Ведро"; // const string name = "Ведро";
	bool horizontal;
	
	vector<Coords> decksPos;
	vector<Coords> damaged;

public:

	Ship(int LScale, int NScale, int size = 1, bool horiz = true) : horizontal(horiz)
	{
		for (int i = 0; i < size; i++)
		{
			if (horiz) decksPos.push_back(Coords{ LScale, NScale + i });
			else decksPos.push_back(Coords{ LScale + i, NScale });
		}
	}
	
	inline vector<Coords>& getDecks() { return decksPos; }
	inline vector<Coords>& getDamagedDecks() { return damaged; }
	inline int getSize() const { return decksPos.size(); }
	inline bool isHorizontal() const { return horizontal; }
	inline string getName() const { return name; }

	void showInfo() const;
	void drawShip(RenderWindow& battleship, float teamStartPosition) const;
};




class Battlefield
{
	int map[12][12]; // заграничные [0] и [11] поля все false (0), к тому же индексы игровых полей удачно 1-10

protected:
		
	int limit[4]{ 4, 3, 2, 1 }; // У каждого игрока свой лимит кораблей
	string const names[4]{ "Тазик", "Бревно", "Плот", "Шлюпка" }; // Как корабль назовёшь...

	inline bool isOutOfLimit(int shipSize) { return limit[shipSize - 1] == 0 ? true : false; } // Остались ли ещё корабли такого-то размера?
	bool isPlaceAvailable(int letterVal, int numberVal, int size = 1, bool horiz = false); // Свободно ли место для размещения корабля с такими-то параметрами?
	void boundPlace(Ship& ship); // Размещаем корабль на карте

public:

	Battlefield() { for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) map[i][j] = 0; }

	inline auto getMap() { return map; } // Да ладно... это работает?
	void showSimpleBoundMap() const; // Отобразить консольную карту с размещёнными кораблями
	int takeShot(Coords LN); // Реакция на выстрел по определённым координатам на карте
	void drawBattlefield(RenderWindow& battleship, float teamStartPosition) const;
	void drawSquare(RenderWindow& battleship, float teamStartPosition, int L, int N, Color color) const;

};
// =====================================================================================================
class Player : public Battlefield
{
	const bool isHuman; // Является ли игрок человеком?
	vector<Ship> fleet;
	
	void placeShip(string name, int size, int& lim); // Разместить корабль
	int letterTointY(char letter); // Преобразование буквы в численную координату
	int getRandTen(int min = 1, int max = 10) const; // Возвращает случайное число (по-умолчанию от 1 до 10)

	void setCoords(int& X, int& Y); // Взаимодействие с игроком: задаём координаты
	void removeShipDeck(Ship& ship, vector<Coords>::iterator& iterator, const Coords LN);
	void removeShipIfDead(vector<Ship>::iterator& iterator);

public:

	Player(bool hum) : isHuman(hum) {}

	inline vector<Ship>& getMyFleet() { return fleet; }

	void menu();
	void initializeFleet(); // Выбор кораблей
	void InitializeRandomFleet(); // 4 COMP

	void updateShipData(const Coords LN);
	
	void removeShipIfDead();

	void drawFleet(RenderWindow& battleship, float teamStartPosition) { for (const auto& ship : fleet) ship.drawShip(battleship, teamStartPosition); }

	void showInfo();
	

	
};
// =====================================================================================================

