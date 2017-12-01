#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include <vector>
#include <iostream>
#include <map>

using namespace std;


class ShapeVisitor;
class Square;
class Triangle;
class Hexagon;

class Shape {
public: 
	Shape(double sidelength) : sidelength(sidelength) {}
	virtual void Accept(ShapeVisitor* shape) {}
	virtual double GetLen() const {return sidelength;}

protected:
	double sidelength;
};


class ShapeVisitor {
public:
	virtual void VisitSquare(const Square& sq) = 0; 
	virtual void VisitTriangle(const Triangle& tri) = 0;
	virtual void VisitHexagon(const Hexagon& hex) = 0;
};

class Square: public Shape {
public: 
	Square(double sidelength) : Shape(sidelength) {};
	
	void Accept(ShapeVisitor* visitor) {
		visitor -> VisitSquare(*this);
	}
};

class Triangle: public Shape {
public: 
	Triangle(double sidelength) : Shape(sidelength) {};
	
	void Accept(ShapeVisitor* visitor) {
		visitor -> VisitTriangle(*this);
	}
};

class Hexagon: public Shape {
public: 
	Hexagon(double sidelength) : Shape(sidelength) {};
	
	void Accept(ShapeVisitor* visitor) {
		visitor -> VisitHexagon(*this);
	}
};


class AreaVisitor : public ShapeVisitor {
public: 
	double GetValForShape(const Shape& shape) {
		return val_map[&shape];
	}

	void VisitSquare(const Square& sq) {
		val_map[&sq] = sq.GetLen() * sq.GetLen();
	}

	void VisitTriangle(const Triangle& tri) {
		val_map[&tri] = tri.GetLen() * tri.GetLen() * sqrt(3)/4;
	}

	void VisitHexagon(const Hexagon& hex) {
		val_map[&hex] = hex.GetLen() * hex.GetLen() * sqrt(3)*3/2;	
	}

private:
	map<const Shape*, double> val_map;
};

class PerimeterVisitor : public ShapeVisitor {
public: 
	double GetValForShape(const Shape& shape) {
		return val_map[&shape];
	}

	void VisitSquare(const Square& sq) {
		val_map[&sq] = sq.GetLen()*4;
	}

	void VisitTriangle(const Triangle& tri) {
		val_map[&tri] = tri.GetLen()*3;
	}

	void VisitHexagon(const Hexagon& hex) {
		val_map[&hex] = hex.GetLen()*6;	
	}

private:
	map<const Shape*, double> val_map;
};

class AngleVisitor : public ShapeVisitor {
public: 
	double GetValForShape(const Shape& shape) {
		return val_map[&shape];
	}

	void VisitSquare(const Square& sq) {
		val_map[&sq] = 90;
	}

	void VisitTriangle(const Triangle& tri) {
		val_map[&tri] = 60;
	}

	void VisitHexagon(const Hexagon& hex) {
		val_map[&hex] = 120;	
	}

private:
	map<const Shape*, double> val_map;
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
	
	AreaVisitor areav;
	PerimeterVisitor perimeterv;
	AngleVisitor anglev;

	for (int i = 0; i < 1000; i++) {
		Shape* curr_shape = shapes[i];
		curr_shape -> Accept(&areav);
		curr_shape -> Accept(&perimeterv);
		curr_shape -> Accept(&anglev);
		
		cout << "Area: " << areav.GetValForShape(*curr_shape)  << " Perimeter: " << perimeterv.GetValForShape(*curr_shape) << " Angle: " << anglev.GetValForShape(*curr_shape) << endl;
		delete curr_shape;
	}
}
