//Program to demonstrate methods of LocalDate class
// such as now(), minusDays(), plusDays().

import java.time.LocalDate;    
public class UtilDateNow{    
  public static void main(String[] args) {    
    LocalDate date = LocalDate.now();    
    LocalDate yesterday = date.minusDays(1);    
    LocalDate tomorrow = yesterday.plusDays(2);   
    LocalDate month = date.minusMonths(1);
    LocalDate year = date.minusYears(1);
    System.out.println("Last month date: "+month);
    System.out.println("Last year date: "+year); 
    System.out.println("Today date: "+date);    
    System.out.println("Yesterday date: "+yesterday);    
    System.out.println("Tomorrow date: "+tomorrow);    
  }    
}    