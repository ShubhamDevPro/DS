//A Java class which is a fully encapsulated class.  
//It has a private data member and getter and setter methods.  
package com.javatpoint;
public class Student {
  //private data member  
  private String name;
  //getter method for name  
  public String getName() {
    return name;
  }
  //setter method for name  
  public void setName(String name) {
    this.name = name
  }
}

//----------------------------

//A Java class to test the encapsulated class.  
package com.javatpoint;
class Test {
  public static void main(String[] args) {
    //creating instance of the encapsulated class  
    Student s = new Student();
    //setting value in the name member  
    s.setName("vijay");
    //getting value of the name member  
    System.out.println(s.getName());
  }
}

//------------------------------------------
Read only mode

//A Java class which has only getter methods.  
public class Student {
  //private data member  
  private String college = "AKG";
  //getter method for college  
  public String getCollege() {
    return college;
  }
}
//---------------------------------------
Write only mode

//A Java class which has only setter methods.  
public class Student {
  //private data member  
  private String college;
  //getter method for college  
  public void setCollege(String college) {
    this.college = college;
  }
}
//-----------------------------------
class Account {
  //private data members  
  private long acc_no;
  private String name, email;
  private float amount;
  //public getter and setter methods  
  public long getAcc_no() {
    return acc_no;
  }
  public void setAcc_no(long acc_no) {
    this.acc_no = acc_no;
  }
  public String getName() {
    return name;
  }
  public void setName(String name) {
    this.name = name;
  }
  public String getEmail() {
    return email;
  }
  public void setEmail(String email) {
    this.email = email;
  }
  public float getAmount() {
    return amount;
  }
  public void setAmount(float amount) {
    this.amount = amount;
  }

}
//-------------------------------------------
//A Java class to test the encapsulated class Account.  
public class TestEncapsulation {
  public static void main(String[] args) {
    //creating instance of Account class  
    Account acc = new Account();
    //setting values through setter methods  
    acc.setAcc_no(7560504000 L);
    acc.setName("Sonoo Jaiswal");
    acc.setEmail("sonoojaiswal@javatpoint.com");
    acc.setAmount(500000 f);
    //getting values through getter methods  
    System.out.println(acc.getAcc_no() + " " + acc.getName() + " " + acc.getEmail() + " " + acc.getAmount());
  }
}
