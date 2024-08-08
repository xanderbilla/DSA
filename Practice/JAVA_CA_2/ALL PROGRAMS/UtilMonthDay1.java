//Java MonthDay Class Example


import java.time.*;  
public class UtilMonthDay1 {  
  public static void main(String[] args) {  
    MonthDay month = MonthDay.now();  
    LocalDate date = month.atYear(2020);  
    System.out.println(date);  
  }  
}  