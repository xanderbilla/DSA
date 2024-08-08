//..Java Lambda Expression Example: Single Parameter


interface Javaable{  
    public String say(String name);  
}  
  
public class LambdaExpression3{  
    public static void main(String[] args) {  
      
        // Lambda expression with single parameter.  
        Javaable s1=(name)->{  
            return "Hello CLASS"+name;  
        };  
        System.out.println(s1.say("CSE"));  
          
        // You can omit function parentheses    
        Javaable s2= name ->{  
            return "Hello CLASS"+name;  
        };  
        System.out.println(s2.say("CSE"));  
    }  
}  