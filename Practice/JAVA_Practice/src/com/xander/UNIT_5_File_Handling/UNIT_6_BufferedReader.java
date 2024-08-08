package com.xander.UNIT_5_File_Handling;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class UNIT_6_BufferedReader {
    public void display() {
        FileReader fr = null;
        BufferedReader br = null;

        try {
            File f = new File("D://myfile.txt");
            fr = new FileReader(f);
            br = new BufferedReader(fr);

            /* // read entire file
            * 
            * String line = br.readLine();
            * while (line != null) {
            *     System.out.println(line);
            *     line = br.readLine();
            * }
            */

            /* // count number of characters in the file
            */


        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                br.close();
                fr.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
