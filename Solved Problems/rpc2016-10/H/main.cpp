#include <bits/stdc++.h>

using namespace std;

#define maxx 10001

int main()
{
	long long ans[maxx];
	for (int i = 0; i < maxx; ++i)
	{
		ans[i] = 1;
	}
	for (int i = 0; i < 2; ++i)
	{
		long long tmp[maxx];
		memset(tmp,0,sizeof tmp);
		for (int j = 1; j < maxx; ++j)
		{
			for (int k = 0; j+k < maxx; ++k)
			{
				tmp[j+k] += ans[k];
			}
		}

		for (int j = 0; j < maxx; ++j)
		{
			ans[j] += tmp[j];
		}
	}
	//cout << "max = " << ans[maxx-1] << endl;
	unordered_map<long long,long> mp;
	for (int i = 0; i < maxx; ++i)
	{
		mp[ans[i]] = i;
	}

	long tc;
	scanf("%ld",&tc);
	while(tc--)
	{
		long long num;
		scanf("%lld",&num);
		if(mp.count(num)!=0)
		{
			printf("%ld\n", mp[num]);
		}
		else printf("No solution\n");
	}
}