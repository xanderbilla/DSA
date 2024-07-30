package com.xander.UNSCHEDUED_TEST;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SuperMarket {
    public static void main(String[] args) {
        Queue<String> checkoutLine = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("1. Add Customer to Line");
            System.out.println("2. Process Customer");
            System.out.println("3. View Checkout Line Status");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    String customerName = scanner.next();
                    checkoutLine.add(customerName);
                    System.out.println(customerName + " added");
                    break;
                case 2:
                    if (!checkoutLine.isEmpty()) {
                        String servedCustomer = checkoutLine.poll();
                        System.out.println("Processing customer: " + servedCustomer);
                    } else {
                        System.out.println("Checkout line is empty");
                    }
                    break;
                case 3:
                    if (checkoutLine.isEmpty()) {
                        System.out.println("Checkout line is empty");
                    } else {
                        for (String customer : checkoutLine) {
                            System.out.println(customer);
                        }
                    }
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        } while (choice != 4);

        scanner.close();
    }
}