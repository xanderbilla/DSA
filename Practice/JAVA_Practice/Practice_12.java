import java.time.LocalDate;

/**
 * Practice_12
 */
public class Practice_12 {

    public static void main(String[] args) {
        
        String dInString = "2020-07-14";
        LocalDate d = LocalDate.parse(dInString);
        System.out.println("Date: " + d.toString());

        String dInString2 = "2020-07-14";
        LocalDate d2 = LocalDate.parse(dInString2);
        System.out.println("Date: " + d2.toString());

    }
}