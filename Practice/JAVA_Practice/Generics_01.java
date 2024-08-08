/*
* - Generic introduced in Java 5.0
* - Generic is used with ArrayList, HashMap, HashSet, etc.
* - Three main advantages of using Generics are:
*       + Type Safety: We can hold only a single type of objects in generics. It doesn’t allow to store other objects.
*       + Type Casting is not required: There is no need to typecast the object.
*       + Compile-Time Checking: It is checked at compile time so the problem will not occur at runtime.
*/

import java.util.ArrayList;

class GenArray {
    public void ArrGen() {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        System.out.println(arr);
    }
}

// single parameter
class SingleParamFun<T> {
    T a;

    void add(T var) {
        ArrayList<T> arr = new ArrayList<T>();
        arr.add(var);
        System.out.println(arr);
    }
}

// multiple parameter
class MultipleParamFun<T, U> {
    T a;
    U b;

    void add(T var1, U var2) {
        ArrayList<T> arr1 = new ArrayList<T>();
        ArrayList<U> arr2 = new ArrayList<U>();
        arr1.add(var1);
        arr2.add(var2);
        System.out.println(arr1);
        System.out.println(arr2);
    }

    void show(T t, U u) {
        System.out.println(t + " " + u);
    }
}

public class Generics_01 {

    public static void main(String[] args) {

        // // GenArray
        // GenArray obj = new GenArray();
        // obj.ArrGen();

        // // Fun
        // SingleParamFun<Integer> obj1 = new SingleParamFun<Integer>();
        // SingleParamFun<String> obj2 = new SingleParamFun<String>();

        // obj1.add(10);
        // obj2.add("Mukehsh");

        //MultipleParamFun
        MultipleParamFun<Integer, String> obj = new MultipleParamFun<Integer, String>();
        obj.show(10, "Mukesh");

    }
}