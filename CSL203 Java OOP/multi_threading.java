/*
To implement a multi-threaded java program which has three threads.
First thread generates a random integer every 1 second. If the value is even, 
second thread computes the square of the number and prints. If the value is odd 
the third thread will print the value of cube of the number.
*/
import java.util.Random;
class Square extends Thread{
	int x;
	Square(int n){
		x=n;
	}
	public void run(){
		try{
			Thread.currentThread().setName("Square");
			int sq = x * x;
			System.out.println(Thread.currentThread().getName() + " is running");
			System.out.println("Square of " + x + " = " + sq);
			Thread.sleep(500);
		}
		catch(InterruptedException e){
			System.out.println("Main Thread Interrupted");
		}
		System.out.println("Square Exiting..\n");
	}
}

class Cube extends Thread{
	int x;
	Cube(int n){
		x = n;
	}
	public void run(){
		try{
			Thread.currentThread().setName("Cube");
			int cub = x * x * x;
			System.out.println(Thread.currentThread().getName() + " is running");
			System.out.println("Cube of " + x + " = " + cub);
			Thread.sleep(500);
		}
		catch(InterruptedException e){
			System.out.println("Main Thread Interrupted");
		}
		System.out.println("Cube Exiting..\n");
	}
}
class Number extends Thread{
	public void run(){
		Thread.currentThread().setName("Random Integer");
		System.out.println(Thread.currentThread().getName() + " is running");
		Random random = new Random();
		for(int i=0;i<5;i++){
			int randomInteger = random.nextInt(50);
			System.out.println("Random integer Generated: " +  randomInteger);
			if(randomInteger % 2==0){
				Square sqr = new Square(randomInteger);
				sqr.start();
			}
			else{
				Cube cub = new Cube(randomInteger);
				cub.start();
			}
			try{
				Thread.sleep(1000);
			}
			catch(InterruptedException e){
				System.out.println("Main Thread Interrupted");
			}
		}
	}
}	
public class multi_threading{
	public static void main(String[] args){
		Number n = new Number();
		n.start();
		try{
			 n.join();  
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println("Main Thread exiting");
	}
}