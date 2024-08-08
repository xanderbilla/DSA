//Multiple Catch block

class MultiCatchBlock{
    public static void main(String[] args) {
        try{
            int arr[] = new int[5];
            arr[5] = 10/0;
            System.out.println(arr[10]);

        }
        catch(ArithmeticException e){
            System.out.println("Arithmetic Exception occurs");
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ArrayIndexOutOfBounds Exception occurs");
        }
        catch(Exception e){
            System.out.println("Parent Exception occurs");
        }
        System.out.println("Rest of the code");
    }
}