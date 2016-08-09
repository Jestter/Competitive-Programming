#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,d;
	cin >> n >> k >> d;
	long long dp[101][101];
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			dp[i][j] = 0;
		}
	}
	dp[0][0]=0;
	dp[1][1]=1;
	for (int i = 2; i <= n; ++i) //para n
	{
		for (int j = 1; j <= k && j<=i; ++j) //para d
		{
			//cout << i << " " << j << " = ";
			for (int l = 1; l <= k && l<=i; ++l) // para cada arista desde origen n d
			{
				//cout << (l==1?"":" + ") << dp[i-l][(l<j?j:1)];
				if(i-l==0) dp[i][j]++;
				else dp[i][j] += dp[i-l][(l<j?j:1)];
				dp[i][j]%=1000000007;
			}
			//cout << " = " << dp[i][j] << endl;
		}
	}

	cout << dp[n][d];

	return 0;
}