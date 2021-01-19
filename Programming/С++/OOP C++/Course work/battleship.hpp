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
class Ship : public Coords
{

protected:

	

	int size;
	int life = size;
	bool isAlive = true;

public:

	Ship(int LScale, int NScale, int size = 1) : size(size) { decksLN.push_back(Coords{ LScale, NScale }); }
	vector<Coords> decksLN;

	inline int getSize() { return size; }
	inline virtual bool isHorizontal() const { return true; }


	virtual void showInfo() const;
	virtual void drawShip(RenderWindow& battleship, float teamStartPosition) const;
};
// =====================================================================================================
class BigShip : public Ship
{

	//bool* deckIsOk = new bool[size];
	
protected:

	bool horizontal;
	
public:
	
	BigShip(int LScale, int NScale, int size, bool horiz) : horizontal(horiz), Ship(LScale, NScale, size)
	{ 
		//for (int i = 0; i < size; i++) deckIsOk[i] = true; // Удалить

		if (horiz) for (int i = 1; i < size; i++) decksLN.push_back(Coords{ LScale + i, NScale });
		else for (int i = 1; i < size; i++) decksLN.push_back(Coords{ LScale, NScale + i });
	}
	/*BigShip(const BigShip& other) : horizontal(other.isHorizontal()), Ship(other.x, other.y, other.size) // Конструктор копирования
	{
		for (int i = 0; i < other.size; i++) deckIsOk[i] = other.deckIsOk[i];
	}
	//~BigShip() { delete deckIsOk; }*/


	inline virtual bool isHorizontal() const { return horizontal; }


	virtual void showInfo() const;
	virtual void drawShip(RenderWindow& battleship, float teamStartPosition) const;
};
// =====================================================================================================



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
	void showSimpleBoundMap() const;

public:

	Battlefield() { for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) isBound[i][j] = 0; }


	int takeShot(int letterVal, int numberVal);

};
// =====================================================================================================
class Player : public Battlefield
{
	const bool isHuman;

	vector<Ship*> fleet;
	void placeShip(string name, int size, int& lim);
	int letterTointY(char letter);
	void setCoords(int& X, int& Y);
	int getRandTen(int min = 1, int max = 10) const; // 4 COMP


	

public:

	Player(bool hum) : isHuman(hum) {}

	void menu();
	void initializeFleet(); // Выбор кораблей

	void InitializeRandomFleet(); // 4 COMP

	
	void updateShipData(Coords LN);
	void removeShipDeck(Ship& ship, const Coords LN);
	void removeShipIfDead();
	
	void drawFleet(RenderWindow& battleship, float teamStartPosition) { for (const auto& ship : fleet) ship->drawShip(battleship, teamStartPosition ); }


	

	
};
// =====================================================================================================

