/* Write a Java program that read from a file and
write to file by handling all file related exceptions.
*/
import java.util.Scanner;
import java.io.*;
public class file_handling{
	public static void main(String[] args) throws IOException{
		String data; int c;
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter data to file : ");
		data=sc.nextLine();
		FileWriter fw=null;
		FileReader fr=null;
		try{
			fw=new FileWriter("Input.txt");
			for(int i=0;i<data.length();i++)
				fw.write(data.charAt(i));
			System.out.println("Writing completed");
		}
		catch(IOException e){
			System.out.println("Error creating file");	
		}
		finally{
			fw.close();
		}

		boolean flag = false;
		fr=new FileReader("Input.txt");
		System.out.print("Enter the character to find frequency : ");
        char search = sc.next().charAt(0);
		int freq = 0;
		while((c=fr.read())!=-1){
			if((char)c==search){
				freq++;
				flag = true;
			}
		}
		try{
			fr=new FileReader("Input.txt");
			fw=new FileWriter("Output.txt");
			System.out.println("Writing data to Output.txt");
			while((c=fr.read())!=-1)
                fw.write((char)c);
                fw.write("\nFrequency of \""+search+"\" : "+freq);
		}
		catch(FileNotFoundException fe){
			System.out.println("File not found.");
		}
		finally{
			fr.close();
			fw.close();
		}
        try{
			fr=new FileReader("Output.txt");
			System.out.println("Contents of Output.txt file : ");
			while((c=fr.read())!=-1)
				System.out.print((char)c);
			System.out.print("\n");
		}
		catch(FileNotFoundException fe){
			System.out.println("File not found.");
		}
		finally{
			fr.close();
		}
    }
}