public class U5_Practice_IndexOutOfBound {
    public static void main(String[] args) {
        //IndexOutOfBound Exception

        try{
            int a[] = new int[5];
            a[6] = 9;
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception: "+e);
        }
    }   
}
