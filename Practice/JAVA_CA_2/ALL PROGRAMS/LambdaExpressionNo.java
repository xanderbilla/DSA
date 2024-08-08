/**
lambda expression in java is an anonymous (no name) function that 
does not need to define the data type of input parameters and does 
not need to have a return type. Lambda expression in java implements
 the functional interface and it can be treated as any other java object.
 It can be used to create threads, comparators and can be used to add event Listeners.

In Java, a thread refers to the smallest unit of execution within a process.
 A process is a self-contained program that runs independently, 
and a thread is a lightweight, smaller unit within that process 
that can execute concurrently with other threads. Threads share
 the same resources (like memory space) within a process, but they have their own execution flow.

Multithreading in Java is the concurrent execution of two or more threads. 
Multithreading is a powerful feature that allows developers to write programs
 that can perform multiple tasks simultaneously, improving the overall performance
 and responsiveness of an application. In Java, multithreading is achieved by using
 the Thread class or implementing the Runnable interface.

Here's a brief overview of creating and running threads in Java:

Extending the Thread class:
You can create a new thread by extending the Thread class and overriding its run() method.
 The run() method contains the code that will be executed when the thread is started.

In Java, an anonymous class is a class that is declared and instantiated simultaneously,
 without explicitly providing a name for the class. Anonymous classes are often used when a small,
 one-time-use class is needed, and it doesn't make sense to create a separate named class for it.
 These classes are commonly used for implementing interfaces or extending classes on the fly.


Why use Lambda Expression
To provide the implementation of Functional interface.
Less coding.

Java Lambda Expression Syntax

(argument-list) -> {body}  

Java lambda expression is consisted of three components.

1) Argument-list: It can be empty or non-empty as well.

2) Arrow-token: It is used to link arguments-list and body of expression.

3) Body: It contains expressions and statements for lambda expression.

No Parameter Syntax

() -> {  
//Body of no parameter lambda  
}  

One Parameter Syntax


(p1) -> {  
//Body of single parameter lambda  
}  

Two Parameter Syntax

(p1,p2) -> {  
//Body of multiple parameter lambda  
}  
Let's see a scenario where we are not implementing Java lambda expression. 
Here, we are implementing an interface without using lambda expression
.
======
*/

// Without Lambda Expression

interface Drawable{  
    public void draw();  
}  
public class LambdaExpressionNo {  
    public static void main(String[] args) {  
        int width=8;  
  
        //without lambda, Drawable implementation using anonymous class  
        Drawable d=new Drawable(){  
            public void draw(){System.out.println("Java Version is: "+width);}  
        };  
        d.draw();  
    }  
}  


