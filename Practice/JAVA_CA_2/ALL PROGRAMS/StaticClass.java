// package Practice.JAVA_U3_U4.ALL PROGRAMS;

class A{
    class B{
        void display(){
            System.out.println("Yohohoho");
        }
    }
}

public class StaticClass {
    public static void main(String[] args) {
        // A obj1 = new A();
        // A.B obj2 = new A.B(); //static class object creation

        // obj2.display();

        A obj1 = new A();
        A.B obj2 = obj1.new B(); //non-static class object creation

            

        obj2.display();
    }
}
