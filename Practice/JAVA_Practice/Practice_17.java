import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
/**
 * Practice_14
 */
public class Practice_17 {

    public static void main(String[] args) {

        LocalTime t = LocalTime.now();
        System.out.println("Before formatting: " + t.toString());

        DateTimeFormatter f = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        String formattedTime = t.format(f);
        System.out.println("After formatting: " + formattedTime);

    }
}