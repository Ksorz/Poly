#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

#include <ctime> // ��� ������� time()
#include <cstdlib> // ��� ������� rand() � srand()

#include "battleship.hpp"

using namespace std;
using namespace sf;

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








void Ship::showInfo() const
{
	string alive = isAlive ? "��" : "���";
	cout << "X: " << x << "\nY: " << y << "\n��� � �����: " << alive << " (��������� " << life << "/" << size << ")" << endl;
}
void Ship::showInfo() const
{
	bool isAlive = decksLN.size();
	string alive = isAlive ? "��" : "���";
	string sailing = isHorizontal() ? "����� ���������" : "� ��������";

	cout << "L: " << x << "\nN: " << y << "\n��� � �����: " << alive << " (��������� " << decksLN.size() << ")" << endl;
	if (isAlive) cout << "�����: " << sailing << endl;
	else cout << "���� ����, ���� �� ������: " << sailing << endl;
}
void Ship::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	RectangleShape rectangle(Vector2f(step, step));
	rectangle.move(teamStartPosition + (step * (y - 1)), startOne + (step * (x - 1))); 
	rectangle.setFillColor(isAlive ? Color::Green : Color::Red);
	battleship.draw(rectangle); 
}
void BigShip::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	for (int i = 0; i < size; i++)
	{
		RectangleShape rectangle(Vector2f(step, step));
		// ����� ����� �������� ������������ ��������� ������� (teamStartPosition) 
		// � ������� ���������� ������� ������� ���������� ��� ����������� (isHorizontal)
		if (isHorizontal()) rectangle.move(teamStartPosition + (step * (y - 1)) + (step * i), startOne + (step * (x - 1))); // ����������
		else rectangle.move(teamStartPosition + (step * (y - 1)), startOne + (step * (x - 1)) + (step * i)); // ����������
		rectangle.setFillColor(deckIsOk[i] ? Color::Green : Color::Red); // ���� ������������ ����, ��������� �� ������
		battleship.draw(rectangle);
	}
}



/*
bool Battlefield::isPlaceAvailable(Ship& ship) const
{
	for (int i = 0; i < 3; i++) // �������� ����� ������ ��������� ��������� (������� ���������� ship)
		for (int j = 0; j < 3; j++) if (isBound[ship.x + (i - 1)][ship.y + (j - 1)]) return false;
	
	// ship.getSize() - 1 -- ���������� ������ ���. �������� (����� ���-�� ���. �����)
	for (int i = 0; i < ship.getSize() - 1; i++) // � ������ ������� � 1 �������, ���� ���� ����� ��������
		for (int j = 0; j < 3; j++)
		{
			// ������� ��������� �� 3 �������������� ���� �� ������ ������
			if (ship.isHorizontal()) if (isBound[ship.x + 2][ship.y + (j - 1)]) return false;
			else if (isBound[ship.x + (j - 1)][ship.y - 2]) return false;
		}
	return true;
}
bool Battlefield::isPlaceAvailable(Ship& ship) const
{
	if (isBound[ship.y][ship.x]) return false;

	for (int i = 1; i < ship.getSize(); i++)
		{
			if (ship.isHorizontal()) if (isBound[ship.y][ship.x + i]) return false;
			else if (isBound[ship.y + i][ship.x]) return false;
		}
	return true;
}
*/

bool Battlefield::isPlaceAvailable(int letterVal, int numberVal, int size = 1, bool horiz = false)
{
	if (isBound[letterVal][numberVal] || letterVal < 1 || letterVal > 10 || numberVal < 1 || numberVal > 10) return false;
	if (size > 1)
	{
		if (horiz) return isPlaceAvailable(letterVal, numberVal + 1, size - 1, horiz);
		else return isPlaceAvailable(letterVal + 1, numberVal, size - 1, horiz);
	}
	return true;
}
void Battlefield::boundPlace(Ship& ship)
{
	for (int i = -1; i < ship.getSize() + 1; i++)
		for (int j = -1; j < 2; j++)
			// ����� ����������� ����� ����� � ������� �������� 1, � ����� ������� �������� ������� ������� + 1
			isBound[ship.decksLN[i].L][ship.decksLN[i].N + j] = i >= 0 && i <= ship.getSize() && j == 0 ? ship.getSize() + 1 : true;
}
int Battlefield::takeShot(int letterVal, int numberVal)
{
	int result = 0;
	if (isBound[numberVal][letterVal] > 1)
	{
		result = 1;
		isBound[numberVal][letterVal]--;

		if (isBound[numberVal][letterVal] == 1) return 2; // ���������
		else if (isBound[numberVal][letterVal] == 2);

	}






	//isBound[numberVal][letterVal] = 9;
	return result;
}






