public class IndexOutOfBoundExc {
    public static void main(String[] args) {
        // Index out of bound exception

        int[] arr = {1, 2, 3, 4, 5};

        try {
            System.out.println(arr[10]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Index out of bound");
        }
    }
}
