#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

#include "battleship.hpp"

using namespace std;
using namespace sf; 



void thisIsForExample_SFML()
{
	// ������������� 8-� ������� �����������
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(500, 300), "SFML Works!", Style::Default, settings);

	// ������� ���� ����������: �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				window.close(); // ����� ��������� ���
		}
		// ��������� ����� ����
		window.clear(Color(250, 220, 100, 0));

		// ������������� ���� �������� 50
		CircleShape circle(50.f);
		circle.setFillColor(Color(230, 0, 230)); // ����������� ��� ����
		circle.setOutlineThickness(15.f); // ������������� ������� ������� �����
		circle.setOutlineColor(Color(80, 220, 50)); // ������������� ���� �������
		circle.move(15, 15); // ���������� ���� ��� ����������� ����������� � ����
		window.draw(circle); // ��������� �����

		// ������� �����������
		CircleShape triangle(65.f, 3);
		triangle.setPosition(125, 0); // ������������� ��������� ������� ������ �� �����
		triangle.setFillColor(Color::Blue); // ������������� ���� ������������ - �����
		window.draw(triangle); // ��������� ������������

		// ������� �������
		CircleShape square(60.f, 4);
		square.setPosition(250, 0); // ������������� ��������� ������� ������ �� ������������
		square.setFillColor(Color::Red); // ������������� ���� �������� - �������
		window.draw(square); // ��������� ��������

		// ������� �������
		CircleShape octagon(60.f, 8);
		octagon.setPosition(380, 0); // ������������� ��������� ������� ������ �� ��������
		octagon.setFillColor(Color::Cyan); // ������������� ���� �������� - ���������
		window.draw(octagon); // ��������� ��������

		// ��������� ������ �������������� 
		ConvexShape convex;
		convex.setPointCount(5); // ������������� ��� 5 ������

		// ������������� ���������� ������
		convex.setPoint(0, Vector2f(0.f, 0.f));
		convex.setPoint(1, Vector2f(150.f, 10.f));
		convex.setPoint(2, Vector2f(120.f, 90.f));
		convex.setPoint(3, Vector2f(30.f, 100.f));
		convex.setPoint(4, Vector2f(5.f, 50.f));

		convex.setFillColor(Color::Black); // ������������� ���� �������������� - ������
		convex.move(1, 150); // ������ ������� ��� ���� � ����-���� ������
		window.draw(convex); // ��������� ��������������

		// ������� ������������� �������� 70�100
		RectangleShape rectangle(Vector2f(70.f, 100.f));
		rectangle.move(165, 150); // ���������� ��� � ������ ��� ������ �� ��������������
		rectangle.setFillColor(Color(175, 180, 240)); // ������������� ���� ��������������
		window.draw(rectangle); // ��������� ��������������

		// ����� � �������� ��������
		RectangleShape line_with_thickness(Vector2f(130.f, 5.f));
		line_with_thickness.rotate(45.f); // ������������ � �� 45 ��������
		line_with_thickness.setFillColor(Color(15, 180, 140)); // ������������� ���� �����
		line_with_thickness.move(250, 150); // ���������� � � ������ ��� ������ �� ��������������
		window.draw(line_with_thickness); // ��������� �����

		// ����� � ������� ��������. ������� � � �������� ������� ������ ���� Vertex
		Vertex line_without_thickness[] =
		{
			Vertex(Vector2f(390.f, 240.f)), // ���������� ������ �������
			Vertex(Vector2f(470.f, 150.f)) // ���������� ������ �������
		};
		line_without_thickness->color = Color::Black; // ������������� ���� ����� - ������
		window.draw(line_without_thickness, 2, Lines); // ��������� �����

		// ��������� ����
		window.display();
	}
}
/*
void garbage(RenderWindow battleship)
{
	// ������ ������
	int w = 32;
	int gridLogic[10][10];
	int gridView[10][10];
	// �������� �������� � �������� �������
	Texture t;
	t.loadFromFile("images/texture.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
		}

	// ������������� ����� ���
	battleship.clear(Color::White);
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			// �������� �� ������� ������ ��� ��������� ��������
			s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
			// ������������� ��� � �������� �������...
			s.setPosition(i * w, j * w);
			// ... � ������������
			battleship.draw(s);
		}
}
y = 750; // �������
	x = y * 1.8f;

	step = y / 15.0f;
	startOne = step * 3;
	startTwo = step * 15;
*/
void kuriBambuk(RenderWindow& battleship)
{
	Ship ship1 (3, 5);
	BigShip ship2 (3, 7, 2, true);
	BigShip ship3 (10, 8, 3, false);
	BigShip ship4 (6, 1, 4, true);

	cout << "step == " << step << endl;

	ship1.showInfo();
	cout << endl;
	ship2.showInfo();
	cout << endl;
	ship3.showInfo();
	cout << endl;
	ship4.showInfo();


	ship1.drawShip(battleship, startOne);
	ship1.drawShip(battleship, startTwo);

	ship2.drawShip(battleship, startOne);
	ship2.drawShip(battleship, startTwo);

	ship3.drawShip(battleship, startOne);
	ship3.drawShip(battleship, startTwo);

	ship4.drawShip(battleship, startOne);
	ship4.drawShip(battleship, startTwo);

}
void kuriBambuk2(RenderWindow& battleship)
{
	vector<Ship*> fleet;

	Ship* ship1 = new Ship(3, 5);
	BigShip* ship2 = new BigShip(3, 7, 2, true);
	BigShip* ship3 = new BigShip(10, 8, 3, false);
	BigShip* ship4 = new BigShip(6, 1, 4, true);

	fleet.push_back(ship1);
	fleet.push_back(ship2);
	fleet.push_back(ship3);
	fleet.push_back(ship4);

	//ship1.drawShip(battleship, startOne);
	//ship2.drawShip(battleship, startOne);
	//ship3.drawShip(battleship, startOne);
	ship4->drawShip(battleship, startTwo);
	ship4->showInfo();

	fleet[3]->drawShip(battleship, startOne);
	fleet[3]->showInfo();
	//for (const auto& ship : fleet) ship.drawShip(battleship, startOne);
}


