interface ShapeAlg<T> {
    T triangle(double sidelength);
    T square(double sidelength);
    T hexagon(double sidelength);
};

interface Area {double area();};

interface Perimeter {double perimeter();};

interface Angle {double angle();};

class AreaShape implements ShapeAlg<Area> {
    public Area triangle(double sidelength) {
        return new Area() {
            public double area () {
                return 0.433*sidelength*sidelength;
            }
        };
    }

    public Area square(double sidelength) {
        return new Area() {
            public double area () {
                return sidelength*sidelength;
            }
        };
    }

    public Area hexagon(double sidelength) {
        return new Area() {
            public double area () {
                return sidelength*sidelength*2.60;
            }
        };
    }
};

class PerimeterShape implements ShapeAlg<Perimeter> {
    public Perimeter triangle(double sidelength) {
        return new Perimeter() {
            public double perimeter() {
                return sidelength*3;
            }
        };
    }

    public Perimeter square(double sidelength) {
        return new Perimeter() {
            public double perimeter() {
                return sidelength*4;
            }
        };
    }

    public Perimeter hexagon(double sidelength) {
        return new Perimeter() {
            public double perimeter() {
                return sidelength*6;
            }
        };
    }
};

class AngleShape implements ShapeAlg<Angle> {
    public Angle triangle(double sidelength) {
        return new Angle() {
            public double angle() {
                return 60;
            }
        };
    }

    public Angle square(double sidelength) {
        return new Angle() {
            public double angle() {
                return 90;
            }
        };
    }

    public Angle hexagon(double sidelength) {
        return new Angle() {
            public double angle() {
                return 120;
            }
        };
    }
};

interface ShapeAlgWithPentagon<T> extends ShapeAlg<T> {
    T pentagon(double sidelength);
};

class AreaWithPentagon extends AreaShape implements ShapeAlgWithPentagon<Area> {
    public Area pentagon(double sidelength) {
        return new Area() {
            public double area() {
                return sidelength*sidelength*1.72;
            }
        };
    }
};

class PerimeterWithPentagon extends PerimeterShape implements ShapeAlgWithPentagon<Perimeter> {
    public Perimeter pentagon(double sidelength) {
        return new Perimeter() {
            public double perimeter() {
                return sidelength*5;
            }
        };
    }
};

class AngleWithPentagon extends AngleShape implements ShapeAlgWithPentagon<Angle> {
    public Angle pentagon(double sidelength) {
        return new Angle() {
            public double angle() {
                return 108;
            }
        };
    }
};
