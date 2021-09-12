#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Geometry 
{
public:
	virtual double area() const = 0;
	virtual void draw() const;
};
void Geometry::draw() const
{
	cout << "geometry object" << endl;
}
class Circle : public Geometry
{
	double rad = 2;
public:
	virtual double area() const final;
	void draw() const override;
};
class Rectangle : public Geometry
{
private:
	double a = 3, b = 4;
public:
	virtual double area() const final;
	void draw() const override;
};
class Triangle : public Geometry
{
private:
	double a = 1, b = 1, c = 3;
public:
	virtual double area() const final;
	void draw()const override;
};
class Exeption
{
	
};
double Circle::area() const { return M_PI * rad * rad; }
double Rectangle::area() const { return a * b; }
double Triangle::area() const 
{
	double p, s, sum;
	p = (a + b + c) / 2;
	sum = p * (p - a)*(p - b)*(p - c);
	if (sum < 0)
	{
		throw Exeption();
	}
	s = sqrt(sum);
	return s; 
}
void Circle::draw()const
{
	cout << "(circle)" << endl;
}
void Rectangle::draw()const
{
	cout << "[rectangle]" << endl;
}
void Triangle::draw()const
{
	cout << "<triangle>" << endl;
}
void gui(vector<Geometry*> &objs)
{
	for (Geometry* g : objs)
	{
		g->draw();
		cout << "area= " << g->area() << endl;
	}
}
int main()
{
	Circle c;
	Rectangle r;
	Triangle t;
	vector<Geometry*>objs;
	objs.push_back(&c);
	objs.push_back(&r);
	objs.push_back(&t);
	try
	{
		gui(objs);
	}
	catch(Exeption)
	{
		cout << "triangle doesn't exist";
	}
	return 0;
}
