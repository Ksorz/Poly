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
class Small : public Coords
{
	

protected:

	int dur;
	int life = dur;
	bool isAlive = true;

public:

	Small(int xScale, int yScale, int size = 1) : dur(size), Coords{ xScale, yScale } {}

	
	virtual void showInfo() const;
	void drawShip(RenderWindow& battleship, float teamStartPosition) const;

};
// =====================================================================================================
// =====================================================================================================
class Big : public Small
{

protected:

	bool horiz;
	
public:

	Big(int xScale, int yScale, int size, bool horizontal) : horiz(horizontal), Small(xScale, yScale, size) {}


	virtual void showInfo() const;
	void drawShip(RenderWindow& battleship, float teamStartPosition) const;

};
// =====================================================================================================


