#pragma once
using namespace std;

bool yesNo(char& choice, string yes = "����������", string no = "���������");
void push_back(int*& oldArr, const int newItem, int& size);
void push_back(string*& oldArr, const string newItem, int& size);

class Instrument
{
	int totalPrice;
	static int maxPrice;
	static Instrument maxPriceTool;

	virtual void renewHighestPrice(const int size, Instrument** iss);

protected:

	// ����� ����
	string itemName;
	int itemQuantity;
	string model;
	int price;

	static int quantity;

public:

	static string className;

	Instrument() : itemName("000"), itemQuantity(0), model("000"), price(0), totalPrice(0) {}
	Instrument(string n, int q, string m, int p) : itemQuantity(q), itemName(n), model(m), price(p), totalPrice(p * q)
	{ 
		quantity += q;
		if (maxPrice < price) { maxPrice = price; maxPriceTool = *this; }
	}
	virtual ~Instrument() { void renewHighestPrice(const int size, Instrument** iss); }

	inline static int getMaxPrice() { return maxPrice; }
	inline static Instrument getmaxPriceTool() { return maxPriceTool; }
	inline static int getTotalQ() { return quantity; }
	inline int getQ() const { return itemQuantity; }

	virtual void showInfo() const;
	virtual string getClassName() { return className; } // inline
	virtual void initializeSpecialData() {}
	void initializeData();

	static void show_stat();
	static void show_all(const int size, Instrument** iss);
	static void push_back_iss(Instrument**& oldIss, int& size, Instrument* newItem);
	static void delete_item_iss(Instrument**& oldIss, int& size, int index);
	static void create_new_item(Instrument**& iss, int& issSize);
};



class Mechanical : public Instrument
{
	string* materials;
	int matsLen;
	static int maxPrice;
	static Mechanical maxPriceTool;

	bool isAlereadyChosen(const int currentIndex, const int* chosenIndexes, const int chosenLen);
	void renewHighestPrice(const int size, Instrument** iss);

protected:

	static int quantity;

public:

	static string className;

	Mechanical() : materials(nullptr), matsLen(0) {}
	Mechanical(string n, int q, string m = "000", int p = 0, string* mat = nullptr, int ml = 0) : Instrument(n, q, m, p), materials(mat), matsLen(ml)
	{
		quantity += q;
		if (maxPrice < price) { maxPrice = price; maxPriceTool = *this; }
	}
	~Mechanical()
	{
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
		void renewHighestPrice(const int size, Instrument** iss);
		delete[] materials;
	}

	inline static int getMaxPrice() { return maxPrice; }
	inline static Instrument getmaxPriceTool() { return maxPriceTool; }
	virtual void showInfo() const;
	virtual void initializeSpecialData();

	inline static int getTotalQ() { return quantity; }
	virtual string getClassName() { return Instrument::getClassName() + ". " + className; }
};

class Fishing : public Mechanical
{
	char isProfessional;

protected:

	static int quantity;

public:

	static string className;

	Fishing() : isProfessional('-') {}
	Fishing(string n, int q, string m = "000", int p = 0, string* mat = nullptr, char ip = '-') : Mechanical(n, q, m, p, mat), isProfessional(ip) { quantity += q; }
	~Fishing()
	{
		Mechanical::quantity -= itemQuantity;
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
	}

	void showInfo() const;
	void initializeSpecialData();

	inline static int getTotalQ() { return quantity; }
	string getClassName() { return Mechanical::getClassName() + ". " + className; }
};



class Electrical : public Instrument
{
	int voltage;
	static int maxPrice;
	static Electrical maxPriceTool;

	void renewHighestPrice(const int size, Instrument** iss);

protected:

	static int quantity;

public:

	static string className;

	Electrical() : voltage(0) {}
	Electrical(string n, int q, string m, int p, int v) : Instrument(n, q, m, p), voltage(v) 
	{
		quantity += q;
		if (maxPrice < price) { maxPrice = price; maxPriceTool = *this; }
	}
	virtual ~Electrical() { void renewHighestPrice(const int size, Instrument** iss); }

	inline static int getMaxPrice() { return maxPrice; }
	inline static Instrument getmaxPriceTool() { return maxPriceTool; }
	virtual void showInfo() const;
	virtual void initializeSpecialData();

	inline static int getTotalQ() { return quantity; }
	virtual string getClassName() { return Instrument::getClassName() + ". " + className; }
};

class Rechargeable : public Electrical
{
	int batteryCapacity;

protected:

	static int quantity;

public:

	static string className;

	Rechargeable() : batteryCapacity(0) {}
	Rechargeable(string n, int q, string m = "000", int p = 0, int v = 0, int bc = 0) : Electrical(n, q, m, p, v), batteryCapacity(bc) { quantity += q; }
	~Rechargeable()
	{
		Electrical::quantity -= itemQuantity;
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
	}

	void showInfo() const;
	void initializeSpecialData();

	inline static int getTotalQ() { return quantity; }
	string getClassName() { return Electrical::getClassName() + ". " + className; }
};



class �lectricalWire : public Electrical
{
	double wireLength;

protected:

	static int quantity;

public:

	static string className;

	�lectricalWire() : wireLength(0) {}
	�lectricalWire(string n, int q, string m = "000", int p = 0, int v = 0, double wl = 0) : Electrical(n, q, m, p, v), wireLength(wl) { quantity += q; }
	~�lectricalWire()
	{
		Electrical::quantity -= itemQuantity;
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
	}

	void showInfo() const;
	void initializeSpecialData();

	inline static int getTotalQ() { return quantity; }
	string getClassName() { return Electrical::getClassName() + ". " + className; }
};

