package com.xander.UNIT_5_Exception;

import java.util.Scanner;

class ItsZeroException extends Exception {
    public ItsZeroException(String message) {
        super(message);
    }
}


public class P01_CustomException {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int u = sc.nextInt();
        int res = 0;
        try {
            if (u == 0) throw new ItsZeroException("It's Zero Exception");
            res = t / u;
            System.out.println(res);
        } catch (ItsZeroException e) {
            System.out.println(e.getMessage());
        } finally {
            sc.close();
        }
    }    
}