public class NullPtrExcetion {
    public static void main(String[] args) {
        try {
            String str = null;
            System.out.println(str.length());
        } catch (NullPointerException e) {
            System.out.println("Exception caught: " + e);
            System.out.println("Exception message: " + e.getMessage());
        }
    }
}

/*
 * Output:
 * Exception caught: java.lang.NullPointerException
 * Exception message: null
 */