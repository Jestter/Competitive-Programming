#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases = 1;
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n == 0)
		{
			break;
		}
		else
		{

			int var;
			int total = 0;
			int arreglito[n];
			memset(arreglito,0,sizeof(arreglito));
			for (int i = 0;i < n ;i++) 
			{
				for (int j = 0; j < n;j++ ) 
				{
					scanf("%d",&var);
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
			printf("%d. %d %d\n",cases,total,agg);
			cases++;


		}
	}
}