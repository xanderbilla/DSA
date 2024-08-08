import java.io.BufferedReader;
import java.io.FileReader;

public class ExcChecked {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("file.txt");
            BufferedReader br = new BufferedReader(fr);

            for (int i = 0; i < 3; i++) {
                System.out.println(br.readLine());
            }

            br.close();
        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
}
