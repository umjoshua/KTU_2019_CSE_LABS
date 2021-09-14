/*To implement a  Java  program  which  creates  a  class  named  'Employee'  
having  the  following members: Name, Age, Phone number, Address, Salary. 
It also has a method named 'printSalary( )' which prints the salary of the Employee. 
Two classes 'Officer' and 'Manager' inherits the 'Employee' class. 
The 'Officer' and 'Manager' classes have data members 'specialization' and 'department' respectively. 
Now, assign name, age, phone number, address and salary to an officer and a manager by 
making an object of both of these classes and print the same.
*/
import java.util.Scanner;
class Employee{
    String Name;
    int Age;
    String Number;
    String Address;
    double Salary;

    Employee(String n,int a,String no,String Ad,double sal){
        Name=n;
        Age=a;
        Number=no;
        Address=Ad;
        Salary=sal;
    }
    
    void printSalary(){
        System.out.println("Salary is : "+Salary);
    }
}
class Officer extends Employee{
    String specialization;
    Officer(String n,int a,String no,String Ad,double sal,String spec){
        super(n,a,no,Ad,sal);
        specialization=spec;
    }
    void printOfficer(){
        System.out.println("");
        System.out.println("***Officer Details***");
        System.out.println("Name : "+Name);
        System.out.println("Specialization : "+specialization);
        System.out.println("Age : "+Age);
        System.out.println("Phone number : "+Number);
        super.printSalary();
        System.out.println("Address : "+Address);
        System.out.println();
    }
}
class Manager extends Employee{
    String department;
    Manager(String n,int a,String no,String Ad,double sal,String dep){
        super(n,a,no,Ad,sal);
        department=dep;
    }
    void printManager(){
        System.out.println("***Manager Details***");
        System.out.println("Name : "+Name);
        System.out.println("Department : "+department);
        System.out.println("Age : "+Age);
        System.out.println("Phone number : "+Number);
        super.printSalary();
        System.out.println("Address : "+Address);
    }
}
class 4_inheritance{
    public static void main(String args[]){
        String name,number,address,spec,dept;
        int age;
        double salary;
        Scanner sc=new Scanner(System.in);
        System.out.println("***Enter officer details***");
        System.out.print("Name : "); name=sc.nextLine();
        System.out.print("Specialization : ");spec=sc.nextLine();
        System.out.print("Phone number: "); number=sc.nextLine();
        System.out.print("Address: "); address=sc.nextLine();
        System.out.print("Age : "); age=sc.nextInt();
        System.out.print("Salary : "); salary=sc.nextDouble();

        Officer one=new Officer(name,age,number,address,salary,spec);
        
        System.out.println("***Enter manager details***");
        sc.nextLine();
        System.out.print("Name : "); name=sc.nextLine();
        System.out.print("Department : "); dept=sc.nextLine();
        System.out.print("Phone number: "); number=sc.nextLine();
        System.out.print("Address: "); address=sc.nextLine();
        System.out.print("Age : "); age=sc.nextInt();
        System.out.print("Salary : "); salary=sc.nextDouble();

        Manager two=new Manager(name,age,number,address,salary,dept);

        one.printOfficer();
        two.printManager();
    }
}