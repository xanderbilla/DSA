//Java Lambda Expression Example: Multiple Statements
//@FunctionalInterface  

interface JavaSayable{  
    String say(String message);  
}  
  
public class LambdaExpression8{  
    public static void main(String[] args) {  
      
        // You can pass multiple statements in lambda expression  
        JavaSayable person = (message)-> {  
            String str1 = "Java is easy Language ";  
            String str2 = str1 + message;   
            return str2;  
        };  
            System.out.println(person.say(" for those who practice on daily based"));  
    }  
}  