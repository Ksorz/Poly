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
	string alive = isAlive ? "��" : "���";
	cout << "X: " << x << "\nY: " << y << "\n��� � �����: " << alive << " (��������� " << life << "/" << size << ")" << endl;
}
void BigShip::showInfo() const
{
	string alive = isAlive ? "��" : "���";
	cout << "X: " << x << "\nY: " << y << "\n��� � �����: " << alive << " (��������� " << life << "/" << size << ")" << endl;
	string sailing = isHorizontal() ? "����� ���������" : "� ��������";
	if (isAlive) cout << "�����: " << sailing << endl;
	else cout << "���� ���� ���� �� ������: " << sailing << endl;
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
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) isBound[ship.x + (i - 1)][ship.y + (j - 1)] = true;

	for (int i = 1; i < ship.getSize(); i++) // � ������ ������� � 1 �������, ���� ���� ����� ��������
		for (int j = 0; j < 3; j++)
		{
			if (ship.isHorizontal()) isBound[ship.x + (j - 1)][ship.y + (i + 1)] = true;
			else isBound[ship.x + (i + 1)][ship.y + (j - 1)] = true;
		}
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
void Player::initializeFleet()
{
	char choice = '0';
	//ShipID listOfShips[4] { {"����", 4},{"������", 3},{"�����", 2},{"�����", 1} };
	system("cls");

	//for (int i = 0; i < 10; i++)
	while(choice != 'q')
	{
		cout << "���������� ��� ������� ����:\n\n";
		for (int i = 0; i < 4; i++)	
			if (limit[i] > 0) cout << i + 1 << ": " << names[i] << " (" << limit[i] << " ��.)\n";
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
void Player::placeShip(string name, int size, int& lim)
{
	int x, y;

	cout << "��������� " << name << "\n\n";
	setCoords(x, y);

	if (!isPlaceAvailable(x, y))
	{
		system("cls");
		cout << "���������� ���������� ������� �����. ���������� �����\n\n";
		__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
		return placeShip(name, size, lim);
	}

	if (size > 1)
	{
		bool horiz;
		char choice = '0';

		cout << "\n1: �������������\n2: �����������" << endl;
		while (true)
		{
			cin >> choice;
			switch (choice)
			{
			case '1':
				horiz = true;
				break;
			case '2':
				horiz = false;
				break;
			default:
				cout << "��������, ��� ��� ��������" << endl;
				continue;
			}
			if (choice == '1' || choice == '2') break;
		}
		BigShip* newShip = new BigShip(x, y, size, horiz);

		if (isPlaceAvailable(x, y, newShip->getSize(), newShip->isHorizontal())) // ���� �� �� � ������� ��� ���������� �����
		{
			system("cls");
			cout << "�� ���� (" << x << " : " << y;
			if (horiz) cout << ") ������������� ";
			else cout << ") ����������� ";
			cout << " ��������: " << name << "\n\n";

			lim--;
			fleet.push_back(newShip);
			boundPlace(*newShip);

			__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
			return;
		}
		system("cls");
		cout << "���������� ���������� ������� �����. ���������� �����\n\n";
		__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
		return placeShip(name, size, lim);
	}
	Ship* newShip = new Ship(x, y, size);
	if (isPlaceAvailable(x, y, newShip->getSize(), newShip->isHorizontal())) // ���� �� �� � ������� ��� ���������� �����
	{
		system("cls");
		cout << "�� ���� (" << x << " : " << y << ") ��������: " << name << "\n\n";

		lim--;
		fleet.push_back(newShip);
		boundPlace(*newShip);

		__Test_checkIsBound(); // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
		return;
	}
	system("cls");
	cout << "���������� ���������� ������� �����. ���������� �����\n\n";
	__Test_checkIsBound(); // ----------------------------------------------
	return placeShip(name, size, lim);
}
void Player::setCoords(int& X, int& Y)
{
	string userInput;
	cout << "������� ����������: " << endl;

	getline(cin >> ws, userInput); // ������������ ������ ������
	userInput.erase(std::remove(userInput.begin(), userInput.end(), ' '), userInput.end()); // ������� �� �� �������

	X = (char)userInput[1] - '0'; // ������������� ������ ...
	Y = letterTointY((char)userInput[0]); // ... � ������ �������, ����������� �� � int

	if (X > 0 && X < 11 && Y > 0 && Y < 11) { x = X; y = Y; } // ���� ��������� � �������� ���������, ����� �� ��
	else
	{
		system("cls");
		cout << "��������, ���������� �����" << endl;
		setCoords(X, Y); // ���������� ���������� ������, ���� �� ����� ������� ���������� ��������
	}
}
int Player::letterTointY(char letter)
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