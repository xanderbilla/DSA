//Java Calendar Class
//./Java Calendar class is an abstract class that provides methods 
//for converting date between a specific instant in time and 
//a set of calendar fields such as MONTH, YEAR, HOUR, etc.
// It inherits Object class and implements the Comparable interface.

//Java Calendar Class Example
import java.util.Calendar;  
public class CalendarExample121{  
   public static void main(String[] args) {  
   Calendar calendar = Calendar.getInstance();  
   System.out.println("The current date is : " + calendar.getTime());  
   calendar.add(Calendar.DATE, -15);  
   System.out.println("15 days ago: " + calendar.getTime());  
   calendar.add(Calendar.MONTH, 4);  
   System.out.println("4 months later: " + calendar.getTime());  
   calendar.add(Calendar.YEAR, 2);  
   System.out.println("2 years later: " + calendar.getTime());  
   }  
}  

