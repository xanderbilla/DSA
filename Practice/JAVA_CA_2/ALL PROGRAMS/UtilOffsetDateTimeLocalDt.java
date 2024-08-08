//Java OffsetDateTime Class Example: toLocalDate()

import java.time.OffsetDateTime;  
public class UtilOffsetDateTimeLocalDt {  
    public static void main(String[] args) {  
        OffsetDateTime offsetDT = OffsetDateTime.now();  
        System.out.println(offsetDT.toLocalDate());  
    }  
}  