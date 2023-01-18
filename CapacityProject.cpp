// CapacityProject.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;

//Materialien Klassen
class Material {
protected:
	float price;
	double anzahl;

public:
	virtual float getPrice() = 0;
	virtual double getAnzahl() = 0;
};

class Wood : public Material {
public:
	Wood() {
		price = 2.50;
		anzahl++;
	}
	double getAnzahl() {
		return anzahl;
	}
	float getPrice() {
		return price;
	}
};

class Metal : public Material {
public:
	Metal() {
		price = 3.50;
		anzahl++;
	}
	double getAnzahl() {
		return anzahl;
	}
	float getPrice() {
		return price;
	}
};

class Plastic : public Material {
public:
	Plastic() {
		price = 5.00;
		anzahl++;
	}
	double getAnzahl() {
		return anzahl;
	}
	float getPrice() {
		return price;
	}
};


//Buildings
class Building {
public:
	Building();
	~Building();
	double getPrice();
	void setPrice(double price);
	string getLabel();
	void setLabel(string label);
	string* getMaterials();
	void setMaterials(string* materials);

private:
	double price;
	string label;
	string* materials;
};

class House : public Building {
public:
	House();
	~House();
	double getBasePrice();
	void setBasePrice(double basePrice);
	string getLabel();
	void setLabel(string label);
	string* getMaterials();
	void setMaterials(string* materials);

private:
	double basePrice;
	string label;
	string* materials;
};

int main() {
	House* house = new House();
	house->setBasePrice(100);
	house->setLabel("My House");
	string materials[3] = { "Wood", "Wood", "Wood" };
	house->setMaterials(materials);
	cout << "Price: " << house->getBasePrice() << endl;
	cout << "Label: " << house->getLabel() << endl;
	cout << "Materials: ";
	for (int i = 0; i < 3; i++) {
		cout << house->getMaterials()[i] << " ";
	}
	cout << endl;
	delete house;

	return 0;
}