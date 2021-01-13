#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <Windows.h>
#include <string>
#include "battleship.hpp"

using namespace std;
using namespace sf; 



void thisIsForExample_SFML()
{
	// Устанавливаем 8-й уровень сглаживания
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(500, 300), "SFML Works!", Style::Default, settings);

	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				window.close(); // тогда закрываем его
		}
		// Установка цвета фона
		window.clear(Color(250, 220, 100, 0));

		// Устанавливаем круг радиусом 50
		CircleShape circle(50.f);
		circle.setFillColor(Color(230, 0, 230)); // закрашиваем наш круг
		circle.setOutlineThickness(15.f); // устанавливаем толщину контура круга
		circle.setOutlineColor(Color(80, 220, 50)); // устанавливаем цвет контура
		circle.move(15, 15); // перемещаем круг для корректного отображения в окне
		window.draw(circle); // отрисовка круга

		// Создаем треугольник
		CircleShape triangle(65.f, 3);
		triangle.setPosition(125, 0); // устанавливаем начальную позицию справа от круга
		triangle.setFillColor(Color::Blue); // устанавливаем цвет треугольника - синий
		window.draw(triangle); // отрисовка треугольника

		// Создаем квадрат
		CircleShape square(60.f, 4);
		square.setPosition(250, 0); // устанавливаем начальную позицию справа от треугольника
		square.setFillColor(Color::Red); // устанавливаем цвет квадрата - красный
		window.draw(square); // отрисовка квадрата

		// Создаем октагон
		CircleShape octagon(60.f, 8);
		octagon.setPosition(380, 0); // устанавливаем начальную позицию справа от квадрата
		octagon.setFillColor(Color::Cyan); // устанавливаем цвет октагона - бирюзовый
		window.draw(octagon); // отрисовка октагона

		// Заготовка фигуры многоугольника 
		ConvexShape convex;
		convex.setPointCount(5); // устанавливаем ему 5 вершин

		// Устанавливаем координаты вершин
		convex.setPoint(0, Vector2f(0.f, 0.f));
		convex.setPoint(1, Vector2f(150.f, 10.f));
		convex.setPoint(2, Vector2f(120.f, 90.f));
		convex.setPoint(3, Vector2f(30.f, 100.f));
		convex.setPoint(4, Vector2f(5.f, 50.f));

		convex.setFillColor(Color::Black); // устанавливаем цвет многоугольника - черный
		convex.move(1, 150); // теперь сдвинем его вниз и чуть-чуть вправо
		window.draw(convex); // отрисовка многоугольника

		// Создаем прямоугольник размером 70х100
		RectangleShape rectangle(Vector2f(70.f, 100.f));
		rectangle.move(165, 150); // перемещаем его в нижний ряд справа от многоугольника
		rectangle.setFillColor(Color(175, 180, 240)); // устанавливаем цвет прямоугольника
		window.draw(rectangle); // отрисовка прямоугольника

		// Линия с заданной толщиной
		RectangleShape line_with_thickness(Vector2f(130.f, 5.f));
		line_with_thickness.rotate(45.f); // поворачиваем её на 45 градусов
		line_with_thickness.setFillColor(Color(15, 180, 140)); // устанавливаем цвет линии
		line_with_thickness.move(250, 150); // перемещаем её в нижний ряд справа от прямоугольника
		window.draw(line_with_thickness); // отрисовка линии

		// Линия с нулевой толщиной. Создаем её в качестве массива вершин типа Vertex
		Vertex line_without_thickness[] =
		{
			Vertex(Vector2f(390.f, 240.f)), // координата первой вершины
			Vertex(Vector2f(470.f, 150.f)) // координата второй вершины
		};
		line_without_thickness->color = Color::Black; // устанавливаем цвет линии - черный
		window.draw(line_without_thickness, 2, Lines); // отрисовка линии

		// Отрисовка окна
		window.display();
	}
}
/*
void garbage(RenderWindow battleship)
{
	// Ширина клетки
	int w = 32;
	int gridLogic[10][10];
	int gridView[10][10];
	// Загрузка текстуры и создание спрайта
	Texture t;
	t.loadFromFile("images/texture.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
		}

	// Устанавливаем белый фон
	battleship.clear(Color::White);
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			// Вырезаем из спрайта нужный нам квадратик текстуры
			s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
			// Устанавливаем его в заданную позицию...
			s.setPosition(i * w, j * w);
			// ... и отрисовываем
			battleship.draw(s);
		}
}
y = 750; // Масштаб
	x = y * 1.8f;

	step = y / 15.0f;
	startOne = step * 3;
	startTwo = step * 15;
*/


void kuriBambuk(RenderWindow& battleship)
{
	Small ship1 (3, 5);
	Big ship2 (3, 7, 2, true);
	Big ship3 (10, 8, 3, false);
	Big ship4 (6, 1, 4, true);

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


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	
	RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");


	drawNet(battleship, startOne, startOne, (int)step);
	drawNet(battleship, startTwo, startOne, (int)step);


	




	kuriBambuk(battleship);




	

	

	battleship.display();
	// Главный цикл приложения: выполняется, пока открыто окно
	while (battleship.isOpen())
	{
		Event e;
		while (battleship.pollEvent(e))
		{
			if (e.type == Event::Closed)
				battleship.close();
		}
	}

	return 0;
}