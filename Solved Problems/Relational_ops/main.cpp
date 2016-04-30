#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int cases;
	scanf("%d",&cases);
	for (int c = 0; c < cases; ++c)
	{
		long a,b;
		scanf("%ld%ld",&a,&b);
		printf("%c\n", a>b?'>':a<b?'<':'=');
	}
    return 0;
}
