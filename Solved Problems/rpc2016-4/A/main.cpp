#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main()
{
	ULL n;
	while(cin>>n)
	{
		if(n==0)break;
		else cout << ((n*(n+1)/2)*(n*(n+1)/2))<<endl;
	}
}