interface Arithmetic{
    int sum(int a, int b);
}

class LambdaExpression1{

    // void sum (int a, int b){
    //     System.out.println("Sum of a and b is: "+(a+b));
    // }

    public static void main(String[] args) {
       Arithmetic a = (n1, n2) -> n1 + n2;
    System.out.println(a.sum(10, 20));
    }

}