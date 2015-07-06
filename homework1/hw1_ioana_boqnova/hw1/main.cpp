#include "Hex.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	HNumber a;
	a.setNumber("1A");
	a.print();

	HNumber b;
	b.setNumber("B3");
	HNumber c;
	c = a + b;
	c.print();
	cout << "a + b = " ; 
	c.print(); cout << endl;
	c = a - b;
	cout << "a - b = ";
	c.print(); cout << endl;
	c = a * b;
	cout << "a * b = ";
	c.print(); cout << endl;
	c = a / b;
	cout << "a / b = ";
	c.print(); cout << endl;
	c = a % b;
	c.print(); cout << endl;

	cout << "a < b " << (a < b) << endl;
	cout << "a > b " << (a > b) << endl;
	cout << "a == b " << (a == b) << endl;
	cout << "a <= b " << (a <= b) << endl;
	cout << "a >= b " << (a >= b) << endl;

	system("pause");
	return 0;
}
