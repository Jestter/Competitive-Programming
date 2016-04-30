#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x=0,y=0,z=0;
	for (int i = 0; i < n; ++i)
	{
		int a,b,c;
		cin >> a;
		cin >> b;
		cin >> c;
		x+=a;
		y+=b;
		z+=c;
	}
	if(x||y||z)printf("NO");
	else printf("YES");
	return 0;
}