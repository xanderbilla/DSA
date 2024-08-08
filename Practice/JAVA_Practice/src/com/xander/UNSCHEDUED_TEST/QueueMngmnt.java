package com.xander.UNSCHEDUED_TEST;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;


/*
 Queue management system
Implement a Java program to simulate a prtnttng queue management system the Oueue and Deque frameworks
The program should allow users to add pont IObs to the queue remove pnnt JObs from the queue and vtew the current status of the
queue
Your program should Include the follow.nq functionalities
1 Add Print Job: Prompt the user to enter the name nf the document to be ponted and add It to the end of the queue
2 Remove Print Job: Remove the pont at the front of the queue and display the name of the document that was removed
3 View Queue Status: Display the names ot all documents currently In the queue a'ong With their order
Refer to the displayed test cases for better understanding
Sample Test Cases
Test Case 1:
Expected Output:
Add
3. View Queue Status
Enter you: choice: 3
2. Remove Print
3 View Queue Status
Enter your 2
til
 */

public class QueueMngmnt {
    public static void main(String[] args) {
        Deque<String> queue = new ArrayDeque<>();
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("1. Add Print Job");
            System.out.println("2. Remove Print Job");
            System.out.println("3. View Queue Status");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    String document = scanner.next();
                    queue.addLast(document);
                    System.out.println(document + " added");
                    break;
                case 2:
                    if (!queue.isEmpty()) {
                        String removedDocument = queue.removeFirst();
                    System.out.println(removedDocument + " removed");
                    } else {
                        System.out.println("Queue is empty.");
                    }
                    break;
                case 3:
                    if (queue.isEmpty()) {
                        System.out.println("Queue is empty.");
                    } else {
                        int order = 1;
                        for (String doc : queue) {
                            System.out.println(order + ". " + doc);
                            order++;
                        }
                    }
                    break;
                    case 4:
                        System.exit(0);
                        break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
