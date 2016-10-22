//Uva 11960
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<long> divs(1e6+1,1);
	vector<long> maxd(1e6+1,0);
	maxd[1]=1;
	long last = 1;
	for (int i = 2; i <= 1e6; ++i)
	{
		for (int j = i; j <= 1e6; j+=i)
		{
			divs[j]++;
		}
		if(divs[i] >= last)
		{
			maxd[i] = i;
			last = divs[i];
		}
		else maxd[i] = maxd[i-1];
	}
	int tc;
	scanf("%d",&tc);

	while(tc--)
	{
		long num; scanf("%ld",&num);
		printf("%ld\n", maxd[num]);
	}
	return 0;
}