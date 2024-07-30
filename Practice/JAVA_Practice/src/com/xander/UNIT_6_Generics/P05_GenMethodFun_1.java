package com.xander.UNIT_6_Generics;

/*
 * - Generic method is a method that is declared with type parameters.
 * - It is a method that can operate on a parameterized type.
 * - The type parameter (also called type variable) is a placeholder for a type (class).
 * 
 * - Syntax:
 *      + <T> returnType methodName(T t) { }
 * 
 * - <T> is a type parameter that is used to create a generic method.
 * - T is a type parameter that is used to create a generic class.
 * 
 */

public class P05_GenMethodFun_1 {
    public <T> void genericDisplay(T element) {
        System.out.println(element.getClass().getName() + 
        " = " + element);
    }
}