#include <SFML/Graphics.hpp>	
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

#include "battleship.hpp"

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

void kuriBambuk(RenderWindow& battleship)
{
	Ship ship1 (3, 5);
	Ship ship2 (3, 7, 2, true);
	Ship ship3 (10, 8, 3, false);
	Ship ship4 (6, 1, 4, true);

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
	Ship* ship2 = new Ship(3, 7, 2, true);
	Ship* ship3 = new Ship(10, 8, 3, false);
	Ship* ship4 = new Ship(6, 1, 4, true);

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
*/

void bfPtr(RenderWindow& battleship, int stepL, int stepN)
{
	int shift = 4;


	float N = 0.1666666;
	float n = 0.0666666;
	float slip = shift > 2 ? N + n * (shift - 3) : 0;

	float aimSlip = step * slip;
	float aimRadius = step / shift;
	// step = 100
	// aimRad 2  3          4          5
	// aimSli 0  0.1666666  0.2333333  0.29999999
	CircleShape aim(aimRadius);
	//aim.setOutlineColor(Color::White);
	//aim.setOutlineThickness(1);

	aim.move(startTwo + (step * (stepL - 1)) + aimSlip, startOne + (step * (stepN - 1)) + aimSlip);
	aim.setFillColor(Color::White);


	//RectangleShape bdPointer(Vector2f(step, step));
	//bdPointer.move(startTwo + (step * (stepL - 1)), startOne + (step * (stepN - 1)));
	//bdPointer.setFillColor(Color::Yellow);
	battleship.draw(aim);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	



	Player* human = new Player(true);
	Player* computer = new Player(false);

	computer->InitializeRandomFleet();
	srand(static_cast<unsigned int>(time(0)));
	//human->InitializeRandomFleet();
	//human->showSimpleBoundMap();
	//human->menu();

	



	RenderWindow battleship(VideoMode((int)x, (int)y), "Battleship!");
	
	int ptrPosL = 0, ptrPosN = 0;
	Coords aim{ 1, 1 };
	int shotResult = 0;

	computer->showSimpleBoundMap();
	computer->showInfo();
	// Главный цикл приложения: выполняется, пока открыто окно
	while (battleship.isOpen())
	{
		// Обрабатываем события в цикле
		Event event;
		while (battleship.pollEvent(event))
		{
			if (event.type == Event::Closed)
				battleship.close();

			
			// Была ли нажата клавиша на клавиатуре?
			if (event.type == Event::KeyPressed)
				// Эта кнопка – стрелка вверх?
				// if (event.key.code == Keyboard::Up) rotate = true;
				// Или может стрелка влево?
				if (event.key.code == Keyboard::Left && aim.L > 1) aim.L--;
				else if (event.key.code == Keyboard::Right && aim.L < 10) aim.L++;
				else if (event.key.code == Keyboard::Up && aim.N > 1) aim.N--;
				else if (event.key.code == Keyboard::Down && aim.N < 10) aim.N++;
				else if (event.key.code == Keyboard::Enter)
				{
					shotResult = computer->takeShot(aim); // 0 - (не попал) 1 - (подбил) 2 - (уничтожил) 3 - (ошибочный выстрел в уже уничтоженную клетку)
					if (shotResult == 1 || shotResult == 2)
					{
						system("cls");
						computer->updateShipData(aim);
						computer->showSimpleBoundMap();
						computer->showInfo();
					}

					else
					{
						system("cls");
						computer->showSimpleBoundMap();
						computer->showInfo();
					}
					
				}
				else if (event.key.code == Keyboard::BackSpace)
				{
					system("cls");
					computer->showSimpleBoundMap(); // Почему рисует криво а ?
					computer->showInfo();
				}

		}

		// Установка цвета фона
		battleship.clear(Color::Black);

		
		drawNet(battleship, startOne, startOne, (int)step);
		drawNet(battleship, startTwo, startOne, (int)step);
		human->drawFleet(battleship, startOne);
		//computer->drawFleet(battleship, startTwo);
		computer->drawBattlefield(battleship, startTwo);

		bfPtr(battleship, aim.L, aim.N);
		

		// Отрисовка окна
		battleship.display();
	}

	return 0;
}