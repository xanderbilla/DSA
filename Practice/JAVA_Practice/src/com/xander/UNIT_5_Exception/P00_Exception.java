package com.xander.UNIT_5_Exception;

/*
* Java Multi-catch block
*
*   - A try block can be followed by one or more catch blocks.
*   - Each catch block must contain a different exception handler. 
*   - So, if you have to perform different tasks at the occurrence of 
*     different exceptions, use java multi-catch block.
* 
*  => Points to remember
*   + At a time only one exception occurs and at a time only one catch block is executed.
*   + All catch blocks must be ordered from most specific to most general, 
*     i.e. catch for ArithmeticException must come before catch for Exception.
*/

public class P00_Exception {
    public static void main(String[] args) {
        int a = 10, b = 5, c = 5, result;
        try {
            result = a / (b - c);
            System.out.println("result" + result);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught:Division by zero");
        } finally {
            System.out.println("I am in final block");
        }
    }
}
