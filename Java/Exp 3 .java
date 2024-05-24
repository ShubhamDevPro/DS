Aim- Write a program to use the Java Operators
(A) Arithmetic Operators
class Main {
  public static void main(String[] args) {
    // declare variables
    int a = 12, b = 5;
    // addition operator
    System.out.println("a + b = " + (a + b));
    // subtraction operator
    System.out.println("a - b = " + (a - b));
    // multiplication operator
    System.out.println("a * b = " + (a * b));
    // division operator
    System.out.println("a / b = " + (a / b));
    // modulo operator
    System.out.println("a % b =" + (a % b));
  }
}
//------------------------------------------------------------------------
(B) Assignment Operators
class Main {
  public static void main(String[] args) {
    // create variables
    int a = 4;
    int
    var;
    // assign value using =
    var = a;
    System.out.println("var using =: " +
      var);
    // assign value using =+
    var += a;
    System.out.println("var using +=: " +
      var);
    // assign value using =*
    var *= a;
    System.out.println("var using *=: " +
      var);
  }
}
//---------------------------------------------------------------
(C) Relational Operators
class Main {
  public static void main(String[] args) {
    // create variables
    int a = 7, b = 11;
    // value of a and b
    System.out.println("a is " + a + " and b is " + b);
    // == operator
    System.out.println(a == b); // false
    // != operator
    System.out.println(a != b); // true
    // > operator
    System.out.println(a > b); // false
    // < operator
    System.out.println(a < b); // true
    // >= operator
    System.out.println(a >= b); // false
    // <= operator
    System.out.println(a <= b); // true
  }
}
// ----------------------------------------------------------------

(D) Java Unary Operators
class Main {
  public static void main(String[] args) {
    // declare variables
    int a = 12, b = 12;
    int result1, result2;
    // original value
    System.out.println("Value of a: " + a);
    // increment operator
    result1 = ++a;
    System.out.println("After increment: " + result1);
    System.out.println("Value of b: " + b);
    // decrement operator
    result2 = --b;
    System.out.println("After decrement: " + result2);
  }
}
