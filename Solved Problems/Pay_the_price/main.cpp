#include <bits/stdc++.h>

using namespace std;


long long dp[305][305]; //[price][n coins]

int N,L1,L2;


int spaces(string s)
{	
	int count = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]==' ')count++;
	}
	return count;
}

int main()
{
	dp[0][0]=1;
	for (int c = 1; c <= 300; ++c)
	{
		for (int i = c; i <= 300; ++i)
		{
			for (int j = 1; j <= 300; ++j)
			{
				dp[i][j]+=dp[i-c][j-1];
				//cout << c << " " << i << " " << j << endl;
			}
		}
	}

	for (int i = 1; i <= 300; ++i)
	{
		for (int j = 1; j<= 300; ++j)
		{
			dp[i][j]+=dp[i][j-1];
		}
	}

	string line;

	while(getline(cin,line))
	{
		if(spaces(line)==0)
		{
			sscanf(line.c_str(),"%d",&N);
			if(N==0)cout << 1 << endl;
			else printf("%lld\n", dp[N][N]);
		}
		else if(spaces(line)==1)
		{
			sscanf(line.c_str(),"%d %d",&N,&L2);
			if(L2>300)L2 = 300;
			if(N==0)cout << 1 << endl;
			else printf("%lld\n",dp[N][L2]);
		}	
		else
		{
			sscanf(line.c_str(),"%d %d %d",&N,&L1,&L2);
			
			if(N==0)cout << (L1==0?1:0) << endl;
			if(L2>300)L2=300;
			if(L1>300)L1=301;
			if(L1==0)L1=1;
			if(N!=0) printf("%lld\n",dp[N][L2]-dp[N][L1-1]);
		}
	}
    return 0;
}