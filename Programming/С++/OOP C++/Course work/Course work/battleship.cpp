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
	string sailing = isHorizontal ? "����� ���������" : "� ��������";
	if (isAlive) cout << "�����: " << sailing << endl;
	else cout << "���� ���� ���� �� ������: " << sailing << endl;
}

void Ship::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	RectangleShape rectangle(Vector2f(step, step));
	rectangle.move(teamStartPosition + (step * (x - 1)), startOne + (step * (y - 1))); 
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
		if (isHorizontal) rectangle.move(teamStartPosition + (step * (x - 1)) + (step * i), startOne + (step * (y - 1))); // ����������
		else rectangle.move(teamStartPosition + (step * (x - 1)), startOne + (step * (y - 1)) + (step * i)); // ����������
		rectangle.setFillColor(deckIsOk[i] ? Color::Green : Color::Red); // ���� ������������ ����, ��������� �� ������
		battleship.draw(rectangle);
	}
}




bool Battlefield::isPlaceAvailable(Ship& const ship) const
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

void Battlefield::boundPlace(Ship& const ship, bool** boundOnMap)
{
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) boundOnMap[ship.x + (i - 1)][ship.y + (j - 1)] = true;

	for (int i = 0; i < ship.getSize() - 1; i++) // � ������ ������� � 1 �������, ���� ���� ����� ��������
		for (int j = 0; j < 3; j++)
		{
			if (ship.isHorizontal()) boundOnMap[ship.x + 2][ship.y + (j - 1)] = true;
			else boundOnMap[ship.x + (j - 1)][ship.y - 2] = true;
		}
}






void Battlefield::addNewShip()
{
	char choice = '0';
	while (choice != 'q')
	{
		switch (choice)
		{
		case '1':

		default:
			break;
		}
	}
}