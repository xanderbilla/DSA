import java.util.Scanner;

public class IOException {
    public static void main(String[] args) {
        //IO Exception
        Scanneo sc = new Scanner("Hello World!");
        try {
            String str = sc.nextLine();
            System.out.println("" + str);
        } catch (Exception e) {
            System.out.println("IO Exception: " + sc.ioException());
        }
        sc.close();
    }
}
