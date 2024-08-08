import java.time.LocalDate;  
// String to LocalDate in java 8  
public class UtilLocalDate   
{  
    public static void main(String ar[])   
    {  
        // Example 1  
        String dInStr = "2024-03-20";  
        LocalDate d1 = LocalDate.parse(dInStr);  
        System.out.println("String to LocalDate : " + d1);  
        // Example 2  
        String dInStr2 = "2024-03-21";  
        LocalDate d2 = LocalDate.parse(dInStr2);  
        System.out.println("String to LocalDate : " + d2);  
    }  
}  