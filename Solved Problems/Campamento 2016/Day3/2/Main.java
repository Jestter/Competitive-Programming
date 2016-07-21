import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		int number = sc.nextInt();

		int tabla[][] = new int[size][size];
		int x = (number/size);
		int d = number-((size-1)*x);

		for (int i=0; i<size; i++) 
		{
			for(int j=0; j<size; j++)
			{
				if(i==j)
					System.out.print(d+((j==size-1)?"":" "));
				else
					System.out.print(x+((j==size-1)?"":" "));
			}
			if(i<size-1 )
				System.out.println();	
		}
	}
}