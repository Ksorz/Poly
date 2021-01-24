#pragma once
using namespace std;
using namespace sf;

static float y = 750; // �������
static float x = y * 1.8f;
static float step = y / 15.0f;
static float startOne = step * 3;
static float startTwo = step * 15;


//static RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");

/*

��� �������:

1) ����� �� ����� ��� ����� ��� � ������������ inline � �������?
2) ����� �� ������� ���, ����� Player � Ship (�� ��������� ������������ �������) ����������� ���� � ��� �� ��������� ������ Battlefield
3) �������� ����������� ������, ������� ���� const, �� ������� �������� � ������. ������? 
4) ����� �� ���������� ������ ������ � ����� �� ���������� � ������� "ClassName::..."?

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
void setByDefault();
void menu();

void fastSaveGame();
void fastLoadGame();
void theGame();

void bfAim(RenderWindow& battleship, float teamStartPosition, int stepL, int stepN, Texture texture);

void showGameInfo();

void setColor(ConsoleColor text, ConsoleColor background);
void drawNet(RenderWindow& battleship, float first, float second, int step);
int rnd(int min = 1, int max = 10); // ���������� ��������� ����� (��-��������� �� 1 �� 10)


//
//struct ShipID
//{
//	string name;
//	int number;
//	const int size = 5 - number;
//};



struct Coords
{
	int L = 0;
	int N = 0; // Letter, Number

	friend ostream& operator<< (ostream& os, const Coords& c)
	{
		os << c.L << " " << c.N << "\n";
		return os;
	}
	friend istream& operator>> (istream& is, Coords& c)
	{
		is >> c.L >> c.N;
		return is;
	}
};

class Ship
{
	string name = "�����"; // const string name = "�����";
	bool horizontal;
	
	vector<Coords> decksPos;
	vector<Coords> damaged;

public:

	Ship() {}
	Ship(int LScale, int NScale, string name, int size = 1, bool horiz = true);
	
	friend ostream& operator<< (ostream& os, const Ship& s);
	friend istream& operator>> (istream& is, Ship& s);

	inline vector<Coords>& getDecks() { return decksPos; }
	inline vector<Coords>& getDamagedDecks() { return damaged; }
	inline int getSize() const { return decksPos.size(); }
	inline int getDamagedSize() const { return damaged.size(); }
	inline bool isHorizontal() const { return horizontal; }
	inline string getName() const { return name; }

	void showInfo() const;
	void drawShip(RenderWindow& battleship, float teamStartPosition) const;
};




class Battlefield
{
	

protected:
		
	int map[12][12]; // ����������� [0] � [11] ���� ��� ����� ��-��������� (9), � ���� �� ������� ������� ����� ������ 1-10
	int limit[4]{ 4, 3, 2, 1 }; // � ������� ������ ���� ����� ��������
	string const names[4]{ "�����", "������", "����", "������" }; // ��� ������� �������...

	inline bool isOutOfLimit(int shipSize) { return limit[shipSize - 1] == 0 ? true : false; } // �������� �� ��� ������� ������-�� �������?
	bool isPlaceAvailable(int letterVal, int numberVal, int size = 1, bool horiz = false); // �������� �� ����� ��� ���������� ������� � ������-�� �����������?
	void boundPlace(Ship& ship); // ��������� ������� �� �����

public:

	Battlefield();

	friend ostream& operator<< (ostream& os, const Battlefield& bf);
	friend istream& operator>> (istream& is, Battlefield& bf);

	inline auto& getMap() { return map; }
	void showSimpleBoundMap() const; // ���������� ���������� ����� � ������������ ���������
	int takeShot(Coords LN); // ������� �� ������� �� ����������� ����������� �� �����
	void drawBattlefield(RenderWindow& battleship, float teamStartPosition) const;
	void drawSquare(RenderWindow& battleship, float teamStartPosition, int L, int N, Color color) const;
};

class Player : public Battlefield
{
	bool isHuman; // �������� �� ����� ���������?
	vector<Ship> fleet;
	vector<Coords> aiEvilMemory;
	
	

	void placeShip(string name, int size, int& lim); // ���������� �������
	int letterTointY(char letter); // �������������� ����� � ��������� ����������
	
	void setCoords(int& X, int& Y); // �������������� � �������: ����� ����������
	void removeShipDeck(Ship& ship, vector<Coords>::iterator& iterator, const Coords LN);
	void removeShipIfDead(vector<Ship>::iterator& iterator);
	void aiBoundAroundWhenHit(int map[12][12], Coords shotHere);
	void aiBoundAroundWhenKill(int map[12][12], Coords shotHere);

	inline int getFleetSize() const { return fleet.size(); }
	inline int aiMemorySize() const { return aiEvilMemory.size(); }

	Coords aiEvilPlan(int map[12][12]);

public:

	Player() {}
	Player(bool hum) : isHuman(hum) {}

	inline vector<Ship>& getMyFleet() { return fleet; }
	inline vector<Coords>& getAiEvilMemory() { return aiEvilMemory; }



	friend ostream& operator<< (ostream& os, const Player& p);
	friend istream& operator>> (istream& is, Player& p);

	


	void initializeFleet(); // ����� ��������
	void InitializeRandomFleet(); // 4 COMP
	
	void updateShipData(const Coords LN);

	void drawFleet(RenderWindow& battleship, float teamStartPosition) { for (const auto& ship : fleet) ship.drawShip(battleship, teamStartPosition); }

	void showInfo(bool hideLocations = false);

	
	Coords aiAim(int map[12][12]);

	
};
// =====================================================================================================





