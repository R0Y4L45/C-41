#pragma once


struct Product
{
	string _name = "";
	float price = 0;
	Product() = default;

	Product(string name, float _price)
	{
		price = _price;
		_name = name;
	}
};

ostream& operator << (ostream& out, Product p)
{
	out << "Name : " << p._name << "      Price : " << p.price << endl;
	return out;
}

