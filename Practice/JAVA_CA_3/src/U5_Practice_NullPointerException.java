public class U5_Practice_NullPointerException {
    public static void main(String[] args) {
        //Null Pointer Exception
        try{
            String str = null;
            System.out.println(str.length());
        }catch(NullPointerException e){
            System.out.println("Exception: "+e);
        }
    }
}
