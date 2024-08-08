package com.xander.UNIT_6_Generics;

import java.util.ArrayList;

public class P06_SingleParamFun<T> {
    T a;

    public void add(T var) {
        ArrayList<T> arr = new ArrayList<T>();
        arr.add(var);
        System.out.println(arr);
    }
}