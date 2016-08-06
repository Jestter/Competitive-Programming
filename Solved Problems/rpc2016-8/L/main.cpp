#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC; scanf("%d",&TC);
	while(TC--)
	{
		long in;
		scanf("%ld",&in);
		long last = in;
		long long sum =0;
		do
		{
			scanf("%ld",&in);
			if(last*2 < in)
			{
				sum+= (in-last*2);
			}

			last = in;
		}while(in!=0);
		printf("%lld\n",sum);
	}
}