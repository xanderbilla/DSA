public class U5_Practice_ClassNotFoundException {
    public static void main(String[] args) {
        //Class Not Found Exception
        try{
            Class.forName("vikas");
        }catch(ClassNotFoundException e){
            System.out.println("Exception: "+e);
        }
    }
}
