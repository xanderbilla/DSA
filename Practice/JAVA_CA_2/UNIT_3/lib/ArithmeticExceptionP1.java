//Exception handling toString() and getMessage() methods

public class ArithmeticExceptionP1 {
    public static void main(String[] args) {
        try {
            int a = 10;
            int b = 0;
            int c = a / b;
            System.out.println("Division of a and b is: " + c);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: " + e);
            System.out.println("Exception message: " + e.getMessage());
        }
    }
}

/*
 * Output: 
 * Exception caught: java.lang.ArithmeticException: / by zero 
 * Exception message: / by zero
 */