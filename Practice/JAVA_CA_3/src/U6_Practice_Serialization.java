import java.io.*;

class Student implements Serializable {
    int id;
    String name;
    int age;

    Student(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }
}

public class U6_Practice_Serialization {

/*
 * Serialization in Java is a mechanism of writing the state of an object into a byte stream.
 * It is mainly used to travel object's state on the network (known as marshalling).
 * 
 * To perform serialization, we have to implement the Serializable interface.
 * It is a marker interface.
 * 
 * The ObjectOutputStream class is used to write primitive data types and Java objects to an OutputStream.
 * 
 * The FileOutputStream class is used to write data to a file.
 * 
 */

    public static void main(String[] args) {
        try {
            Student s1 = new Student(211, "ravi", 22); 

            FileOutputStream fout = new FileOutputStream("D:\\f_Student.txt");
            ObjectOutputStream out = new ObjectOutputStream(fout);

            out.writeObject(s1);

            out.flush();
            out.close();

            System.out.println("Success...");

        } catch (Exception e) {
            System.out.println(e);
        }
    }    
}
