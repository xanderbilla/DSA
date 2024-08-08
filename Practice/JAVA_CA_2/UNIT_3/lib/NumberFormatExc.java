public class NumberFormatExc{
    public static void main(String[] args) {
        // Numberformat Exception

        int num = 0;

        // num = Integer.parseInt("123");
        // System.out.println("Number: " + num);


        try {
            num = Integer.parseInt("akk");
            System.out.println("Number: " + num);
        } catch (NumberFormatException e) {
            System.out.println("Invalid Number");
        }
    }
}