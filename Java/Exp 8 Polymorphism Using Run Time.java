class Car {
  void run() {
    System.out.println("running");
  }
}
class Innova extends Car {
  void run() { // Removed semicolon here
    System.out.println("running fast at 120km");
  }
  public static void main(String args[]) {
    Car c = new Innova(); // Changed innova to Innova
    (Java is casesensitive)
    c.run();
  }
}

//-----------------------------------------------------------------------
class Animal {
  void eat() {
    System.out.println("Animals Eat");
  }
}
class Herbivores extends Animal {
  void eat() {
    System.out.println("Herbivores Eat Plants");
  }
}
class Omnivores extends Animal {
  void eat() {
    System.out.println("Omnivores Eat Plants and meat");
  }
}
class Carnivores extends Animal {
  void eat() {
    System.out.println("Carnivores Eat meat");
  }
}
class Main {
  public static void main(String args[]) {
    Animal A = new Animal();
    Animal h = new Herbivores(); //upcasting
    Animal o = new Omnivores(); //upcasting
    Animal c = new Carnivores(); //upcasting
    A.eat();
    h.eat();
    o.eat();
    c.eat();
  }
}
