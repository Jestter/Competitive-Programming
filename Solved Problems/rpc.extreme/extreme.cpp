#include <bits/stdc++.h>

#define EPS 1e-7

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int a,b;
	scanf("%d",&a);
	for(int i=0;i<N-1;i++)
	{
		scanf("%d",&b);
		if(b<a)
		{
			printf("no");
			return 0;
		}
		a = b;
	}
	printf("yes");
	return 0;
}

