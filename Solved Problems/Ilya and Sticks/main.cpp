#include <bits/stdc++.h>

using namespace std;

int main()
{
	long n;
	scanf("%ld",&n);
	long sticks[n];

	for (long i = 0; i < n; ++i)
	{
		scanf("%ld",&sticks[i]);
	}

	sort(sticks,sticks+n);

	bool bo = false;
	long long count = 0;
	long long a,b;

	for (long i = n-1; i > 0; --i)
	{
		if(sticks[i]==sticks[i-1])
		{
			if(!bo)a=sticks[i];
			if(bo){b=sticks[i];count+=a*b;}
			bo=!bo;
			i--;
		}
		else if(sticks[i]-1 == sticks[i-1])
		{
			if(!bo)a=sticks[i]-1;
			if(bo){b=sticks[i]-1;count+=a*b;}
			bo=!bo;
			i--;
		}
	}

	printf("%I64d",count);
	return 0;
}