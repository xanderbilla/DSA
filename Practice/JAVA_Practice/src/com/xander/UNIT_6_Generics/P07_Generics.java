package com.xander.UNIT_6_Generics;

import java.util.*;

/*  Create a generic class DataHolder that can hold a single value of any data type. 
*   
*   It should have the following methods:
*   
*   DataHolder(T data): A constructor that takes the initial data value.
*   T getData(): A method that returns the stored data value.
*   void setData(T data): A method that sets the stored data value.
*   Bonus:
*   
*   Implement a static method swapData within the DataHolder class that takes two DataHolder objects as 
*   arguments and swaps their data values. Ensure type safety is maintained throughout the process. 
*/

class DataHolder<T>{
    T data;

    public DataHolder(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public static <T> void swapData(DataHolder<T> d1, DataHolder<T> d2) {
        T temp = d1.data;
        d1.data = d2.data;
        d2.data = temp;
    }
}


//generic class for adding two number
class Calc<T extends Number>{
    public T addCalc(T a, T b) throws ClassCastException{
        if (a instanceof Integer) {
            return (T) Integer.valueOf(a.intValue() + b.intValue());
        } else if (a instanceof Double) {
            return (T) Double.valueOf(a.doubleValue() + b.doubleValue());
        } else if (a instanceof Float) {
            return (T) Float.valueOf(a.floatValue() + b.floatValue());
        } else if (a instanceof Long) {
            return (T) Long.valueOf(a.longValue() + b.longValue());
        } else {
            return null;
        }
    }
}

public class P07_Generics {

    public void display() {

        Calc<Integer> calc = new Calc<>();
        System.out.println(calc.addCalc(10, 20));

    }

}
