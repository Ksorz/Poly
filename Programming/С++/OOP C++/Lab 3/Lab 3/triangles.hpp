using namespace std;

struct Point { double x; double y; };

class Triangle
{
public:

	Point* ABC = new Point[3];
	Triangle();
	Triangle(Point a, Point b, Point c);
	bool isIsosceles();
	void printTriangle();

private:

	double getSideLen(Point one, Point two);

};

int rnd(int min, int max);
void randomTriangles(Triangle*& allTr, int& sizeAll, Triangle*& selectedTr, int& sizeSel, int quantity, int rndMin, int rndMax);
char endOrContinue();
int factorial(int N);
void push_back_Point(Point*& oldArr, int& size, const Point newPoint);
void push_back_Triangle(Triangle*& oldArr, int& size, const Triangle newTriangle);
Point newPoint();
Triangle* buildAllPossibleTriangles(Point* points, int& sizeP, Triangle*& selected, int& sizeT);
void printAllTriangles(Triangle* triangles, int size);
void printAllPoints(Point* arr, int size);
void delTriangles(Triangle*& allTr, int& sizeAll, Triangle*& selectedTr, int& sizeSel);