abstract class Shape {
    double sidelength;
    public Shape(double sidelength) {
        this.sidelength = sidelength;
    }

    public abstract double CalcArea();
    public abstract double CalcPerimeter();
    public abstract double CalcAngle();
}

class Square extends Shape {

    public Square(double sidelength) {super(sidelength);}

    @Override
    public double CalcArea() {
        return sidelength*sidelength;
    }
    
    @Override
    public double CalcPerimeter() {
        return sidelength*4;
    }

    @Override
    public double CalcAngle() {
        return 90;
    }
}

class Triangle extends Shape {

    public Triangle(double sidelength) {super(sidelength);}


    @Override
    public double CalcArea() {
        return 0.433*sidelength*sidelength;
    }
    
    @Override
    public double CalcPerimeter() {
        return sidelength*3;
    }

    @Override
    public double CalcAngle() {
        return 60;
    }
}

class Hexagon extends Shape {
    
    public Hexagon(double sidelength) {super(sidelength);}

    @Override
    public double CalcArea() {
        return 2.60*sidelength*sidelength;
    }
    
    @Override
    public double CalcPerimeter() {
        return sidelength*6;
    }

    @Override
    public double CalcAngle() {
        return 120;
    }
}

class Pentagon extends Shape {

    public Pentagon(double sidelength) {super(sidelength);}

    @Override
    public double CalcArea() {
        return 1.72*sidelength*sidelength;
    }
    
    @Override
    public double CalcPerimeter() {
        return sidelength*5;
    }

    @Override
    public double CalcAngle() {
        return 108;
    }
}
