/*
To implement a Java program that shows thread synchronization
in which two threads prints the multiplication table.
*/
class NumTable{
	synchronized static void printTable(int n){
		System.out.println(Thread.currentThread().getName());
		for(int i = 1;i<=10;i++){
			System.out.println(" "+n+" x "+i+" = "+n*i);
			try{
				Thread.sleep(500);
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
		System.out.println();
	}
}
class One extends Thread{
	public void run(){
		Thread.currentThread().setName("Multiplication Table of 2");
		NumTable.printTable(2);
	}
}
class Two extends Thread{
	public void run(){
		Thread.currentThread().setName("Multiplication Table of 3");
		NumTable.printTable(3);
	}
}

public class thread_sync{
	public static void main(String[] args){
		One o1 = new One();
		Two o2 = new Two();
		o1.start();
		o2.start();
		try{
			o1.join();
			o2.join();
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println("Main thread exiting..." );
	}
}