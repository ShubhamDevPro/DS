// i) Right Triangle Alphabetic Pattern
public class Exp_4_iii_a {
  public static void main(String[] args) {
    int alphabet = 65; //ASCII value of capital A is 65
    //inner loop for rows
    for (int i = 0; i <= 8; i++) {
      //outer loop for columns
      for (int j = 0; j <= i; j++) {
        //adds the value of j in the ASCII value of A and prints the corresponding alphabet
        System.out.print((char)(alphabet + j) + " ");
      }
      System.out.println();
    }
  }
}

// ------------------------------------------------------------------
// ii) Repeating Alphabet Pattern
public class Exp_4_iii_b {
  public static void main(String[] args) {
    int letter = 65; //ASCII value of capital A is 65
    //inner loop for rwos
    for (int i = 0; i <= 9; i++) {
      //outer loop for columns
      for (int j = 0; j <= i; j++) {
        //prints the character
        System.out.print((char) letter + " ");
      }
      letter++;
      System.out.println();
    }
  }
}
///-------------------------------------------------------------------------
/// iii) K - Shape Alphabet Pattern
public class Exp_4_iii_c {
  public static void main(String[] args) {
    for (int i = 8; i >= 0; i--) {
      int alphabet = 65;
      for (int j = 0; j <= i; j++) {
        System.out.print((char)(alphabet + j) + " ");
      }
      System.out.println();
    }
    for (int i = 0; i <= 8; i++) {
      int alphabet = 65;
      for (int j = 0; j <= i; j++) {
        System.out.print((char)(alphabet + j) + " ");
      }
      System.out.println();
    }
  }
}

// ----------------------------------------------------------------------------
// iv) Triangle Character Pattern
public class Exp_4_iii_c {
  public static void main(String[] args) {
    for (int i = 8; i >= 0; i--) {
      int alphabet = 65;
      for (int j = 0; j <= i; j++) {
        System.out.print((char)(alphabet + j) + " ");
      }
      System.out.println();
    }
    for (int i = 0; i <= 8; i++) {
      int alphabet = 65;
      for (int j = 0; j <= i; j++) {
        System.out.print((char)(alphabet + j) + " ");
      }
      System.out.println();
    }
  }
}
