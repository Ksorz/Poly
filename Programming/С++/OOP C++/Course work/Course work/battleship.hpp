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

	
	virtual void showInfo() const;
	inline int getSize() { return size; }
	inline virtual bool isHorizontal() const { return true; }

	void drawShip(RenderWindow& battleship, float teamStartPosition) const;

};
// =====================================================================================================
class BigShip : public Ship
{

	bool* deckIsOk = new bool[size];
	
protected:

	bool isHorizontal;
	
public:
	
	BigShip(int xScale, int yScale, int size, bool horiz) : isHorizontal(horiz), Ship(xScale, yScale, size) { for (int i = 0; i < size; i++) deckIsOk[i] = true; }
	~BigShip() { delete deckIsOk; }

	virtual void showInfo() const;
	inline virtual bool isHorizontal() const { return isHorizontal; }

	void drawShip(RenderWindow& battleship, float teamStartPosition) const;

};
// =====================================================================================================



// =====================================================================================================
class Battlefield
{
	// Карта занятых позиций (в данный момент будет поддерживаться только 10х10 карта)
	bool isBound[12][12]; // заграничные [0] и [11] поля все false, к тому же индексы игровых полей удачно 1-10
	int limit[4] { 4, 3, 2, 1 };
	vector<Ship> fleet;

	inline bool isOutOfLimit(int shipSize) { return limit[shipSize - 1] == 0 ? true : false; }
	bool isPlaceAvailable(Ship& const ship) const;
	void boundPlace(Ship& const ship, bool** boundOnMap);

public:

	Battlefield() { for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) isBound[i][j] = false; }

	void addNewShip();

};
// =====================================================================================================
class Player : public Battlefield
{

};
// =====================================================================================================

