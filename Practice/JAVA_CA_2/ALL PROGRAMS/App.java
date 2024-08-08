import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

class App {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String date1 = sc.nextLine();
        String date2 = sc.nextLine();


    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
    
    LocalDate localDate1 = LocalDate.parse(date1, formatter);
    LocalDate localDate2 = LocalDate.parse(date2, formatter);

    String res = ChronoUnit.DAYS.between(localDate1, localDate2) + " days";

    //excluding 'Sunday' and 'Saturday'

    long count = 0;
    for (LocalDate date = localDate1; date.isBefore(localDate2); date = date.plusDays(1)) {
        if (date.getDayOfWeek().getValue() < 6) {
            count++;
        }
    }

    System.out.println(res);




    }

}