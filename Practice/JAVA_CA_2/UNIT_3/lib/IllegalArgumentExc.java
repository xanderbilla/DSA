public class IllegalArgumentExc {

    void checkArgument(int a) {
        if (a >= 18){
            System.out.println("You are an adult");
        }else{
            throw new IllegalArgumentException("You're a kid yet!");
        }
    }

    public static void main(String[] args) {
        IllegalArgumentExc exc = new IllegalArgumentExc();
        exc.checkArgument(17);
    }
}
