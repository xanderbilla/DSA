package com.xander;


import com.xander.UNIT_6_Collection.P02_Collection;

// Importing the generic method package
// import com.xander.generic.*; // Importing the generic package

/*
* - Generic introduced in Java 5.0
* - Generic is used with ArrayList, HashMap, HashSet, etc.
* - Three main advantages of using Generics are:
*       + Type Safety: We can hold only a single type of objects in generics. It doesn’t allow to store other objects.
*       + Type Casting is not required: There is no need to typecast the object.
*       + Compile-Time Checking: It is checked at compile time so the problem will not occur at runtime.
*/

public class Test { 
   public static void main(String[] args) {
      
      P02_Collection obj = new P02_Collection();
      obj.setDisplay();

   }
}
