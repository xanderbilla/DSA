package com.xander.UNIT_6_Generics;

import java.util.ArrayList;

public class P03_MultipleParamFun<T, U> {
    T a;
    U b;

    public void add(T var1, U var2) {
        ArrayList<T> arr1 = new ArrayList<T>();
        ArrayList<U> arr2 = new ArrayList<U>();
        arr1.add(var1);
        arr2.add(var2);
        System.out.println(arr1);
        System.out.println(arr2);
    }

    public void show(T t, U u) {
        System.out.println(t + " " + u);
    }
}
