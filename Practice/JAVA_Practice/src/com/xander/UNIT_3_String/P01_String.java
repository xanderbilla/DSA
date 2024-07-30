package com.xander.UNIT_3_String;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class P01_String {

    public void String_display() {

        // Convert String to StringBuilder

        String s = "La$de na bhujjam";
        // String s = "";

        StringBuilder sb = new StringBuilder(s); // Convert String to StringBuilder

        /*
         * length() of the string i.e., number of characters in the string
         * codePointCount() of the string i.e., number of Unicode code points in the
         * string
         */
        System.out.println("Character at 2th position: " + sb.charAt(2));
        System.out.println("Character at 2th position: " + sb.codePointAt(2));

    }

    public void showMethods() {
        // display all the method name of the stringBuilder class using javap

        try {
            Process process = Runtime.getRuntime().exec("javap java.util.Arrays");
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));

            StringBuilder bytecodeOutput = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                bytecodeOutput.append(line).append("\n");
            }

            System.out.println(bytecodeOutput.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void Special_Character() {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        StringBuilder sb = new StringBuilder(s);

        /*

        if(Character.isDigit((char) x)){
            count++;
        }

        int sum = 0;
        int odd = 47;

        for (int i = 0; i < sb.length(); i++) {
            if (!Character.isLetterOrDigit(sb.charAt(i))) {
                System.out.print(sb.charAt(i) + " ");
                sum += sb.codePointAt(i);

                // replace the special character with odd number
                sb.setCharAt(i, (char) (odd += 2));
            }
        }
        System.out.println("\nSum of Unicode of all special characters: " + sum);
        System.out.println("String after replacing special characters: " + sb);
        */

        /*
         * Delete sequence of string
         */

        // System.out.println("Enter the sequence to delete: " + sb.delete(3, 6));
        
        System.out.println("Enter the sequence to delete: " + sb.delete(sb.length(), (sb.length() + 1)));
        System.out.println("String after deleting the sequence: " + sb);

        sc.close();
    }

    
}
