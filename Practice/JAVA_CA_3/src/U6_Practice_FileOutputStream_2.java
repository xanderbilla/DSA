import java.io.FileOutputStream;

//Use to write a String into a file

public class U6_Practice_FileOutputStream_2 {
    public static void main(String[] args) {
        try{
            FileOutputStream fos = new FileOutputStream("D:\\testout.txt");
            String s = "Smile you're in LPU!";

            byte[] b = s.getBytes();//converting string into byte array
            
            fos.write(b);
            fos.close();
            System.out.println("Success...");
        }
        catch(Exception e){
            System.out.println("Exception: "+e);
        }
    }
}
