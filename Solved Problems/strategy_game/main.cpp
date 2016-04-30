#include <bits/stdc++.h>

using namespace std;


int main()
{
    int j,r;
    while(scanf("%d %d",&j,&r)!=EOF)
    {
    	long points[j];
    	memset(points,0,sizeof(points));

    	for (int i = 0; i < j*r; ++i)
    	{
    		int p;
    		scanf("%d",&p);
    		points[i%j]+=p;
    	}

    	int last = 0;
    	int p = 0;
    	for (int i = 0; i < j; ++i)
    	{
    		if(points[i]>=p){last = i+1;p = points[i];}
    	}
    	printf("%d\n",last);
    }
}