public class ExcClassNotFound {
    public static void main(String[] args) {
        //Class Not Found Exception
        try {
            Class.forName("class1");
        } catch (ClassNotFoundException e) {
            System.out.println("Class Not Found ...");
        }
    }
}
