package com.xanderbilla.algorithm;

public class P2_ArrayUtil {

    public void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }

    public void arrayDemo() {
        int[] arr = new int[5]; // default value is [0, 0, 0, 0, 0]
        // printArray(arr);

        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        printArray(arr); // [10, 20, 30, 40, 50]

        // update value at index 2
        arr[2] = 100;
        printArray(arr); // [10, 20, 100, 40, 50]

        /*
         * //insert value at index 5 (not in the array)
         * arr[5] = 60;
         * printArray(arr); //ArrayIndexOutOfBoundsException: Index 5 out of bounds for
         * length 5
         */

        // length of array
        System.out.println("Length of array: " + arr.length);

        //last element
        System.out.println("Last element: " + arr[arr.length - 1]);

        //first element
        System.out.println("First element: " + arr[0]);
    }

    public static void main(String[] args) {
        P2_ArrayUtil obj = new P2_ArrayUtil();
        obj.arrayDemo();
    }
}
