import java.util.Scanner;

public class Main
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();

		double start = 0;
		double end = 100000000;
		for (int i = 0; i<100; i++) 
		{
			double x = (start+end)/2;
			double xini = (a/x);
			double yini;
			if(xini%2 == 0)
				yini = 0;
			else
				yini = x;

			double xend = xini+x;
			double yend = (yini==0)? x:0;

			double pend1 = (yini-b)/(xini-a);
			double pend2 = (b-yend)/(a-xend);
			if(pend1==pend2)
			{

			}
			else
			{

			}

		}

		if(end-start > 0.00000001)
			System.out.println(-1);
		else
			System.out.println(start);
	}
}