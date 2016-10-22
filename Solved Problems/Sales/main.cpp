//Uva 1260
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		
		int n;
		scanf("%d",&n);
		
		int arr[n];
		long long sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
			
			for (int j = 0; j < i; ++j)
			{
				if(arr[i] >= arr[j])sum++;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
