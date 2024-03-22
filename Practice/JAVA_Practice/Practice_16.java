import java.time.LocalTime;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;

/**
 * Practice_14
 */
public class Practice_16 {

    public static void main(String[] args) {
        
        ZoneId z = ZoneId.systemDefault();
        System.out.println("Zone: " + z.toString());

        ZoneId z2 = ZoneId.of("Asia/Tokyo");
        System.out.println("Zone: " + z2.toString());

        ZoneId z3 = ZoneId.of("Asia/Kolkata");
        System.out.println("Zone: " + z3.toString());

        LocalTime t = LocalTime.now(z);
        System.out.println("Time: " + z + " " + t.toString());

        LocalTime t2 = LocalTime.now(z2);
        System.out.println("Time: " + z2 + " " + t2.toString());

        long hour = ChronoUnit.HOURS.between(t, t2);
        System.out.println("Hour between two time zone: " + hour);

        long miute = ChronoUnit.MINUTES.between(t, t2);
        System.out.println("Minute between two time zone: " + miute);




    }
}