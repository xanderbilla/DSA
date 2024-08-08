//Java OffsetDateTime Class Example: plusDays()


import java.time.OffsetDateTime;  
public class OffsetDateTimePlus {  
  public static void main(String[] args) {  
    OffsetDateTime offset = OffsetDateTime.now();  
    OffsetDateTime value =  offset.plusDays(10);  
    System.out.println(value);  
  }  
} 