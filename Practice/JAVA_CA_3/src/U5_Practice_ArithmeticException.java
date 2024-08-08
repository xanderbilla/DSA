//Arithemetic Exception

class U5_Practice_ArithmeticException{
    public static void main(String[] args) {
        try{
            int a = 10;
            int b = 0;
            int c = a/b;
            System.out.println("Result: "+c);
        }catch(ArithmeticException e){
            System.out.println("Exception: "+e);
        }
    }
}