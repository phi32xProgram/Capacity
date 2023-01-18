// CapacityProject.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;
int main()
{
	int x;
	int y;
	int nummer;
	bool laeuft = true;

	enum FieldStatus{empty, house};
	FieldStatus gebaeudeart;

	cout << "Geben Sie die Breite ein!" << endl;
	cin >> x;
	cout << "Geben Sie die Laenge ein!" << endl;
	cin >> y;
    
	FieldStatus baubereich[10][10];	// veraltete c++ compiler version, 10 als default, eigtl muss hier x und y aus der Eingabe stehen

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			baubereich[i][j] = empty;
		}
	}
	//Anzeigemenü  ############################################
	//Schleifenaufruf des Menues bis abbruchbedingung
	while (laeuft) {
		//Menue
		cout << "      // Menue // \n" << endl;
		cout << "|| 1.Gebaeude setzen.    ||\n" << endl;
		cout << "|| 2.Bereich loeschen.   ||\n" << endl;
		cout << "|| 3.Ausgabe Baubereich. ||\n" << endl;
		cout << "|| 4.End.                ||\n" << endl;
		cout << "Nummer Eingeben!:" << endl;
		cin >> nummer;
		cout << "________________________" << endl;
		//#########################################################
		//Menuelogik
		switch (nummer) {
		case 1:
			char eingabeArt;
			FieldStatus art;
			int lengthg, widthg, posx, posy;
			cout << "Bitte geben Sie Art, Laenge, Breite und die x und y Position ihres Gebaeudes an! \n Entweder 'h' fuer Haus oder 'e' fuer leer" << endl;
			cin >> eingabeArt; cin >> lengthg; cin >> widthg; cin >> posx; cin >> posy;
			eingabeArt == 'h' ? art = FieldStatus::house : art = FieldStatus::empty;
			//eintragen
			if ((posx + lengthg) > x || (posy + widthg > y)) {
				cout << "Gebäude wäre außerhalb des Bereichs" << endl;
			}
			else{
			for (int i = posx; i < posx + lengthg; i++) {
				for (int j = posy; j < posy + widthg; j++) {
					if (baubereich[i][j] == 1) {
						cout << "Hier steht schon ein Gebäude" << endl;
						break;
					}
					else{
						baubereich[i][j] = art;
					}
				}
			}}
			break;
		case 2:
			int dposx, dposy;
			cout << "Bitte geben Sie) die x und y Position ihres Gebaeudes an!";
			cin >> dposx; cin >> dposy;
			break;
		case 3:
			for (int i = 0; i < x; i++) {
				cout << endl;
				for (int j = 0; j < y; j++) {
					cout << "[" << baubereich[i][j] << "]";
				}
			}cout << endl;
			break;
		case 4:
			laeuft = false;
			break;
		default:
			cout << "Gibts nich!" << endl;
			break;
		}cin.clear();
	}
	return 0;
}

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