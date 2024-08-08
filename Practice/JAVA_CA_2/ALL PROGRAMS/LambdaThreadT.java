//How to create a thread using lambda expressions in Java?
//Java 8Object Oriented ProgrammingProgramming
//The lambda expressions are introduced in Java 8. 
//.It is one of the most popular features of Java 8 and brings
// functional programming capabilities to Java. By using a lambda expression, 
//we can directly write the implementation for a method in Java.

//In the below program, we can create a thread by implementing the 
//Runnable interface using lamda expression. While using the lambda expressions, 
//we can skip the new Runnable() and run() method because the compiler knows that
// Thread object takes a Runnable object and that contains only one method run() that takes no argument.

//Example

public class LambdaThreadT {
   public static void main(String args[]) {
      // Child thread
      new Thread(() -> { // Lambda Expression
         for(int i=1; i <= 5; i++) {
            System.out.println("Child Thread: "+ i);
            try {
               Thread.sleep(500);
            } catch(Exception e) {
               e.printStackTrace();
            }
         }
      }).start();
      // Main Thead
      for(int j=1; j < 5; j++) {
         System.out.println("Main Thread: "+ j);
         try {
            Thread.sleep(500);
         } catch(Exception e) {
            e.printStackTrace();
         }
      }
   }
}