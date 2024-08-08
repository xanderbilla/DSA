//Java LocalTime Example: plusHours() and plusMinutes()

import java.time.LocalTime;  
public class UtilLocalTimePlus {  
  public static void main(String[] args) {  
    LocalTime time1 = LocalTime.of(10,45,45);  
    System.out.println(time1);  
    LocalTime time2=time1.plusHours(1);  
    LocalTime time3=time2.plusMinutes(45);  
    System.out.println(time3);  
  }  
}  