#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int cases;
	scanf("%d",&cases);
	for (int d = 0; d < cases; ++d)
	{
		vector<int> a(3);
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a.begin(),a.begin()+3);
		printf("Case %d: %d\n",d+1,a[1]);
	}
    return 0;
}
