// package Practice.JAVA_U3_U4.ALL PROGRAMS;

public class AnonymousClass {
    public static void main(String[] args) {
        Electronics e = new Electronics(){
            public void offGadget(){
                System.out.println("Gadget is off");
            }

            public void onGadget(){
                System.out.println("Gadget is on");
            }
        };

        e.onGadget();
        e.offGadget();
    }

    interface Electronics{
        void onGadget();
        void offGadget();
    }
}


