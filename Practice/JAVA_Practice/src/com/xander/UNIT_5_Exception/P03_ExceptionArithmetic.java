package com.xander.UNIT_5_Exception;

//Examples of Built-in Exception
//A. Arithmetic exception

// Java program to demonstrate ArithmeticException 
public class P03_ExceptionArithmetic
{ 
    public static void main(String args[]) 
    { 
        try { 
            int a = 30, b = 0; 
            int c = a/b;  // cannot divide by zero 
            System.out.println ("Result = " + c); 
        } 
        catch(ArithmeticException e) { 
            System.out.println ("Can't divide a number by 0"); 
        } 
    } 
} 