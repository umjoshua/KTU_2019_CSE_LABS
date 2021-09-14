/* To implement  a Java program that reads a line of integers, and then displays each integer,
and the sum of all the integers 
*/
import java.util.*;
class string_tokenizer{
    public static void main(String args[]) {
		int n,sum=0;
		String s;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter integers with once space gap : ");
        s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s," ");
		System.out.println("The Numbers are:");
		while(st.hasMoreTokens())
		{
			String temp = st.nextToken();
			n = Integer.parseInt(temp);
			System.out.print(n+" ");
			sum+=n;
        }
		System.out.println('\n'+"Sum:" + sum);
		sc.close();
    }
}