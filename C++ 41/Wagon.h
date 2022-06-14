#pragma once


struct Wagon
{
	stack<Product> products;
	int count = products.size();
	static int s_id;
	int id = 0;
	int speed = 0;
	string country = "";

	Wagon() = default;

	Wagon(stack<Product>_products, int _speed, string _country)
	{
		speed = _speed;
		country = _country;
		count = _products.size();
		id = s_id++;
		if(!_products.empty())
			while (!_products.empty())
				products.push(_products.top());
	}
};

int Wagon::s_id = 1;


ostream& operator << (ostream& out, Wagon w)
{
	for (size_t i = 0; i < w.count; i++)
		cout << w.products._Get_container()[i];

	return out;
}

