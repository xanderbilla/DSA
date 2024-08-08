//A lambda expression can have zero or any number of arguments. Let's see the examples:

//Java Lambda Expression Example: No Parameter

interface Javaable {
    public String say();
}

public class LambdaExpression2 {
    public static void main(String[] args) {
        Javaable s = () -> {
            return "Java with Lambda ";
        };
        System.out.println(s.say());
    }
}