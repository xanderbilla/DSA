/*
 You are developtng a text-process•ng tool for a language-learning platform One of the requirements IS to Implement a feature that
checks whether a gtven phrase ts a palindrome or not This feature Will be used to provide Immediate feedback to language learners as
they practice writing phases and sentences
Your task ts to wnte a Java program that checks whether a qwen phrase entered by the user IS a palindrome or not using a Deque data
structure
Input Format:
The should expect the user to Input a streing representing a phrase
Output Format:
proqram should output a message Indicating whethe' the entered phrase IS a palindrorne or not
Note:
• Remove ail non-alphanumenc characters from the Input phrase and convert It to lowercase This step ensures that the
palindrome check IS case-insensitive and •gnores punctuation and spaces
• The partial code IS prowded to you 'n the editor
e 

Test Cases

Test Case 1:
Expected Output:
A man, a plan, a canal, Panama!
A man, a plan, a canal, Panama! is a palindrome

Case 2:
Expected Output:
Programming is fun
Programming is fun is not a palindrome
 */

 package com.xander.UNSCHEDUED_TEST;

import java.util.Scanner;

public class PalindromeChecker {

    public static boolean isPalindrome(String input) {
        
        String cleanInput = input.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        
        int left = 0;
        int right = cleanInput.length() - 1;
        while (left < right) {
            if (cleanInput.charAt(left) != cleanInput.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        if (isPalindrome(input)) {
            System.out.println(input + " is a palindrome");
        } else {
            System.out.println(input + " is not a palindrome");
        }
        scanner.close();
    }
}