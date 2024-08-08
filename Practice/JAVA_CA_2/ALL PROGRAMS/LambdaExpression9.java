//.Java Lambda Expression Example: Creating Thread
//You can use lambda expression to run thread. In the following example,
//.. we are implementing run method by using lambda expression.

public class LambdaExpression9{  
    public static void main(String[] args) {  
      
        //Thread Example without lambda  
        Runnable r1=new Runnable(){  
            public void run(){  
                System.out.println("Thread1 is printing first..");  
            }  
        };  
        Thread t1=new Thread(r1);  
        t1.start();  
        //Thread Example with lambda  
        Runnable r2=()->{  
                System.out.println("Thread2 is printing second..");  
        };  
        Thread t2=new Thread(r2);  
        t2.start();  
    }  
}  