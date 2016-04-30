#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s = "";
	char c;
	bool b= true;
	while(scanf("%c",&c)!=EOF && c!='\n')
	{
		if(c-'0' > 4)
		{
			c = '0'+ ('9'-c);
			if(c != '0')b = false;
		}
		if(c-'0' <= 4)
		{
			if(c!='0')b = false;
		}
		if(c=='0' && b)
		{
			c = '9';
			b = false;
		}
		s += c;
	}
	long long agg;
	sscanf(s.c_str(),"%I64d",&agg);
	printf("%I64d", agg);
	return 0;
}