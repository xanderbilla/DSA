//Java MonthDay Class Example: isValidYear()


import java.time.*;  
public class UtilMonthDayYr {  
  public static void main(String[] args) {  
    MonthDay month = MonthDay.now();  
    boolean b = month.isValidYear(2023);  
    System.out.println(b);  
  }  
}  