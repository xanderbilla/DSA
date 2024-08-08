//Java Period Example: plus()

import java.time.Period;  
public class PeriodExample4 {  
  public static void main(String[] args) {  
    Period period1 = Period.ofMonths(4);   
    Period period2 = period1.plus(Period.ofMonths(2));  
    System.out.println(period2);  
  }  
}  