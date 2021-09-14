/*Java program to multiply two matrices*/
import java.util.Scanner;
public class matrix_multi{
    public static void main(String args[]){
        int r1, r2, c1, c2, i, j, k;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter row & col size of first matrix: ");
		r1 = s.nextInt(); c1 = s.nextInt();
		int mat1[][] = new int[r1][c1];
		System.out.print("Enter row & col size of second matrix: ");
		r2 = s.nextInt(); c2 = s.nextInt();
		int mat2[][] = new int[r2][c2];
		if (c1 != r2)
			System.out.println("Matrix multiplication failed!");
		else{
			System.out.println("Enter first matrix");
			for (i = 0; i < r1; i++)
				for (j = 0; j < c1; j++)
					mat1[i][j] = s.nextInt();
			
            System.out.println("Enter second matrix");
			for (i = 0; i < r2; i++)
				for (j = 0; j < c2; j++)
					mat2[i][j] = s.nextInt();
			
            int m3[][] = new int[r1][c2];
			for (i = 0; i < r1; i++) {
				for (j = 0; j < c2; j++) {
					for (k = 0; k < r2; k++) {
						m3[i][j] = m3[i][j] + mat1[i][k] * mat2[k][j];
					}
				}
            }
            
            System.out.println("Product is: ");
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++){
                    System.out.print(m3[i][j]+" ");
                }
                System.out.println();
            }
        }
    }
}