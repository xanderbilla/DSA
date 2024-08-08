class IllegalStateExc{
    public static void main(String[] args) {
       //Illegal State Exception
        String str = "Hello World!";
        try {
            str = str.substring(6, 5);
        } catch (Exception e) {
            System.out.println("Illegal State Exception: " + e);
        }
    }
}