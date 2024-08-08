package com.xander.UNIT_5_Exception;

//F. ArrayIndexOutOfBounds Exception

// Java program to demonstrate ArrayIndexOutOfBoundException 
class ExceptionArrayIndexOutOfBound
{ 
    public static void main(String args[]) 
    { 
        try{ 
            int a[] = new int[5]; 
            a[6] = 9; // accessing 7th element in an array of 
                      // size 5 
        } 
        catch(ArrayIndexOutOfBoundsException e){ 
            System.out.println ("Array Index is Out Of Bounds"); 
        } 
    } 
} 