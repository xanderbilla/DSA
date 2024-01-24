/*------------------------------------------------------------------------------------------+
|ASCII conversion in JAVA.                                                                  |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 24/1/2024                                                             |
|Copyright © 2024 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

public class Practice_04 {
    public static void main(String[] args) throws Exception{
        int num = 65;
        char ch = 'A';

        //data type must be int
        int ascii = ch;

        System.out.println("ASCII value of " + ch + " is " + ascii);
        // System.out.println("ASCII value of " + ch + " is " + (int)ch);
        System.out.println("Character value of " + num + " is " + (char)num);
    }
}