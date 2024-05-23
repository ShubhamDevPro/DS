Exp 4 B) Number Pattern
  i) Incremental Number Pattern

  public class EXP_4_ii_a {
  public static void main(String args[]) {
    int i, j, number, n = 7;
    //loop for rows
    for (i = 0; i < n; i++) {
      number = 1;
      //loop for columns
      for (j = 0; j <= i; j++) {
        //prints num
        System.out.print(number + " ");
        //incrementing the value of number
        number++;
      }
      //throws the cursor at the next line after
      printing each row
      System.out.println();
    }
  }
}

// ---------------------------------------------------------------------------------------------
// ii) K Shape Number Pattern
public class EXP_4_ii_b {
  public static void main(String[] args) {
    int i, j, rows = 9;
    //Prints upper half pattern
    for (i = rows; i >= 1; i--) {
      for (j = 1; j <= i; j++) {
        System.out.print(j + " ");
      }
      System.out.println();
    }
    //Prints lower half pattern
    for (i = 2; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
        System.out.print(j + " ");
      }
      System.out.println();
    }
  }
}

// --------------------------------------------------------------------------------------------
//iii) Triangular Number Pattern
import java.util.*;
public class Exp_4_ii_c {
  public static void main(String[] args) {
    int i, j, rows;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of rows you want to print: ");
    rows = sc.nextInt();
    for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}
// -----------------------------------------------------------------------------------------
// iv) Pyramidal Number Pattern
public class Exp_4_ii_d {
  public static void main(String[] args) {
    for (int i = 1; i <= 4; i++) {
      int n = 8;
      for (int j = 1; j <= n - i; j++) {
        System.out.print(" ");
      }
      for (int k = i; k >= 1; k--) {
        System.out.print(k);
      }
      for (int l = 2; l <= i; l++) {
        System.out.print(l);
      }
      System.out.println();
    }
    for (int i = 3; i >= 1; i--) {
      int n = 7;
      for (int j = 0; j <= n - i; j++) {
        System.out.print(" ");
      }
      for (int k = i; k >= 1; k--) {
        System.out.print(k);
      }
      for (int l = 2; l <= i; l++) {
        System.out.print(l);
      }
      System.out.println();
    }
  }
}
