#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	vector<vector<int> > V(n+2,vector<int>());
  
	while(m--)
	{
		int a,b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	int node = -1;
	for (int i = 1; i <= n; ++i)
	{
		if(V[i].size()==0)
		{
			node = i;
			break;
		}
	}

	cout << (n-1) << endl;
	for (int i = 1; i <= n; ++i)
	{
		if(i == node)continue;
		cout << node << " " << i << (i==n?"":"\n");
	}
	return 0;
}