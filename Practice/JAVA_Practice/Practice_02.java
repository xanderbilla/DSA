/*------------------------------------------------------------------------------------------+
|Command line argument.                                                                     |
+-------------------------------------------------------------------------------------------+
|Author: Vikas Singh                                                                        |   
|Date of Publication: 24/1/2024                                                             |
|Copyright © 2024 Xander Billa                                                              |
+------------------------------------------------------------------------------------------*/

public class Practice_02 {
    public static void main(String[] args) throws Exception{
        System.out.println("Command line arguments are:");
        
        for (int i = 0; i < args.length; i++) {
            System.out.println(args[i]);
        }
    }
}