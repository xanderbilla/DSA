import java.io.FileInputStream;

//Use to write a String into a file

public class U6_Practice_FileInputStream_1 {
    public static void main(String[] args) {
        int i;
        try{
            FileInputStream fin = new FileInputStream("D:\\testout.txt");
            
            // default value of fin.read is -1 
            i = fin.read();
            System.out.println((char)i);
            fin.close();
            System.out.println("\n\nFile read successfully...");
        }
        catch(Exception e){
            System.out.println("Exception: "+e);
        }
    }
}