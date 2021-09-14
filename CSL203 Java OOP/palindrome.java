/*Java program that checks whether a given string is palindrome or not
*/
import java.util.Scanner;
class palindrome{

    static boolean palindrome(String word){
        StringBuffer br=new StringBuffer(word);
        br.reverse();
        if(br.toString().compareTo(word)==0)
            return true;
        else return false;
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the string: ");
        String word=sc.nextLine();
        if(palindrome(word))
            System.out.println(word+" is palindrome");
        else
            System.out.println(word+" is not palindrome");
    }
}