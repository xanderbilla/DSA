import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

//Use to write a String into a file
/*
 * BufferedOutputStream is used to provide buffering for OutputStreams. 
 * It makes the performance fast.
 */
public class U6_Practice_BufferedStream_1 {
    public static void main(String[] args) {
        try {
            FileOutputStream fout = new FileOutputStream("D:\\testout.txt");
            BufferedOutputStream bout = new BufferedOutputStream(fout);
            String s = "Smile you're in LPU.";
            byte b[] = s.getBytes();

            bout.write(b); // write the string into the file
            bout.flush();  // flush the stream
            bout.close();  // close the stream
            fout.close();  
            System.out.println("Success...");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}