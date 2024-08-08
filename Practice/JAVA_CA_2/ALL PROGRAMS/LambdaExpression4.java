//Java Lambda Expression Example: Multiple Parameters


interface JavaAddable{  
    int add(int a,int b);  
}  
  
public class LambdaExpression4{  
    public static void main(String[] args) {  
          
        // Multiple parameters in lambda expression  
        JavaAddable ad1=(a,b)->(a+b);  
        System.out.println(ad1.add(15,25));  
          
        // Multiple parameters with data type in lambda expression  
        JavaAddable ad2=(int a,int b)->(a+b);  
        System.out.println(ad2.add(125,275));  
    }  
}  