#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <iostream>

using namespace std;

class Shape {
public: 
	Shape(double sidelength) : sidelength(sidelength) {}
	virtual double CalcArea() const = 0;
	virtual double CalcPerimeter() const = 0;
	virtual double CalcAngle() const = 0;

protected:	
	double sidelength;
};

class Square : public Shape {
public:
	Square(double sidelength) : Shape(sidelength) {};

	double CalcArea() const {
		return sidelength*sidelength;
	}

	double CalcPerimeter() const {
		return sidelength*4;
	}

	double CalcAngle() const {
		return 90;
	}
};

class Triangle : public Shape {
public: 
	Triangle(double sidelength) : Shape(sidelength) {};

	double CalcArea() const {
		return sidelength*sidelength*sqrt(3)/4;
	}

	double CalcPerimeter() const {
		return sidelength*3;
	}

	double CalcAngle() const {
		return 60;
	}
};

class Hexagon: public Shape {
public:
	Hexagon(double sidelength) : Shape(sidelength) {};

	double CalcArea() const {
		return sidelength*sidelength*sqrt(3)*3/2;
	}

	double CalcPerimeter() const {
		return sidelength*6;
	}

	double CalcAngle() const {
		return 120;
	}
};

/* randomly generate a list of shapes, then process this list and compute their areas */
int main () {
	vector<Shape*> shapes;
	for (int i = 0; i < 1000; i++) {
		int shape_type = rand() % 3 + 1;
		if (shape_type == 1) {
			shapes.push_back(new Square(1));
		}
		if (shape_type == 2) {
			shapes.push_back(new Triangle(1));
		}
		if (shape_type == 3) {
			shapes.push_back(new Hexagon(1));
		}
	}
	for (int i = 0; i < 1000; i++) {
		Shape* curr_shape = shapes[i];
		cout << "Area: " << curr_shape->CalcArea() << " Perimeter: " << curr_shape->CalcPerimeter() << " Angle: " << curr_shape->CalcAngle() << endl;
		delete curr_shape;
	}
}
