#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int ini,a,b,c;
	scanf("%d%d%d%d",&ini,&a,&b,&c);
	while(ini!=0||a!=0||b!=0||c!=0)
	{
		printf("%d\n",(1080+ 360-(a-ini<0?40+(a-ini):a-ini)*9 + 360-(a-b<0?40+(a-b):a-b)*9 + 360-(c-b<0?40+(c-b):c-b)*9));
		scanf("%d%d%d%d",&ini,&a,&b,&c);
	}
    return 0;
}
