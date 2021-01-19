#pragma once
using namespace std;
using namespace sf;

static float y = 450; // Масштаб
static float x = y * 1.8f;
static float step = y / 15.0f;
static float startOne = step * 3;
static float startTwo = step * 15;
//static RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");

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
	int L, N;
};



// =====================================================================================================
class Ship
{

protected:

	bool horizontal;
	bool isAlive = true;

public:
	vector<Coords> decksLN;

	Ship(int LScale, int NScale, int size = 1, bool horiz = true) : horizontal(horiz)
	{
		for (int i = 0; i < size; i++)
		{
			if (horiz) decksLN.push_back(Coords{ LScale, NScale + i });
			else decksLN.push_back(Coords{ LScale + i, NScale });
		}
	}
	

	inline int getSize() { return decksLN.size(); }

	inline virtual bool isHorizontal() const { return horizontal; }
	virtual void showInfo() const;
	virtual void drawShip(RenderWindow& battleship, float teamStartPosition) const;
};
// =====================================================================================================
class Battlefield
{
	 // заграничные [0] и [11] поля все false, к тому же индексы игровых полей удачно 1-10

protected:

	int isBound[12][12];
	int limit[4]{ 4, 3, 2, 1 };
	string const names[4]{ "Тазик", "Плот", "Шлюпка", "Лодка" };

	inline bool isOutOfLimit(int shipSize) { return limit[shipSize - 1] == 0 ? true : false; }
	bool isPlaceAvailable(int letterVal, int numberVal, int size, bool horiz);
	void boundPlace(Ship& ship);
	

public:
	void showSimpleBoundMap() const;
	Battlefield() { for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) isBound[i][j] = 0; }


	int takeShot(int letterVal, int numberVal);

};
// =====================================================================================================
class Player : public Battlefield
{
	const bool isHuman;

	
	void placeShip(string name, int size, int& lim);
	int letterTointY(char letter);
	void setCoords(int& X, int& Y);
	int getRandTen(int min = 1, int max = 10) const; // 4 COMP


	

public:

	Player(bool hum) : isHuman(hum) {}
	~Player() {} // СДЕЛАТЬ ДЕСТРУКТОР!

	vector<Ship> fleet;
	void menu();
	void initializeFleet(); // Выбор кораблей

	void InitializeRandomFleet(); // 4 COMP

	
	void drawFleet(RenderWindow& battleship, float teamStartPosition) { for (const auto& ship : fleet) ship.drawShip(battleship, teamStartPosition); }


	

	
};
// =====================================================================================================

