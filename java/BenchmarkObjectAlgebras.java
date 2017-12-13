import java.util.Random;
import java.util.Vector;

public class BenchmarkObjectAlgebras {
    public static void main (String[] args) {
 		double avg_time = 0;	
		for (int num_tests = 0; num_tests < 10; num_tests++) {	
			double start_time = System.nanoTime();	
			Vector<Area> areas = new Vector();
			Vector<Perimeter> perimeters = new Vector();
			Vector<Angle> angles = new Vector();
			AreaWithPentagon areaFactory = new AreaWithPentagon();
			PerimeterWithPentagon perimeterFactory = new PerimeterWithPentagon();
			AngleWithPentagon angleFactory = new AngleWithPentagon();
		    Random rand_gen = new Random();	
            for (int i = 0; i < 1000000; i++) {
				int shape_type = rand_gen.nextInt(4) + 1;
				if (shape_type == 1) {
					areas.add(areaFactory.square(1));
					perimeters.add(perimeterFactory.square(1));
					angles.add(angleFactory.square(1));	
				}
				if (shape_type == 2) {
					areas.add(areaFactory.triangle(1));
					perimeters.add(perimeterFactory.triangle(1));
					angles.add(angleFactory.triangle(1));
				}
				if (shape_type == 3) {
					areas.add(areaFactory.hexagon(1));
					perimeters.add(perimeterFactory.hexagon(1));
					angles.add(angleFactory.hexagon(1));
				}
				if (shape_type == 4) {
					areas.add(areaFactory.pentagon(1));
					perimeters.add(perimeterFactory.pentagon(1));
					angles.add(angleFactory.pentagon(1));
				}
			}

			for (int i = 0; i < 1000000; i++) {
				areas.get(i).area(); 
                perimeters.get(i).perimeter(); 
                angles.get(i).angle();
			}
			double end_time = System.nanoTime();
		    double time_passed = (end_time - start_time)/1000000000.0;	
            avg_time = (avg_time*num_tests + time_passed)/(num_tests + 1);
		}
		System.out.println("average time passed " + avg_time);
    }
}
