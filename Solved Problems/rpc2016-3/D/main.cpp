#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	unordered_map<long long,double> sol;

	while(scanf("%lld", &n) == 1)
	{
		if(n == 0)return 0;
		if(sol.count(n)==0)
		{
			double res= 0;
			double s2 = 0;
			/*for (double j = 1; j <= n*2-1; j+=2)
			{
				s2+= ((j-n)*(j-n));  //j^2 - 2*j*n*n/2 + n^2* n/2
			}*/
			n = n-1;
			double sumodd = ((double)(4*n*n*n + 12*n*n + 11*n + 3))/3.0;
			n = n+1;
			s2 = sumodd/(n-1) - (n)*(n);
			//s2/= (n-1);
			//cout <<"---->" <<s2 << endl;
			sol[n]=sqrt(s2);
		}
		printf("%.6f\n", sol[n]);
	}
}