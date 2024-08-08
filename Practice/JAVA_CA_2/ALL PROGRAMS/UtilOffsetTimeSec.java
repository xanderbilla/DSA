//Java OffsetTime Class Example: getSecond()

import java.time.OffsetTime;  
public class UtilOffsetTimeSec {  
  public static void main(String[] args) {  
    OffsetTime offset = OffsetTime.now();  
    int s = offset.getSecond();  
    System.out.println(s+ " second");  
  }  
}  