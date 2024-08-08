//..Java LocalTime Example: minusHours() and minusMinutes()


import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.time.LocalDate;  
public class UtilLocalTimeMinus {  
  public static void main(String[] args) {  
    LocalTime time1 = LocalTime.of(10,45,45);  
    System.out.println(time1);  
    LocalTime time2=time1.minusHours(1);  
    LocalTime time3=time2.minusMinutes(45);  
    System.out.println(time3);  

    LocalDate date = LocalDate.now();
    LocalDate yesterday = date.minusDays(1);
    LocalDate tomorrow = yesterday.plusDays(2);
    LocalDate d = LocalDate.now();

    


    String date =

    System.out.println("Today date: "+date);
    System.out.println("Yesterday date: "+yesterday);
    System.out.println("Tomorrow date: "+tomorrow);
  }  
}  