void bfPtr(RenderWindow& battleship, int stepL, int stepN)
{

	RectangleShape bdPointer(Vector2f(step, step));
	bdPointer.move(startTwo + (step * stepL), startOne + (step * stepN));
	bdPointer.setFillColor(Color::Yellow);
	battleship.draw(bdPointer);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	



	Player* human = new Player(false);
	Player* computer = new Player(false);
	//human->menu();

	computer->InitializeRandomFleet();
	//srand(static_cast<unsigned int>(time(0)));
	human->InitializeRandomFleet();

	//human->showSimpleBoundMap();
	//human->menu();

	



	RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");
	
	int ptrPosL = 0, ptrPosN = 0;

	// ������� ���� ����������: �����������, ���� ������� ����
	while (battleship.isOpen())
	{
		// ������������ ������� � �����
		Event event;
		while (battleship.pollEvent(event))
		{
			if (event.type == Event::Closed)
				battleship.close();

			
			// ���� �� ������ ������� �� ����������?
			if (event.type == Event::KeyPressed)
				// ��� ������ � ������� �����?
				// if (event.key.code == Keyboard::Up) rotate = true;
				// ��� ����� ������� �����?
				if (event.key.code == Keyboard::Left && ptrPosL > 0) ptrPosL--;
				else if (event.key.code == Keyboard::Right && ptrPosL < 9) ptrPosL++;
				else if (event.key.code == Keyboard::Up && ptrPosN > 0) ptrPosN--;
				else if (event.key.code == Keyboard::Down && ptrPosN < 9) ptrPosN++;
				else if (event.key.code == Keyboard::Enter) computer->takeShot(ptrPosL + 1, ptrPosN + 1);
		}

		// ��������� ����� ����
		battleship.clear(Color::Black);

		bfPtr(battleship, ptrPosL, ptrPosN);
		
		drawNet(battleship, startOne, startOne, (int)step);
		drawNet(battleship, startTwo, startOne, (int)step);

		human->drawFleet(battleship, startOne);
		computer->drawFleet(battleship, startTwo);

		bfPtr(battleship, ptrPosL, ptrPosN);
		

		// ��������� ����
		battleship.display();
	}

	return 0;
}