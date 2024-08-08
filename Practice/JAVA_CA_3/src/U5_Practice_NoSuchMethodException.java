public class U5_Practice_NoSuchMethodException {
    public static void main(String[] args) {
        //Method Not Found Exception
        try{
            Class.forName("vikas").getMethod("hello");
        }catch(ClassNotFoundException | NoSuchMethodException e){
            System.out.println("Exception: "+e);
        }   
    }
}
