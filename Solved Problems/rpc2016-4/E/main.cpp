#include <bits/stdc++.h>

using namespace std;

int main()
{
	char line[((int)1e6+1)];
	string s;
	int n;
	while(scanf("%s %d",line,&n)!=EOF)
	{
		s = string(line);
		while(n--)
		{
			int i,j;scanf("%d %d",&i,&j);
			char a = s[(i-2+j)%s.length()];
			printf("%c\n",a);
		}
		
	}	
}
