#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int cases;
	scanf("%d",&cases);
	for (int c = 0; c < cases; ++c)
	{
		int a;
		scanf("%d",&a);
		int max=-1,min=100,sum=0;
		for (int i = 0; i < a; ++i)
		{
			int d;
			scanf("%d",&d);
			if(d<min)min =d;
			if(d>max)max = d;
			sum+=d;
		}
		printf("%d\n",(max-(sum/a)+(sum/a)-min)*2);
	}
    return 0;
}
