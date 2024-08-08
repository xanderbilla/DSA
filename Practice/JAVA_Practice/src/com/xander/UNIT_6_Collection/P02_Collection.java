package com.xander.UNIT_6_Collection;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class P02_Collection {

    /* // Notes
     *
     * Collection:
     * 
     *   - Collection is an interface
     *   - It represents a group of objects known as its elements. For example, a list of integers.
     * 
     * Collections:
     *   - Collections is a class
     *   - Java Collections Framework provides a standard way to handle a group of objects.
     *   - Collection framework is a class that provides an architecture to store and manipulate the group of objects.
     * 
     * Collection (I)
     *      |
     *      + List (I)
     *      |
     *      + Set (I)
     *      |
     *      + Queue (I)
     * 
     * Common methods of Collection interface:
     * 
     *      + add(Object o): Appends the specified element to the end of the list.
     *      + addAll(Collection c): Appends all of the elements in the specified collection to 
     *        the end of this list, in the order that they are returned by the specified collection's iterator.
     *      
     *      + remove(): Removes the first occurrence of the specified element from the list.
     *      + removeAll(Collection c): Removes all of the elements from the list that are present in 
     *        the specified collection.
     * 
     *      + clear(): Removes all of the elements from the list.
     *      + isEmpty(): Returns true if the list is empty.
     *      + size(): Returns the number of elements in the list.
     *      + contains(Object o): Returns true if the list contains the specified element.
     *      + containsAll(Collection c): Returns true if the list contains all of the elements in the specified collection.
     */

    public void arrayListDisplay() {
        /*
         * List:
         *      - List is an interface
         *      - Insertion order is preserved
         *      - It is an ordered collection of objects in which duplicate values can be stored.
         *      - Duplicate values can be stored.
         *      - List interface is implemented by ArrayList, LinkedList, Vector, and Stack classes.
         *
         *  
         *  List (I)
         *      |
         *      + ArrayList (C)
         *      |
         *      + LinkedList (C) #goto linkedListDisplay()
         *      |
         *      + Vector (C)
         *      |
         *      + Stack (C)
         * 
         * ArrayList and operations:
         *      - ArrayList is a class
         *      - It is a class that provides a resizable array and implements the List interface.
         *      - It is an ordered collection of objects in which duplicate values can be stored.
         *      - ArrayList maintains the insertion order and is non-synchronized.
         *      - In ArrayList, manipulation is fast because no shifting is required.
         *  
         * Note: 
         *      - When we create an array List, it creates an array of size 10 by default.
         *      - When the array is full, it creates a new array of size (old capacity * 3/2) + 1.
         *      - And the old array is copied to the new array.
         *      - And the ArrayList point to the new array. Meanwhile the old array is garbage collected.
        -*      - We can pass the initial capacity of the ArrayList as an argument to the constructor.
                 List<Integer> l2 = new ArrayList<>(20);
         * 
         * ArrayList methods: 
         *      + add(int index, Object element): Inserts the specified element at the specified 
         *        position in the list.
         *      + addAll(int index, Collection c): Inserts all of the elements in the specified
         *      + remove(int index): Removes the element at the specified position in the list.
         *      + get(int index): Returns the element at the specified position in the list.
         *      + set(int index, Object element): Replaces the element at the specified position in 
         *        the list with the specified element.
         *      + indexOf(Object o): Returns the index of the first occurrence of the specified element in the list.
         *      + lastIndexOf(Object o): Returns the index of the last occurrence of the specified element in the list.
         * 
         */

        List<Integer> l1 = new ArrayList<>();
        l1.add(100);
        l1.add(200);
        l1.add(300); 
        List<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);
        list.addAll(l1); // add all elements of l1 to list
        
        System.out.println("List : " + list);
        System.out.println("List Size: " + list.size());
        System.out.println("List Empty: " + list.isEmpty());
        System.out.println("List contains 10: " + list.contains(10));

        //remove elements from list
        list.remove(2);
        list.removeAll(l1);

        //remove by value
        list.remove(list.indexOf(20));

        //get element by index
        System.out.println("List : " + list);   
        System.out.println("Element at index 0: " + list.get(0));

        //set element by index
        list.set(0, 11);

        //print all elements using for iterator
        System.out.println("Printing all elements using for iterator");

        Iterator<Integer> it = list.iterator();

        while(it.hasNext()) {
            System.out.println(it.next());
        }
        System.out.println();


        //print all elements using for each loop
        System.out.println("Printing all elements using for each loop");
        for(int i : list) {
            System.out.println(i);
        }
        System.out.println();

        //print all elements using for loop
        System.out.println("Printing all elements using for loop");
        for(int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

    }
    
    public void arrayListUtilDisplay() {
        /*
         * Using collections utility class for additional functionalities such as sort, reverse, etc.
         * 
         * Collections methods:
         * 
         *    + sort(List list): Sorts the list in ascending order.
         *    + binarySearch(List list, Object key): Searches the specified list for the specified object 
         *      using the binary search algorithm.
         *    + max(Collection c): Returns the maximum element in the specified collection.
         *    + min(Collection c): Returns the minimum element in the specified collection.
         *    + frequency(Collection c, Object o): Returns the number of elements in the specified 
         *      collection equal to the specified object.         * 
         *    + reverse(List list): Reverses the order of elements in the list.
         *    + shuffle(List list): Randomly permutes the list.
         *    + swap(List list, int i, int j): Swaps the elements at the specified positions in the list.
         */

         List<Integer> list = new ArrayList<>();
         list.add(23);
         list.add(34);
         list.add(27);
         list.add(52);
         list.add(86);
         list.add(45);
         list.add(49);

        System.out.println("Original list: " + list);


        /*
         * sort the list
         */

         List<Integer> sortedList = new ArrayList<>();
         sortedList.addAll(list);

         Collections.sort(sortedList); // sort the list
         Collections.reverse(sortedList);

        System.out.println("Sorted list: " + sortedList);


        /*
         * Converting existing array to list
         */

          Integer arr[] = { 1, 2, 9, 7, 6 }; //Must be Integer (Wrapper class) not int
 
          List<Integer> arrList = new ArrayList<>(Arrays.asList(arr));
          System.out.println("Array to list: " + arrList);

    }

    public void linkedListDisplay(){

        /*
         * LinkedList and operations:
         *      - LinkedList is a class
         *      - It is a class that provides a linked-list data structure.
         *      - It inherits the AbstractList class and implements List and Deque interfaces.
         *      - It can contain duplicate elements.
         *      - It maintains the insertion order and is not synchronized.
         *      - In LinkedList, the manipulation is fast because no shifting is required.
         * 
         *
         *  LinkedList methods:
         *      + addFirst(Object o): Inserts the specified element at the beginning of the list.
         *      + addLast(Object o): Inserts the specified element at the end of the list.
         *      + getFirst(): Returns the first element in the list.
         *      + getLast(): Returns the last element in the list.
         *      + removeFirst(): Removes the first element from the list.
         *      + removeLast(): Removes the last element from the list.
         *
         */

         LinkedList<Integer> l1 = new LinkedList<>();
         l1.add(100);
         l1.add(0, 200);


         for(int i : l1) {
             System.out.print(i + " -> ");
         }

         System.out.println("NULL");
    }

    public void setDisplay() {
        
        /*
         * Set:
         *      - Set is an interface
         *      - Insertion order is not preserved
         *      - It is an unordered collection of objects in which duplicate values cannot be stored.
         *      - Set interface is implemented by HashSet, LinkedHashSet, and TreeSet classes.
         *      - Insert element by using a concept called Hash code.
         *              * Hash code is a unique identifier for an object.
         *              * It is used to identify an object uniquely.
         *              * It is generated by the JVM based on the object's state.
         *              * It is used to store the elements in the HashSet, LinkedHashSet, and
         *                TreeSet classes.
         *      - Because of Hash code, the retrieval of elements is faster.
         *      - NULL insertion is possible.
         *     
         * Notes:
         *      - The initial capacity of the HashSet is 16 and the load factor (fill ratio) 
         *        is 0.75.
         *      - Once the load factor is reached, the capacity of the HashSet is doubled. i.e,
         *        when 75% of the HashSet is filled, the capacity is doubled. 
         *      - We can pass the initial capacity of the HashSet and load factor as an 
         *        argument to the constructor.
         *        
         *        HashSet<Integer> l2 = new HashSet<>(20);
         * 
         *      - we cannot sort, shuffle, get, or remove elements by index in the Set 
         *        interface. To do this, we need to convert the Set to a List.
         * 
         * Set methods:
         *      + difference(Set s): Returns the difference between the two sets.
         *      + intersection(Set s): Returns the intersection of two sets.
         *      + union(Set s): Returns the union of two sets.
         * 
         * 
         *  Set (I)
         *      |
         *      + HashSet (C)
         *      |
         *      + LinkedHashSet (C)
         *      |
         *      + TreeSet (C)
         * 
         */

         HashSet<Integer> l1 = new HashSet<>();
        l1.add(null);
        l1.add(100);
        l1.add(200);
        l1.add(100);
        l1.add(400);
        l1.add(300);

        System.out.println("Set : " + l1);

        //remove element
        l1.remove(100);
        l1.add(89);
        System.out.println("Set : " + l1);

        //contain
        System.out.println("Set contains 100: " + l1.contains(100));

        //size
        System.out.println("Set size: " + l1.size());

        //isEmpty
        System.out.println("Set empty: " + l1.isEmpty());

        HashSet<Integer> l2 = new HashSet<>();
        HashSet<Integer> l3 = new HashSet<>();

        l2.add(100);
        l2.add(200);
        l2.add(300);
        l2.add(400);
        l2.add(600);

        l3.add(100);
        l3.add(200);
        l3.add(300);
        l3.add(900);

        //union
        l2.addAll(l3);

        //intersection
        l2.retainAll(l3);

        //difference
        l2.removeAll(l3);
    }

    public void queueDisplay() {
        /*
         * Queue:
         *      - Queue is an interface
         *      - It is used to hold the elements about to be processed and provides various operations like the insertion, removal, etc.
         *      - Queue interface is implemented by PriorityQueue, Deque, and ArrayDeque classes.
         * 
         *  Queue (I)
         *      |
         *      + PriorityQueue (C)
         *      |
         *      + Deque (I)
         *      |
         *      + ArrayDeque (C)
         * 
         */
    }

    //Map is independent of Collection interface
    public void mapDisplay() {
        /*
         * Map:
         *      - Map is an interface
         *      - It is not a subtype of the Collection interface.
         *      - It represents a mapping between a key and a value.
         *      - Each key and value pair is known as an entry.
         *      - A Map contains unique keys, but values can be duplicated.
         *      - Map interface is implemented by HashMap, LinkedHashMap, TreeMap, Hashtable, and Properties classes.
         * 
         *  Map (I)
         *      |
         *      + HashMap (C)
         *      |
         *      + LinkedHashMap (C)
         *      |
         *      + TreeMap (C)
         *      |
         *      + Hashtable (C)
         *      |
         *      + Properties (C)
         * 
         */
    }

}
