import java.util.*;

class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = 1;
		while(true)
		{
			int n = sc.nextInt();
			if(n == 0)
			{
				break;
			}
			else
			{

				int var;
				int total = 0;
				int[] arreglito = new int[n];
				for (int i = 0;i < n ;i++) 
				{
					for (int j = 0; j < n;j++ ) 
					{
						var = sc.nextInt();
						total = total + var; 
						arreglito[i] = arreglito[i]-var;
						arreglito[j] = arreglito[j]+var;			
					}	
				}
				int agg = 0;
				for(int i = 0; i < n; i++)
				{
					if(arreglito[i] > 0)
					{
						agg = agg + arreglito[i];
					}
				}
				System.out.println(cases+". " + total + " " + agg);
				cases++;


			}
		}
	}
}