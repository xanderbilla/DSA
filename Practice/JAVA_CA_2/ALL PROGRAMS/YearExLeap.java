import java.time.Year;  
public class YearExLeap {  
  public static void main(String[] args) {  
    Year year = Year.of(2024);  
    System.out.println(year.isLeap());  
  }  
}  

//is leap yr