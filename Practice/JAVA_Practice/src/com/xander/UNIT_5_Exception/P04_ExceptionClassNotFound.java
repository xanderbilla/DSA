package com.xander.UNIT_5_Exception;

//k. ClassNotFound Exception :

// Java program to demonstrate ClassNotFoundException 
public class P04_ExceptionClassNotFound
{ 
    public static void main(String[] args) { 
        try{ 
            Class.forName("Class1");   // Class1 is not defined 
        } 
        catch(ClassNotFoundException e){ 
            System.out.println(e); 
            System.out.println("Class Not Found..."); 
        } 
    } 
}