#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int cases;
	scanf("%d",&cases);
	for (int c = 0; c < cases; ++c)
	{
		long a;
		scanf("%ld",&a);
		long r = abs(((a*567/9+7492)*235/47-498)/10%10);
		printf("%ld\n", r);
	}
    return 0;
}
