/* Java program to find the frequency of a given character in a string */
import java.util.Scanner;
public class frequency{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a string to check frequency : ");
		String word=sc.nextLine();
		System.out.println("Enter the character to find the frequency : ");
		char a=sc.next().charAt(0);
		int freq=0;
		for(int i=0;i<word.length();i++){
			if(a==word.charAt(i)){
				++freq;
				}
			}
		System.out.println("Frequency of "+a+" is "+freq);
		}
}