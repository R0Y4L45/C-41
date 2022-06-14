#include <iostream>
#include <string>
#include <stack>


using namespace std;


#include "Product.h"
#include "Wagon.h"
#include "Dlink.h"





class Train
{
	DLL<Wagon> wagons;
	int count = wagons.getSize();

public:

	Train() = default;

	Train(DLL<Wagon> _wagons)
	{
		count = wagons.getSize();
		wagons = _wagons;
	}


////////////////////GETTERS///////////

	DLL<Wagon>& getWagons() { return wagons; }

	Wagon getWagonByNo(int id)
	{
		if(wagons.search(id) != NULL)
			return wagons.search(id)->data;
		cout << "There is no such wagon...\n";
	}

//////////////////////////////////////


	void showProductsByNo(int id)
	{
		if (wagons.search(id) != NULL)
		{
			Wagon w = wagons.search(id)->data;
			cout << "Country of Wagon --> " << w.country << endl;
			cout << "ID of Wagon --> " << id << endl;
			cout << "Speed of Wagon --> " << w.speed << " km/s" << endl << endl;
			cout << "Products : " << endl << endl;
			for (size_t i = 0; i < w.count; i++)
				cout << w.products._Get_container()[i];
			cout << endl;
		}
		else
			cout << "There is no such wagon according to id...\n";
	}

//////////////////UPDATES/////////////////////////

	void updateSpeedByNo(int id, int speed)
	{
		if (wagons.search(id) != NULL)
			wagons.search(id)->data.speed = speed;
		else
			cout << "There is no such wagon according to id...\n";
	}

	void updateCountryByNo(int id, string country)
	{
		if (wagons.search(id) != NULL)
			wagons.search(id)->data.country = country;
		else
			cout << "There is no such wagon according to id...\n";
	}

/////////////////////////////////////////////////////


	void deleteWagonById(int id)
	{
		wagons.delete_byId(id);
	}

};





int main()
{
	short choice;
	bool t = true;
	cout << "1.Create product\n2.Create Wagon\n3.Add products to Wagon\n4.Get wangon by ID\n5.Show products by wagon ID\n6.Change speed by wagon ID\n7.Change country by ID\n8.Delete wagon by ID\n0.EXIT\n\n";
	stack<Product> products;
	Train train;
	do 
	{
		cout << "Enter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: //PRODUCT YARADILIR VE MAIN-DE YARADILMIS MUVEQQETI STACK-IN ICINDE SAXLANILIR VE ISTENILEN QEDER PRODUCT YARADILA BILER
		{
			string name;
			float price;
			cout << "Enter name of product : ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter price of product : ";
			cin >> price;
			Product p(name, price);
			products.push(p);
			break;
		}
		case 2://VAQONLAR BURADAN YARADILIR VE ILK YARADILDIQLARI VAXT OLKE VE SURET ELAVE EDILIR ICI ISE BOS OLUR
		{
			stack<Product> temp;
			string country;
			int speed;
			cout << "Enter country of wagon : ";
			cin.ignore();
			getline(cin, country);
			cout << "Enter speed of wagon : ";
			cin >> speed;
			Wagon w(temp, speed, country);
			train.getWagons().push_back(w);
			break;
		}
		case 3:// YUXARIDA YARADILMIS PRODUCTS STACK-ININ ICINDEKI PRODUCTLARI ID-SIN VERDIYIMIZ VAQONA ELAVE EDIR...
		{
			int id;
			cout << "Enter ID of wagon : ";
			cin >> id;

			Wagon w = train.getWagons().search(id)->data;
			w.count = products.size();

			if (!products.empty())
				while (!products.empty())
				{
					w.products.push(products.top());
					products.pop();
				}

			train.getWagons().search(id)->data = w;
			break;
		}
		case 4:// VAQONLARI ID-SINE GORE QAYTARIR
		{
			int id;
			cout << "Enter id : ";
			cin >> id;
			cout << train.getWagonByNo(id);
			break;
		}
		case 5:// ID-SIN VERDIYIMIZ VAQONUN MELUMATLARINI VE PRODUCLARIN MELUMATLARINI VERIR...
		{
			int id;
			cout << "Enter id : ";
			cin >> id;
			train.showProductsByNo(id);
			break;
		}
		case 6:// ISTENILEN VAQONUN SPEED-IN DEYISIR
		{
			int id, speed;
			cout << "Enter id : ";
			cin >> id;
			cout << "Enter new speed : ";
			cin >> speed;
			train.updateSpeedByNo(id, speed);
			break;
		}
		case 7:// ISTENILEN VAQONUN COUNTRY-SIN DEYISIR
		{
			int id;
			string country;
			cout << "Enter id : ";
			cin >> id;
			cout << "Enter new country : ";
			cin.ignore();
			getline(cin, country);
			train.updateCountryByNo(id, country);
			break;
		}
		case 8:// ID-YE GORE VAQONLARI SILIR
		{
			int id;
			cout << "Enter id : ";
			cin >> id;
			train.deleteWagonById(id);
			break;
		}
		case 0:// PROGRAMDAN CIXIS...
			t = false;
			break;
		default:
			cout << "Wrong choice...\n";
			break;
		}
	} while (t);
}