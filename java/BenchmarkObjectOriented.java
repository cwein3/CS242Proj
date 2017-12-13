import java.util.Random;
import java.util.Vector;

public class BenchmarkObjectOriented {
    public static void main (String[] args) {
 		double avg_time = 0;	
		for (int num_tests = 0; num_tests < 10; num_tests++) {	
			double start_time = System.nanoTime();	
			Vector<Shape> shapes = new Vector();
		    Random rand_gen = new Random();	
            for (int i = 0; i < 1000000; i++) {
				int shape_type = rand_gen.nextInt(4) + 1;
				if (shape_type == 1) {
			        shapes.add(new Triangle(1));	
                }
				if (shape_type == 2) {
			        shapes.add(new Square(1));	
                }
				if (shape_type == 3) {
					shapes.add(new Hexagon(1));
                }
				if (shape_type == 4) {
				    shapes.add(new Pentagon(1));	
				}
			}

			for (int i = 0; i < 1000000; i++) {
		        shapes.get(i).CalcArea();
                shapes.get(i).CalcPerimeter();
                shapes.get(i).CalcAngle();
            }
			double end_time = System.nanoTime();
		    double time_passed = (end_time - start_time)/1000000000.0;	
            avg_time = (avg_time*num_tests + time_passed)/(num_tests + 1);
		}
		System.out.println("average time passed " + avg_time);
    }
}
