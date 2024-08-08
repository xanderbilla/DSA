//Java Calendar Class
//./Java Calendar class is an abstract class that provides methods 
//for converting date between a specific instant in time and 
//a set of calendar fields such as MONTH, YEAR, HOUR, etc.
// It inherits Object class and implements the Comparable interface.

//Java Calendar Class Example: getMaximum()
import java.util.*;  
public class CalendarGetMax {  
   public static void main(String[] args) {  
   Calendar calendar = Calendar.getInstance();  
   int maximum = calendar.getMaximum(Calendar.DAY_OF_WEEK);  
   System.out.println("Maximum number of days in week: " + maximum);  
   maximum = calendar.getMaximum(Calendar.WEEK_OF_YEAR);  
   System.out.println("Maximum number of weeks in year: " + maximum);  
   }  
}  

