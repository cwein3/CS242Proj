#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
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
		return recent_val;
	}

	void VisitSquare(const Square& sq) {
		recent_val = sq.GetLen() * sq.GetLen();
	}

	void VisitTriangle(const Triangle& tri) {
		recent_val = tri.GetLen() * tri.GetLen() * sqrt(3)/4;
	}

	void VisitHexagon(const Hexagon& hex) {
		recent_val = hex.GetLen() * hex.GetLen() * sqrt(3)*3/2;	
	}

private:
	double recent_val;
};

class PerimeterVisitor : public ShapeVisitor {
public: 
	double GetValForShape(const Shape& shape) {
		return recent_val;
	}

	void VisitSquare(const Square& sq) {
		recent_val = sq.GetLen()*4;
	}

	void VisitTriangle(const Triangle& tri) {
		recent_val = tri.GetLen()*3;
	}

	void VisitHexagon(const Hexagon& hex) {
		recent_val = hex.GetLen()*6;	
	}

private:
	double recent_val;
};

class AngleVisitor : public ShapeVisitor {
public: 
	double GetValForShape(const Shape& shape) {
		return recent_val;
	}

	void VisitSquare(const Square& sq) {
		recent_val = 90;
	}

	void VisitTriangle(const Triangle& tri) {
		recent_val = 60;
	}

	void VisitHexagon(const Hexagon& hex) {
		recent_val = 120;	
	}

private:
	double recent_val;
};

/* randomly generate a list of shapes, then process this list and compute their areas */
int main () {
	double avg_time = 0;
	for (int num_tests = 0; num_tests < 10; num_tests++) {	
		time_t start = time(0);	
		vector<Shape*> shapes;
		for (int i = 0; i < 1000000; i++) {
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

		for (int i = 0; i < 1000000; i++) {
			Shape* curr_shape = shapes[i];
			curr_shape -> Accept(&areav);
			curr_shape -> Accept(&perimeterv);
			curr_shape -> Accept(&anglev);
			
			delete curr_shape;
		}
		double time_passed = difftime(time(0), start);
		avg_time = (avg_time*num_tests + time_passed)/(num_tests + 1);
	}
	cout << "Average time of 10 tests: " << avg_time;
}
