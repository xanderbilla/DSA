/*------------------------------------------------------------------------------------------+
|Sum using Command line argument.                                                           |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 24/1/2024                                                             |
|Copyright © 2024 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

public class Practice_03 {
    public static void main(String[] args) throws Exception{
        System.out.println("Command line arguments are:");
        int i; 
        int sum = 0;
        for (i = 0; i < args.length; i++) {
            sum += Integer.parseInt(args[i]);
        }
        System.out.println(sum / args.length);
    }
}