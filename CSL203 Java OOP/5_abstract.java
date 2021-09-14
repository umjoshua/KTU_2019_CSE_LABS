/*To implement a Java program to create an abstract class 
named Shape that contains an empty method named numberOfSides( ). 
Provide three classes named Rectangle, Triangle and Hexagon such that each one 
of the classes extends the class Shape. Each one of the classes contains only the 
method numberOfSides( ) that shows the number of sides in the given geometrical structures.*/
abstract class Shape{
    abstract void numberOfSides();
     }
   class Rectangle extends Shape {
     void numberOfSides() {
       System.out.println("Rectangle has 4 sides");
     }
   }
   class Triangle extends Shape {
     void numberOfSides() {
       System.out.println("Triangle has 3 sides");
     }
   }
   class Hexagon extends Shape {
     void numberOfSides() {
       System.out.println("Hexagon has 6 sides");
     }
   }
   class 5_abstract{
     public static void main(String[] args){
         Rectangle rect = new Rectangle();
         Triangle tri = new Triangle();
         Hexagon hex = new Hexagon();
         rect.numberOfSides();
         tri.numberOfSides();
         hex.numberOfSides();
     }
   }