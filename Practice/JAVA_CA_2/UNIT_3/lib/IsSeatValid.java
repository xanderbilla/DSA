/*
 * Write a program to accept the seat number and display the seat number. 
 * If the seat number is not valid, display "Invalid seat number".
 */

import java.util.Scanner;

public class IsSeatValid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the seat number:");
        try {
            int seat = sc.nextInt();
            System.out.println("Seat number is: " + seat);
        } catch (Exception e) {
            System.out.println("Invalid seat number");
        }
        sc.close();
    }
}