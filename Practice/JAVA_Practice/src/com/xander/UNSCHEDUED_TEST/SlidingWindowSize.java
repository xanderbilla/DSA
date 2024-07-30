
package com.xander.UNSCHEDUED_TEST;
import java.util.*;

/*
 
Sliding Window Technique is a method used to efficiently solve problems that involve defining a window or range in the input data
(arrays or strings) and then moving that window across the data to perform some operation within the window.
Write a Java program to find the minimum element in each sliding window of size K in an array using a Deque. The program should
prompt the user to enter the elements of the array and the window size K, and then print the minimum element in each sliding window.

Input Format:
The first line should prompt the user to enter the elements of the array.
The second line should prompt the user to enter the window size K.

Output Format:
The program should print the minimum element in each sliding window.

Note:
K must be less than the number of elements in the array.

Sample Test Cases:

Test Case 1:
Input:
-10 52 63 41 89 56 -2
5
Output:
-10 41 -2

Test Case 2:
Input:
8 -9 5 -2 8 3 -4
2
Output:
-9 -9 -2 -2 3 -4

*/


public class SlidingWindowSize {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] elements = scanner.nextLine().split(" ");
        
        int k = scanner.nextInt();
        
        Deque<Integer> deque = new LinkedList<>();
        
        for (int i = 0; i < elements.length; i++) {
            while (!deque.isEmpty() && deque.peekFirst() <= i - k) {
                deque.pollFirst();
            }
            
            while (!deque.isEmpty() && Integer.parseInt(elements[deque.peekLast()]) >= Integer.parseInt(elements[i])) {
                deque.pollLast();
            }
            
            deque.offerLast(i);
            
            if (i >= k - 1) {
                System.out.print(elements[deque.peekFirst()] + " ");
            }
        }
        
        scanner.close();
    }
}
