//Java OffsetTime Class Example: getHour()


import java.time.OffsetTime;  
public class UtilOffsetTimeHour {  
  public static void main(String[] args) {  
    OffsetTime offset = OffsetTime.now();  
    int h = offset.getHour();  
    System.out.println(h+ " hour");  
  }  
}