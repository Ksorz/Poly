#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

#include <ctime> // ��� ������� time()
#include <cstdlib> // ��� ������� rand() � srand()

#include "battleship.hpp"

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
	bool isAlive = decksPos.size();
	string alive = isAlive ? "��" : "���";
	string sailing = isHorizontal() ? "����� ���������" : "� ��������";

	cout << name << " (";
	for (int i = 0; i < getSize(); i++)
	{
		cout << (char)(64 + decksPos[i].N) << decksPos[i].L;
		if(i + 1 != getSize()) cout << ", ";
	}
	cout << ") ��� � �����: " << alive << " (��������� " << decksPos.size() << ")" << endl;

	if (isAlive) cout << "�����: " << sailing << endl;
	else cout << "���� ����, ���� �� ������: " << sailing << endl;
}
void Ship::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	for (int i = 0; i < decksPos.size(); i++)
	{
		RectangleShape rectangle(Vector2f(step, step));
		rectangle.move(teamStartPosition + (step * (decksPos[i].N - 1)), startOne + (step * (decksPos[i].L - 1))); // ����������
		rectangle.setFillColor(Color::Green);
		battleship.draw(rectangle);
	}
}




bool Battlefield::isPlaceAvailable(int letterVal, int numberVal, int size, bool horiz)
{
	if (map[letterVal][numberVal] || letterVal < 1 || letterVal > 10 || numberVal < 1 || numberVal > 10) return false;
	if (size > 1)
	{
		if (horiz) return isPlaceAvailable(letterVal, numberVal + 1, size - 1, horiz);
		else return isPlaceAvailable(letterVal + 1, numberVal, size - 1, horiz);
	}
	return true;
}
void Battlefield::boundPlace(Ship& ship)
{
	int L, N;
	for (int i = 0; i < ship.getSize(); i++)
	{
		L = ship.getDecks()[i].L;
		N = ship.getDecks()[i].N;

		map[L][N] = ship.getSize() + 1;
		for (int j = -1; j < 2; j++)
		{
			if (map[L + 1][N + j] < 1) map[L + 1][N + j] = 1;
			if (map[L + 0][N + j] < 1) map[L + 0][N + j] = 1;
			if (map[L - 1][N + j] < 1) map[L - 1][N + j] = 1;
		}			
	}
}
int Battlefield::takeShot(Coords LN) // ����������: 0 - (�� �����) 1 - (������) 2 - (���������) 3 - (��������� ������� � ��� ������������ ������)
{
	int result = 0;
	if (map[LN.N][LN.L] > 1 && map[LN.N][LN.L] < 6) // �������� �������� ��������
	{
		result = 1; // �������
		if (map[LN.N][LN.L] == 2) result = 2; // ����������
	}
	else if (map[LN.N][LN.L] < 2) map[LN.N][LN.L] = 9; // ������
	else if (map[LN.N][LN.L] > 5) result = 3; // ��� �������� ���� ����� ��� �������� ��?
	return result;
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
			if (map[i][j])
			{
				if (map[i][j] > 1) setColor(Blue, LightCyan);
				else setColor(White, LightCyan);
				cout << map[i][j] - 1 << "  ";
				setColor(Black, LightCyan);
			}
			else cout << map[i][j] << "  ";
		}
		if (i != 10) cout << endl;
	}
	cout << "\n" << setfill(' ') << setw(36) << "\n";
	setColor(White, Black);
	cout << "\n";
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
int Player::letterTointY(char letter)
{
	return (int)letter - 96 > 0 ? (int)letter - 96 : (int)letter - 64;
}
int Player::getRandTen(int min, int max) const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void Player::updateShipData(const Coords LN) // ������� ����� (� ����� �����) �������� ������ ���� ���� ��������� � �������
{
	for (auto itShip = getMyFleet().begin(); itShip != getMyFleet().end(); ++itShip) // ������������ �� ������� ��������
	{
		for (auto itDeck = itShip->getDecks().begin(); itDeck != itShip->getDecks().end(); ++itDeck) // � ������ ������� �� �������
		{
			if (itDeck->L == LN.N && itDeck->N == LN.L) // ���� ����� ������ � ������� ���� ���������...
			{
				removeShipDeck(*itShip, itDeck, LN); // ... ������� � �� �������
				removeShipIfDead(itShip); // ���� ��� ���� ��������� ������ �� �������, ������� �������
				return; // ������� ��������� ���� ����, ������������
			}
		}
	}
}
void Player::removeShipDeck(Ship& ship, vector<Coords>::iterator& iterator, const Coords LN)
{// ��� ����� ������ ��������...
	getMap()[iterator->L][iterator->N] = 7; // ��������� � ����� ����� �������� �������� ������ �������
	ship.getDamagedDecks().push_back(*iterator);
	ship.getDecks().erase(iterator); // ������� ������
	for (auto& deck : ship.getDecks()) getMap()[deck.L][deck.N]--; // �������� �� ����� �������� ����� ������� ������� (�.�. �� ���� ������ �� 1)
}
void Player::removeShipIfDead(vector<Ship>::iterator& iterator)
{
	if (iterator->getSize() == 0)
	{
		for (auto& deadDeck : iterator->getDamagedDecks())
		{
			getMap()[deadDeck.L][deadDeck.N] = 8;
		}
		getMyFleet().erase(iterator);
	}

}





void Player::showInfo()
{
	cout << "��������: " << getMyFleet().size() << "\n\n";

	for (auto& ship : getMyFleet())
	{
		cout << ship.getName() << ". ����� ����: -" << ship.getSize() << "- ";
		cout << " (";
		for (int i = 0; i < ship.getSize(); i++)
		{
			cout << (char)(64 + ship.getDecks()[i].N) << ship.getDecks()[i].L;
			if (i + 1 != ship.getSize()) cout << ", ";
		}
		cout << ")\n";
	}
}




void Battlefield::drawBattlefield(RenderWindow& battleship, float teamStartPosition) const
{
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 11; j++)
		{
			if (map[i][j] == 7) drawSquare(battleship, teamStartPosition, i, j, Color::Yellow);
			else if (map[i][j] == 8) drawSquare(battleship, teamStartPosition, i, j, Color::Red);
			else if (map[i][j] == 9) drawSquare(battleship, teamStartPosition, i, j, Color::Cyan);
		}
}

void Battlefield::drawSquare(RenderWindow& battleship, float teamStartPosition, int L, int N, Color color) const
{
	RectangleShape rectangle(Vector2f(step, step));
	rectangle.move(teamStartPosition + step * (N - 1), startOne + step * (L - 1));
	rectangle.setFillColor(color);
	battleship.draw(rectangle);
}








