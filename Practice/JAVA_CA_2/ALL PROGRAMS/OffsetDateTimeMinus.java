//Java OffsetDateTime Class Example: minusDays()

import java.time.OffsetDateTime;  
public class OffsetDateTimeMinus {  
  public static void main(String[] args) {  
    OffsetDateTime offset = OffsetDateTime.now();  
    OffsetDateTime value =  offset.minusDays(240);  
    System.out.println(value);  
  }   
}  