#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <Windows.h>
#include <string>
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

void Small::showInfo() const
{
	string alive = isAlive ? "��" : "���";
	cout << "X: " << x << "\nY: " << y << "\n��� � �����: " << alive << " (��������� " << life << "/" << dur << ")" << endl;
}

void Big::showInfo() const
{
	string alive = isAlive ? "��" : "���";
	cout << "X: " << x << "\nY: " << y << "\n��� � �����: " << alive << " (��������� " << life << "/" << dur << ")" << endl;
	string sailing = horiz ? "����� ���������" : "� ��������";
	if (isAlive) cout << "�����: " << sailing << endl;
	else cout << "���� ���� ���� �� ������: " << sailing << endl;
}

void Small::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	RectangleShape rectangle(Vector2f(step, step * dur));
	rectangle.move(teamStartPosition + (step * (x - 1)), startOne + (step * (y - 1))); // ����������
	rectangle.setFillColor(Color(175, 180, 240)); // ������������� ���� ��������������
	battleship.draw(rectangle); // ��������� ��������������
}

void Big::drawShip(RenderWindow& battleship, float teamStartPosition) const
{
	RectangleShape rectangle(Vector2f(step, step * dur));
	if (horiz) rectangle.rotate(270);
	rectangle.move(teamStartPosition + (step * (x - 1)), startOne + (step * (y - 1))); // ����������
	rectangle.setFillColor(Color(175, 180, 240)); // ������������� ���� ��������������
	battleship.draw(rectangle); // ��������� ��������������
}