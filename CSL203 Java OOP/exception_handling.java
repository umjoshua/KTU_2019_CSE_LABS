/*try, catch, throws and finally in Java*/
import java.util.*;
class exception_handling{
    public static void main(String args[]) throws ArrayIndexOutOfBoundsException {
        Scanner sc=new Scanner(System.in);
        int size1,size2,flag,sum;
        System.out.print("Enter size of the first array: ");
        size1=sc.nextInt();
        System.out.print("Enter size of the second array: ");
        size2=sc.nextInt();
        int[] array1=new int[size1];
        int[] array2=new int[size2];
        
        System.out.println("Enter elements of array 1: ");
        for(int i=0;i<size1;i++){
            array1[i]=sc.nextInt();
        }
        System.out.println("Enter elements of array 2: ");
        for(int i=0;i<size2;i++){
            array2[i]=sc.nextInt();
        }
        flag=size1;
        if(size2>size1)
            flag=size2;
        try{
            for(int i=0;i<flag;i++){
                    sum = (array1[i]/array2[i]);
                    System.out.println(array1[i]+"/"+array2[i]+"="+sum);
                }
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index is out of bounds "+e);
        }
        catch(ArithmeticException e){
            System.out.println("Cannot divide a number by zero "+e);  
        }
        catch(Exception e){
            System.out.println("Some other Exception "+e);
        }
        finally{
            System.out.println("Operation Completed");
        }

    }
}