#pragma once
using namespace std;
using namespace sf;

static float y = 750; // Масштаб
static float x = y * 1.8f;
static float step = y / 15.0f;
static float startOne = step * 3;
static float startTwo = step * 15;
//static RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");

void drawNet(RenderWindow& battleship, float first, float second, int step);



struct ShipID
{
	string name;
	int number;
	const int size = 5 - number;
};



struct Coords
{
	int x;
	int y;
};



// =====================================================================================================
class Ship : public Coords
{

protected:

	const int size;
	int life = size;
	bool isAlive = true;

public:

	Ship(int xScale, int yScale, int size = 1) : size(size), Coords{ xScale, yScale } {}


	inline int getSize() { return size; }
	inline virtual bool isHorizontal() const { return true; }


	virtual void showInfo() const;
	virtual void drawShip(RenderWindow& battleship, float teamStartPosition) const;
};
// =====================================================================================================
class BigShip : public Ship
{

	bool* deckIsOk = new bool[size];
	
protected:

	bool horizontal;
	
public:
	
	BigShip(int xScale, int yScale, int size, bool horiz) : horizontal(horiz), Ship(xScale, yScale, size)
	{ 
		for (int i = 0; i < size; i++) deckIsOk[i] = true;
	}
	BigShip(const BigShip& other) : horizontal(other.isHorizontal()), Ship(other.x, other.y, other.size) // Конструктор копирования
	{
		for (int i = 0; i < other.size; i++) deckIsOk[i] = other.deckIsOk[i];
	}
	~BigShip() { delete deckIsOk; }


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

	bool isBound[12][12];
	int limit[4]{ 4, 3, 2, 1 };
	string const names[4]{ "Тазик", "Плот", "Шлюпка", "Лодка" };

	inline bool isOutOfLimit(int shipSize) { return limit[shipSize - 1] == 0 ? true : false; }
	bool isPlaceAvailable(int letterVal, int numberVal, int size, bool horiz);
	void boundPlace(Ship& ship);

public:

	Battlefield() { for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) isBound[i][j] = false; }

};
// =====================================================================================================
class Player : public Battlefield
{
	vector<Ship*> fleet;
	void placeShip(string name, int size, int& lim);
	int letterTointY(char letter);
	void setCoords(int& X, int& Y);

public:

	void menu();
	void initializeFleet(); // Выбор кораблей

	void __Test_checkIsBound()
	{
		for (int i = 1; i < 11; i++)
		{
			cout << endl;
			for (int j = 1; j < 11; j++) cout << isBound[i][j] << "  ";
		}
		cout << endl;
	}

	void drawFleet(RenderWindow& battleship, float teamStartPosition)
	{
		for (const auto& ship : fleet) ship->drawShip(battleship, teamStartPosition); 
		//fleet[0].drawShip(battleship, teamStartPosition);
	}

	
};
// =====================================================================================================

