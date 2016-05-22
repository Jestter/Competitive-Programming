#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC,M,W;
	cin >> TC;
	while(TC--)
	{
		cin >> M >> W;
		int arr[M];
		for (int i = 0; i < M; ++i)
		{
			cin >> arr[i];
		}
		sort(arr,arr+M);
		long long sum=0;
		int eles=0;
		for (int i = 0; i < M; ++i)
		{
			sum+=arr[i];
			if(sum<W)eles++;
			else break;
		}
		cout << eles << endl;
	}
}