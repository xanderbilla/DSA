//Java Nested Interface
//An interface, i.e., declared within another interface or class,
// is known as a nested interface. The nested interfaces are used to group
// related interfaces so that they can be easy to maintain.
// The nested interface must be referred to by the outer interface or class. 
//It can't be accessed directly.


interface Showable{  
  void show();  
  interface Message{  
   void msg();  
  }  
}  
class TestNestedInterface1 implements Showable.Message{  
 public void msg(){System.out.println("Hello nested interface");}  
  
 public static void main(String args[]){  
  Showable.Message message=new TestNestedInterface1();//upcasting here  
  message.msg();  
 }  
}  

