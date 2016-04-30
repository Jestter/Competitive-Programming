#include <bits/stdc++.h>
using namespace std;


int main()
{
	int cases;
	long total=0;
	scanf("%d",&cases);
	for (int C = 0; C < cases; ++C)
	{
		string s1;
		int a;
		cin >> s1;
		if(s1[0]=='d')
		{
			cin >> a;
			total+= a;
		}
		else
		{
			printf("%ld\n",total);
		}
	}
    return 0;
}
