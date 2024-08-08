//Java MonthDay Class Example: get()

import java.time.*;  
import java.time.temporal.*;  
public class UtilMonthDayEx{  
  public static void main(String[] args) {  
    MonthDay month = MonthDay.now();  
    long n = month.get(ChronoField.MONTH_OF_YEAR);  
    System.out.println(n);  
  }  
}  