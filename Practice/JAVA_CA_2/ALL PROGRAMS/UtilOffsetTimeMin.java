//Java OffsetTime Class Example: getMinute()

import java.time.OffsetTime;  
public class UtilOffsetTimeMin {  
  public static void main(String[] args) {  
    OffsetTime offset = OffsetTime.now();  
    int m = offset.getMinute();  
    System.out.println(m+ " minute");  
  }  
}  