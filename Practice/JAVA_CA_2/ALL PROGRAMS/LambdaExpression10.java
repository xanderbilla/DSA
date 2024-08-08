//Java lambda expression can be used in the collection framework.
// It provides efficient and concise way to iterate, filter and fetch data.
// Following are some lambda and collection examples provided.

//Java Lambda Expression Example: Comparator
import java.util.ArrayList;  
import java.util.Collections;  
import java.util.List;  

class Product{  
    int id;  
    String name;  
    float price;  
    public Product(int id, String name, float price) {  
        super();  
        this.id = id;  
        this.name = name;  
        this.price = price;  
    }  
}  
public class LambdaExpression10{  
    public static void main(String[] args) {  
        List<Product> list=new ArrayList<Product>();  
          
        //Adding Products  
        list.add(new Product(3,"Pawan Salary",25000f));  
        list.add(new Product(2,"Daman Salary",30000f));  
        list.add(new Product(1,"Aman Salary",15000f));  
          
        System.out.println("Sorting on the basis of name...");  
  
        // implementing lambda expression  
        Collections.sort(list,(p1,p2)->{  
        return p1.name.compareTo(p2.name);  
        });  
        for(Product p:list){  
            System.out.println(p.id+" "+p.name+" "+p.price);  
        }  
  
    }  
}  