void Player::menu()
{
	char choice = '0';
	while (choice != 'q')
	{
		cout << "\n����� ����:                               '1'" << endl;
		cout << "����������:                               '2'" << endl;
		cout << "���������:                                '3'" << endl;
		cout << "�����:                                    'Q'" << endl;
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
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void Player::initializeFleet()
{
	char choice = '0';
	//ShipID listOfShips[4] { {"����", 4},{"������", 3},{"�����", 2},{"�����", 1} };
	system("cls"); showSimpleBoundMap();

	//for (int i = 0; i < 10; i++)
	while(choice != 'q')
	{
		cout << "���������� ��� ������� ����:\n\n";
		for (int i = 0; i < 4; i++)	
			if (limit[i]) cout << i + 1 << ": " << names[i] << " (" << limit[i] << " ��.)\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls"); showSimpleBoundMap();
			if (!limit[0]) continue;
			placeShip(names[0], 1, limit[0]);
			continue;
		case '2':
			system("cls"); showSimpleBoundMap();
			if (!limit[1]) continue;
			placeShip(names[1], 2, limit[1]);
			continue;
		case '3':
			system("cls"); showSimpleBoundMap();
			if (!limit[2]) continue;
			placeShip(names[2], 3, limit[2]);
			continue;
		case '4':
			system("cls"); showSimpleBoundMap();
			if (!limit[3]) continue;
			placeShip(names[3], 4, limit[3]);
			continue;
		default:
			//i--;
			continue;
		}
	}
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void Player::placeShip(string name, int size, int& lim)
{
	int x, y;

	if (isHuman)
	{
		cout << "��������� " << name << "\n\n";
		setCoords(x, y);
	}
	else { x = getRandTen(); y = getRandTen(); } // ���� �������� ������ ����������
	
	if (!isPlaceAvailable(x, y))
	{
		if (isHuman)
		{
			system("cls"); showSimpleBoundMap();
			cout << "���������� ���������� ������� �����. ���������� �����\n\n";
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
			cout << "\n1: �����������\n2: �������������" << endl;
			getline(cin >> ws, toBool);
			horiz = (int)(char)toBool[0] - '0' - 1;
		}
		else horiz = getRandTen(0, 1); // ���� �������� ������� �����������

		if (isPlaceAvailable(x, y, size, horiz)) // ���� �� �� � ������� ��� ���������� �����
		{
			
			lim--;
			fleet.push_back(Ship{ x, y, size, horiz });
			boundPlace(fleet[fleet.size() - 1]);

			if (isHuman)
			{
				system("cls"); showSimpleBoundMap(); 
				cout << "�� ����� (" << (char)(64 + y) << x;
				for (int i = 1; i < fleet[fleet.size() - 1].getSize(); i++)
				{
					cout << ", ";
					if (horiz) cout << (char)(64 + y + i) << x;
					else cout << (char)(64 + y) << x + i;
				}
				cout << ") ��������: " << name << "\n\n";
			}
			return;
		}
		if (isHuman)
		{
			system("cls"); showSimpleBoundMap();
			cout << "���������� ���������� ������� �����. ���������� �����\n\n";
			cout << endl;
		}
		return placeShip(name, size, lim);
	}
	if (isPlaceAvailable(x, y, size, true)) // ���� �� �� � ������� ��� ���������� �����
	{
		lim--;
		fleet.push_back(Ship{ x, y, size });
		boundPlace(fleet[fleet.size() - 1]);

		if (isHuman)
		{
			system("cls"); showSimpleBoundMap();
			cout << "�� ���� (" << (char)(64 + y) << x << ") ��������: " << name << "\n\n";
		}
		return;
	}
	if (isHuman)
	{
		system("cls"); showSimpleBoundMap();
		cout << "���������� ���������� ������� �����. ���������� �����\n\n";
		cout << endl;
	}
	return placeShip(name, size, lim);
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void Player::setCoords(int& X, int& Y)
{
	string userInput;
	cout << "������� ����������: " << endl;

	getline(cin >> ws, userInput); // ������������ ������ ������
	userInput.erase(std::remove(userInput.begin(), userInput.end(), ' '), userInput.end()); // ������� �� �� �������

	if ((char)userInput[1] - '0' == 1 && (char)userInput[2] - '0' == 0) X = 10;
	else X = (char)userInput[1] - '0'; // ������������� ������ ...
	Y = letterTointY((char)userInput[0]); // ... � ������ �������, ����������� �� � int

	if (X > 0 && X < 11 && Y > 0 && Y < 11) { x = X; y = Y; } // ���� ��������� � �������� ���������, ����� �� ��
	else
	{
		system("cls"); showSimpleBoundMap();
		cout << "��������, ���������� �����" << endl;
		setCoords(X, Y); // ���������� ���������� ������, ���� �� ����� ������� ���������� ��������
	}
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int Player::letterTointY(char letter)
{
	return (int)letter - 96 > 0 ? (int)letter - 96 : (int)letter - 64;
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
			if (isBound[i][j])
			{
				if(isBound[i][j] > 1) setColor(Blue, LightCyan);
				else setColor(White, LightCyan);
				cout << isBound[i][j] - 1 << "  ";
				setColor(Black, LightCyan);
			}
			else cout << isBound[i][j] << "  ";
		}
		if (i != 10) cout << endl;
	}
	cout << "\n" << setfill(' ') << setw(36) << "\n";
	setColor(White, Black);
	cout << "\n";
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
			srand(static_cast<unsigned int>(time(0)));
			placeShip(names[i], size, limit[i]);
		}
	}
}

int Player::getRandTen(int min, int max) const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}



