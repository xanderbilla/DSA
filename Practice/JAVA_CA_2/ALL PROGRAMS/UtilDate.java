//The java.util.Date class represents date and time in java. 
//It provides constructors and methods to deal with date and time in java.

// Java program to demonstrate constuctors of Date 
import java.util.*; 
  
public class UtilDate
{ 
    public static void main(String[] args) 
    { 
        Date d1 = new Date(); 
        System.out.println("Current date is " + d1); 
        Date d2 = new Date(2323223232L); 
        System.out.println("Date represented is "+ d2 ); 
    } 
} 