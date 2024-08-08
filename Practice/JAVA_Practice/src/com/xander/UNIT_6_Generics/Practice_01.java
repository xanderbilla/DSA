package com.xander.UNIT_6_Generics;

/*
* Write a Java program to create a generic method that takes two arrays of the same type and checks if they 
* have the same elements in the same order
*/

public class Practice_01{
    public <T> boolean compareArr(T [] List1, T [] List2){
        if(List1.length != List2.length){
            return false;
        }
        for(int i = 0; i < List1.length; i++){
            if(!List1[i].equals(List2[i])){
                return false;
            }
        }
        return true;
    }
}