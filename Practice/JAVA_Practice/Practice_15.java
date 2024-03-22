import java.time.LocalTime;

/**
 * Practice_14
 */
public class Practice_15 {

    public static void main(String[] args) {
        
        LocalTime t = LocalTime.of(10,45,45);
        System.out.println("Time: " + t.toString());

        LocalTime t2 = t.plusHours(1);
        LocalTime t3 = t2.plusMinutes(45);
        // LocalTime t4 = t.minusSeconds(1);
        System.out.println("Time: " + t3.toString());


    }
}