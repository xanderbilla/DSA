//Java ZonedDateTime class
//Java ZonedDateTime class is an immutable representation of a
// date-time with a time-zone. It inherits Object class and implements
// the ChronoZonedDateTime interface.

//ZonedDateTime class is used to store all date and time fields,
// to a precision of nanoseconds, and a time-zone with a zone offset 
//used to handle ambiguous local date-times.



//Java ZonedDateTime class Example

import java.time.ZonedDateTime;  
public class ZonedDateTime{  
  public static void main(String[] args) {  
    ZonedDateTime zone = ZonedDateTime.parse("2024-03-20T08:20:10+05:30[Asia/Kolkata]");  
    System.out.println(zone);  
  }  
}  