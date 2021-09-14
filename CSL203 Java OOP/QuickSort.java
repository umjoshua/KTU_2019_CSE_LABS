/* Java program to implement quick sort of string array*/
import java.util.*;
public class QuickSort{
    void quicksort(String ar[], int low, int high){
        String temp,pivot;int i,j;
        if(low<high){
            pivot=ar[low];
            i=low;
            j=high;
            
            while(i<j){
                i=i+1;
                while(i<=high && (ar[i].compareTo(pivot))<=0)
                    i++;
                while(j>=low && (ar[j].compareTo(pivot))>0)
                    j--;
                if(i<j){
                    temp=ar[i];
                    ar[i]=ar[j];
                    ar[j]=temp;
                    }
            }
            temp=ar[low];
            ar[low]=ar[j];
            ar[j]=temp;
            
            quicksort(ar,low,j-1);
            quicksort(ar,j+1,high);
   }
 }
 
 public static void main(String[] args){
    QuickSort qs = new QuickSort();
    Scanner sc = new Scanner (System.in);
    
    System.out.print(" \nEnter the number of names : ");
    int n=sc.nextInt();
    String array[]=new String[n];
    int l=array.length;
     
    System.out.print(" \nEnter the names :");
    for(int i=0;i<l;i++)
       array[i]=sc.next();
    qs.quicksort(array,0,l-1);
    
    System.out.println("\nThe sorted names are : ");
    for(int i=0;i<l;i++)
        System.out.println(array[i]);
 }
}
