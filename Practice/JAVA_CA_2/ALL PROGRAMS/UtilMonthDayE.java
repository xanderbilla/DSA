//Java MonthDay Class Example: range()

import java.time.*;  
import java.time.temporal.*;  
public class UtilMonthDayE {  
  public static void main(String[] args) {  
    MonthDay month = MonthDay.now();  
    ValueRange r1 = month.range(ChronoField.MONTH_OF_YEAR);  
    System.out.println(r1);  
    ValueRange r2 = month.range(ChronoField.DAY_OF_MONTH);  
    System.out.println(r2);  
  }  
}  