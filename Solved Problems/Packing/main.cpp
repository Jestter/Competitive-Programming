#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int cases;
	scanf("%d",&cases);
	for (int c = 0; c < cases; ++c)
	{
		int m,n,o;
		scanf("%d%d%d",&m,&n,&o);
		printf("Case %d: %s\n",c+1, m>20||n>20||o>20?"bad":"good" );
	}
    return 0;
}
