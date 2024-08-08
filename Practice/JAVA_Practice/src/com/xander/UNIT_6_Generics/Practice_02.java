package com.xander.UNIT_6_Generics;

import java.util.Scanner;

/*
* Use generics - The first line will contain an integer T (number of test cases). First line of 
* each test case will contain one integer c. Next line will contain a string if c is equal to 1 or 
* will contain a integer if c is equal to 2. 
*/

public class Practice_02<T>{
    private T c;
    Practice_02(T c){
        this.c = c;
    }

    public void print(){
        System.out.println(c.getClass().getSimpleName());
        System.out.println(c);
    }

    public static void call() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++){
            int c = sc.nextInt();
            if(c == 1){
                String s = sc.next();
                Practice_02<String> obj = new Practice_02<>(s);
                obj.print();
            }else{
                int n = sc.nextInt();
                Practice_02<Integer> obj = new Practice_02<>(n);
                obj.print();
            }
        }
        sc.close();
    }
}