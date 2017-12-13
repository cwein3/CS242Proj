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
class Pentagon;

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

class ShapeVisitorWithPentagon : virtual public ShapeVisitor {
public:
	virtual void VisitPentagon(const Pentagon& pentagon) = 0;
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

class Pentagon: public Shape {
public:
	Pentagon(double sidelength) : Shape(sidelength) {};

	void Accept(ShapeVisitor* visitor) {
		ShapeVisitorWithPentagon* v = dynamic_cast<ShapeVisitorWithPentagon*>(visitor);
		v -> VisitPentagon(*this);
	}
};

class AreaVisitor : virtual public ShapeVisitor {
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

protected:
	double recent_val;
};

class PerimeterVisitor : virtual public ShapeVisitor {
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

protected:
	double recent_val;
};

class AngleVisitor : virtual public ShapeVisitor {
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

protected:
	double recent_val;
};

class AreaVisitorWithPentagon: public ShapeVisitorWithPentagon, public AreaVisitor { 
public: 
	void VisitPentagon(const Pentagon& pent) {
		recent_val = pent.GetLen()*pent.GetLen()*1.72;	
	}
};

class PerimeterVisitorWithPentagon: public ShapeVisitorWithPentagon, public PerimeterVisitor { 
public: 
	void VisitPentagon(const Pentagon& pent) {
		recent_val = pent.GetLen()*5;	
	}
};

class AngleVisitorWithPentagon: public ShapeVisitorWithPentagon, public AngleVisitor { 
public: 
	void VisitPentagon(const Pentagon& pent) {
		recent_val = 108;	
	}
};

/* randomly generate a list of shapes, then process this list and compute their areas */
int main () {
 	double avg_time = 0;	
	for (int num_tests = 0; num_tests < 10; num_tests++) {	
		time_t start_time = time(0);	
		vector<Shape*> shapes;
		for (int i = 0; i < 1000000; i++) {
			int shape_type = rand() % 4 + 1;
			if (shape_type == 1) {
				shapes.push_back(new Square(1));
			}
			if (shape_type == 2) {
				shapes.push_back(new Triangle(1));
			}
			if (shape_type == 3) {
				shapes.push_back(new Hexagon(1));
			}
			if (shape_type == 4) {
				shapes.push_back(new Pentagon(1));
			}
		}
		
		AreaVisitorWithPentagon areav;
		PerimeterVisitorWithPentagon perimeterv;
		AngleVisitorWithPentagon anglev;

		for (int i = 0; i < 1000000; i++) {
			Shape* curr_shape = shapes[i];
			curr_shape -> Accept(&areav);
			curr_shape -> Accept(&perimeterv);
			curr_shape -> Accept(&anglev);
			
			//cout << "Area: " << areav.GetValForShape(*curr_shape)  << " Perimeter: " << perimeterv.GetValForShape(*curr_shape) << " Angle: " << anglev.GetValForShape(*curr_shape) << endl;
			delete curr_shape;
		}
		double time_passed = difftime(time(0), start_time);
		avg_time = (avg_time*num_tests + time_passed)/(num_tests + 1);
	}
	cout << "average time passed " << avg_time;
}
