//Java Nested Static Class
//We use the keyword static to make our nested class static.

//Note: In Java, only nested classes are allowed to be static.

//Like regular classes, static nested classes can include both static and non-static fields and methods. For example,

//Class Animal {
 //  static class Mammal {
      // static and non-static members of Mammal
//   }
   // members of Animal
//} 

class Animal {

// inner class
   class Reptile {
      public void displayInfo() {
        System.out.println("I am a Engg.");
      }
   }

// static class
   static class Mammal {
      public void displayInfo() {
        System.out.println("I am a Person.");
      }
   }
}

class NestStatic {
   public static void main(String[] args) {
      // object creation of the outer class
      Animal animal = new Animal();

      // object creation of the non-static class
      Animal.Reptile reptile = animal.new Reptile();
      reptile.displayInfo();

      // object creation of the static nested class
      Animal.Mammal mammal = new Animal.Mammal();
      mammal.displayInfo();

   }
}