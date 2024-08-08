import java.io.FileOutputStream;

//Use to write a byte into a file

public class U6_Practice_FileOutputStream_1 {
    public static void main(String[] args) {
        try{
            FileOutputStream fos = new FileOutputStream("D:\\testout.txt");
            fos.write(165);
            fos.close();
            System.out.println("Success...");
        }
        catch(Exception e){
            System.out.println("Exception: "+e);
        }
    }
}
