package com.xander.UNSCHEDUED_TEST;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


/*
You are developing a messaging system for a distributed application. The system should allow multiple clients to communicate
asynchronously by sending messages to each other through a message queue.

Task:
Implement a Java program that utilizes the Queue framework to simulate a message queue system. Clients should be able to send
and receive messages through the queue.

Your program should include the following functionalities:
1. Send Message: Allow clients to send messages to the queue.
2. Receive Message: Allow clients to receive messages from the queue.
3. View Queue: Display the current messages in the queue.
4. Exit: Terminate the program.

Note:
- The given program is menu-driven. Refer to the displayed test cases for the input and output layout.

Sample Test Cases:
Test Case 1:
Expected Output:
1. Send Message
2. Receive Message
3. View Queue
4. Exit
1
Enter message: "Hello"
Message sent successfully!

2
Received message: "Hello"

3
Current messages in the queue:
- "Hello"

4
Program terminated.
*/

/**
 * Message
 */
public class Message {
    private static Queue<String> messageQueue = new LinkedList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("1. Send Message");
            System.out.println("2. Receive Message");
            System.out.println("3. View Queue");
            System.out.println("4. Exit");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    scanner.nextLine(); // Consume the newline character
                    String message = scanner.nextLine();
                    messageQueue.add(message);
                    System.out.println("Message sent: " + message);
                    break;
                case 2:
                    receiveMessage();
                    break;
                case 3:
                    viewQueue();
                    break;
                case 4:
                    System.out.println("Program terminated.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 4);

        scanner.close();
    }

    private static void receiveMessage() {
        if (messageQueue.isEmpty()) {
            System.out.println("No messages in the queue.");
        } else {
            String message = messageQueue.poll();
            System.out.println("Received message: " + message);
        }
    }

    private static void viewQueue() {
        System.out.println("Current messages in the queue:");
        for (String message : messageQueue) {
            System.out.println(message);
        }
    }
}