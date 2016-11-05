#include <bits/stdc++.h>

using namespace std;


int main()
{
	int pcs,vends;
	cin >> pcs >> vends;

	vector<vector<int> > mapita(pcs+5,vector<int>());

	long best = 0;
	for (int i = 1; i <= pcs; ++i)
	{
		int a; cin >> a;
		mapita[pcs-i].push_back(a);
		best = max(best,(long)a);
	}

	for (int j = 1; j < vends; ++j)
	{
		for (int i = 1; i <= pcs; ++i)
		{
			int a; cin >> a;
			mapita[pcs-i].push_back(a);
			best = max(best,(long)a);
			int quedan = 0;
			long mejor = 0;
			if(i!=pcs)for (int k = i; k <= pcs; ++k)
			{
				for (int n:mapita[k])
				{
					if(mejor < n + a)
					{
						mejor = n + a;
						quedan = pcs-k;
					}
					else if(mejor == n + a && quedan < pcs-k)
					{
						mejor = n + a;
						quedan = pcs-k;
					}
				}
			}
			mapita[quedan].push_back(mejor);

			best = max(mejor,best);

		}
	}

	cout << best << endl;	
	return 0;
}