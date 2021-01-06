#pragma once
using namespace std;



bool yesNo(char& choice, string yes = "Ïðîäîëæèòü", string no = "Çàâåðøèòü");
void push_back(int*& oldArr, const int newItem, int& size);
void push_back(string*& oldArr, const string newItem, int& size);

class Instrument
{
	int totalPrice;

protected:

	// Îáùèå ïîëÿ
	string itemName;
	int itemQuantity;
	string model;
	int price;

	static int quantity;

public:

	static string className;

	Instrument() : itemName("000"), itemQuantity(0), model("000"), price(0), totalPrice(0) {}
	Instrument(string n, int q, string m, int p) : itemQuantity(q), itemName(n), model(m), price(p), totalPrice(p * q) { quantity += q; }
	virtual ~Instrument() {}


	inline static int getTotalQ() { return quantity; }
	inline int getQ() const { return itemQuantity; }

	virtual void showInfo() const;
	virtual string getClassName() { return className; } // inline
	virtual void initializeSpecialData() {}

	static void initializeData(string& iName, int& iQuantity, string& mod, int& p);
	static void show_stat();
	static void show_all(const int size, Instrument** iss);
	static void push_back_iss(Instrument**& oldIss, int& size, Instrument* newItem);
	static void delete_item_iss(Instrument**& oldIss, int& size, int index);
	static void create_new_item(Instrument**& iss, int& issSize);
	static void search(const int size, Instrument** iss);
};



class Mechanical : public Instrument
{
	string* materials;
	int matsLen;

	bool isAlereadyChosen(const int currentIndex, const int* chosenIndexes, const int chosenLen);

protected:

	static int quantity;

public:

	static string className;

	Mechanical() : materials(nullptr), matsLen(0) {}
	Mechanical(string n, int q, string m = "000", int p = 0, string* mat = nullptr, int ml = 0) : Instrument(n, q, m, p), materials(mat), matsLen(ml) 
	{ quantity += q; }
	~Mechanical()
	{
		Instrument::quantity -= itemQuantity;
		quantity -= itemQuantity;
		delete[] materials;
	}

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

protected:

	static int quantity;

public:

	static string className;

	Electrical() : voltage(0) {}
	Electrical(string n, int q, string m, int p, int v) : Instrument(n, q, m, p), voltage(v) { quantity += q; }
	virtual ~Electrical() {}

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



class ÅlectricalWire : public Electrical
{
	double wireLength;

protected:

	static int quantity;

public:

	static string className;

	ÅlectricalWire() : wireLength(0) {}
	ÅlectricalWire(string n, int q, string m = "000", int p = 0, int v = 0, double wl = 0) : Electrical(n, q, m, p, v), wireLength(wl) { quantity += q; }
	~ÅlectricalWire()
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

