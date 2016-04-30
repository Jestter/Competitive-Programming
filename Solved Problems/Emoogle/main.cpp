#include <bits/stdc++.h>
using namespace std;


int main()
{
	int d =1;
	while(true)
	{
		int a;
		scanf("%d",&a);
		if(a==0)break;
		long sum = 0;
		for (int i = 0; i < a; ++i)
		{
			int b;
			scanf("%d",&b);
			sum+= (b==0?-1:1);
		}
		printf("Case %d: %ld\n",d,sum);
		d++;
	}
    return 0;
}
