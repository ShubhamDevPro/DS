Write a program to print the Star, Number and
Character pattern using Java packages
(A) Star Pattern
 // i) Pyramidal Pattern


public class Main {
  public static void main(String args[]) {
    //i for rows and j for columns
    //row denotes the number of rows you want to print
    int i, j, row = 6;
    //Outer loop work for rows
    for (i = 0; i < row; i++) {
      //inner loop work for space
      for (j = row - i; j > 1; j--) {
        //prints space between two stars
        System.out.print(" ");
      }
      //inner loop for columns
      for (j = 0; j <= i; j++) {
        //prints star
        System.out.print("* ");
      }
      //throws the cursor in a new line after printing each line
      System.out.println();
    }
  }
}


//// ii) Diamond Shape Pattern

import java.util.Scanner;
public class Experiment_4_B {
  public static void main(String args[]) {
    int row, i, j, space = 1;
    System.out.print("Enter the number of rows you want
      to print: ");
      Scanner sc = new Scanner(System.in); row = sc.nextInt(); space = row - 1;
      for (j = 1; j <= row; j++) {
        for (i = 1; i <= space; i++) {
          System.out.print(" ");
        }
        space--;
        for (i = 1; i <= 2 * j - 1; i++) {
          System.out.print("*");
        }
        System.out.println("");
      }
      space = 1;
      for (j = 1; j <= row - 1; j++) {
        for (i = 1; i <= space; i++) {
          System.out.print(" ");
        }
        space++;
        for (i = 1; i <= 2 * (row - j) - 1; i++) {
          System.out.print("*");
        }
        System.out.println("");
      }
    }
  }

/// iii) SandGlas Star Pattern

import java.util.Scanner;
public class EXPERIMENT_4_C {
  public static void main(String[] args) {
    int i, j, k, n;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of rows you want to print: ");
    n = sc.nextInt();
    for (i = 0; i <= n - 1; i++) {
      for (j = 0; j < i; j++) {
        System.out.print(" ");
      }
      for (k = i; k <= n - 1; k++) {
        System.out.print("*" + " ");
      }
      System.out.println("");
    }
    for (i = n - 1; i >= 0; i--) {
      for (j = 0; j < i; j++) {
        System.out.print(" ");
      }
      for (k = i; k <= n - 1; k++) {
        System.out.print("*" + " ");
      }
      System.out.println("");
    }
    sc.close();
  }
}

/// iv) Right Pascal Triangle 
import java.util.Scanner;
public class EXPERIMENT_4_D {
  public static void main(String[] args) {
    int i, j, rows;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of rows you want to print: ");
    rows = sc.nextInt();
    for (i = 0; i <= rows - 1; i++) {
      for (j = 0; j <= i; j++) {
        System.out.print("*" + " ");
      }
      System.out.println("");
    }
    for (i = rows - 1; i >= 0; i--) {
      for (j = 0; j <= i - 1; j++) {
        System.out.print("*" + " ");
      }
      System.out.println("");
    }
  }
}
