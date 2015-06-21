#include <iostream>
using namespace std;
struct Point
{
	double x, y;
	Point(double = 0, double = 0);
	void print() const
	{
		cout << "(" << this->x << "," <<this->y << ") ";
	}
};
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
class Figure
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual Point center() const = 0;
	virtual void print() const = 0;
}; 
class Triangle : public Figure
{
	Point a, b, c;
public:
	Triangle();
	Triangle(Point, Point, Point);
	virtual double area() const;
	virtual double perimeter() const;
	virtual Point center() const;
	virtual void print() const;
};
Triangle::Triangle()
{
	this->a.x = 0; this->a.y = 0;
	this->b.x = 1; this->b.y = 0;
	this->c.x = 0; this->c.y = 2;
}
Triangle::Triangle(Point a, Point b, Point c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
double Triangle::area() const
{
	double res = 0;
	double x = sqrt(pow((this->a.x - this->b.x), 2) + pow((this->a.y - this->b.y), 2));
	double y = sqrt(pow((this->b.x - this->c.x), 2) + pow((this->b.y - this->c.y), 2));
	double z = sqrt(pow((this->c.x - this->a.x), 2) + pow((this->c.y - this->a.y), 2));
	if ((x + y) > z && (x + z) > y && (y + z) > x)
	{
		double p = (x + y + z) / 2;
		res = sqrt(p* (p - x) * (p - y) * (p - z));
		return res;
	}
	return 0;	
}
double Triangle::perimeter() const
{
	double x = sqrt(pow((this->a.x - this->b.x), 2) + pow((this->a.y - this->b.y), 2));
	double y = sqrt(pow((this->b.x - this->c.x), 2) + pow((this->b.y - this->c.y), 2));
	double z = sqrt(pow((this->c.x - this->a.x), 2) + pow((this->c.y - this->a.y), 2));	
	if ((x + y) > z && (x + z) > y && (y + z) > x) return (x + y + z);
	else return 0;
}
Point Triangle::center() const
{
	double x = sqrt(pow((this->a.x - this->b.x), 2) + pow((this->a.y - this->b.y), 2));
	double y = sqrt(pow((this->b.x - this->c.x), 2) + pow((this->b.y - this->c.y), 2));
	double z = sqrt(pow((this->c.x - this->a.x), 2) + pow((this->c.y - this->a.y), 2));
	if ((x + y) > z && (x + z) > y && (y + z) > x)
	{
		double p = (x + y + z) / 2;
		double ap = p - y;
		double r = (2 * this->area()) / (x + y + z);
		Point res(this->a.x + ap, this->a.y + r);
		return res;
	}
	return Point(0, 0);
}
void Triangle::print() const
{
	cout << "Triangle with points: " << "Point A"; this->a.print();
	cout << " Point B"; this->b.print(); cout << "  Point C"; this->c.print(); cout << endl;	
}
class Rectangle : public Figure
{
	Point a, c;
public:
	Rectangle()
	{
		this->a.x = 0; this->a.y = 0;
		this->c.x = 2; this->c.y = 2;
	}
	Rectangle(Point, Point);
	virtual double area() const;
	virtual double perimeter() const;
	virtual Point center() const;
	virtual void print() const;
};
Rectangle::Rectangle(Point a, Point c)
{
	this->a = a;
	this->c = c;
}
double Rectangle::area() const
{
	double x = abs(this->c.x - this->a.x);
	double y = abs(this->c.x - this->a.y);
	return x*y;
}
double Rectangle::perimeter() const
{
	double x = abs(this->c.x - this->a.x);
	double y = abs(this->c.x - this->a.y);
	return (2 * x + 2 * y);
}
Point Rectangle::center() const
{
	double x = abs(this->c.x - this->a.x);
	double y = abs(this->c.x - this->a.y);
	if (x == y)
	{
		return Point(this->a.x + x / 2, this->a.y + x / 2);
	}
	return Point(0, 0);
}
void Rectangle::print() const
{
	cout << "Rectangle with points:   Point A"; this->a.print(); cout << " Point C"; this->c.print(); 
	cout << "and sands length: " << abs(this->c.x - this->a.x) << " , " << abs(this->c.y - this->a.y) << endl;
}
class Circle : public Figure
{
	Point o;
	double r;
public:
	Circle();
	Circle(Point o, double r);
	virtual double area() const;
	virtual double perimeter() const;
	virtual Point center() const;
	virtual void print() const;
};
Circle::Circle()
{
	this->o.x = 0; this->o.y = 0;
	this->r = 1;
}
Circle::Circle(Point o, double r)
{
	this->o = o;
	this->r = r;
}
double Circle::perimeter() const
{
	return 2 * 3.14 * r;
}
Point Circle::center() const
{
	return this->o;
}
double Circle::area() const
{
	return 3.14 * r * r;
}
void Circle::print() const
{
	cout << "Circle with center  Point 0"; this->o.print(); 
	cout << " and r: " << this->r << endl;
}

bool isInFigure(Figure& one, Figure& two)
{
	Figure& temp1 = dynamic_cast<Triangle&>(one);
	Figure& temp2 = dynamic_cast<Circle&>(two);

}
int main()
{
	Point a(0, 0), b(1, 0), c(0, 2);
	Triangle test(a, b, c);
	/*cout << test.area() << "  " << test.perimeter() << endl;
	test.center().print();*/

	Point r1(0, 0); Point r2(2, 2);
	Rectangle r(r1, r2);
	/*cout << r.area() << "  " << r.perimeter() << "     ";
	r.center().print(); */

	test.print();
	r.print();
	Circle cr; cr.print();
	system("pause");
	return 0;
}
