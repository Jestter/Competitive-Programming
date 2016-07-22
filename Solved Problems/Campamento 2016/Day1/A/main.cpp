#include <bits/stdc++.h>

using namespace std;

int landscape[1e5];
int w,b;

bool check(int h)
{

}


int main()
{
	scanf("%d %d",&w,&b);
	for (int i = 0; i < w; ++i)
	{
		scanf("%d",&landscape[i]);
	}

	int ini=0,end=1e9+1;
	while(true)
	{
		int mid = (end+ini)/2;
		bool res1 = check(mid);
		bool res2 = check(mid+1);
		if(res1 && !res2)
		{
			break;
		}
		if(res1)
		{
			ini = mid;
		}
		if(!res1)
		{
			end = mid;
		}
	}
	return 0;
}