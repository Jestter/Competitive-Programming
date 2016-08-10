#include <bits/stdc++.h>

using namespace std;

int main()
{
	long n;
	scanf("%ld",&n);

	vector<long> sadnum(n+1,0);

	for (long i = 1; i <= n; ++i)
	{
		long num; scanf("%ld",&num);
		sadnum[i] = num;
	}

	vector<vector<pair<long,long> > > goesTo(n+1,vector<pair<long,long> >());

	for (long i = 2; i <= n; ++i)
	{
		long parent,w;
		scanf("%ld %ld",&parent,&w);
		goesTo[parent].push_back(make_pair(i,w));
	}

	long count = 0;
	vector<long long> bsf(n+1,0);
	stack<long> st; st.push(1);
	while(!st.empty())
	{
		long u = st.top();st.pop();
		count++;
		for (long j = 0; j < goesTo[u].size(); ++j)
		{
			long v = goesTo[u][j].first;
			long w = goesTo[u][j].second;

			if(w > bsf[u] + w) bsf[v] = w;
			else bsf[v] = bsf[u] + w;

			if(bsf[v] <= sadnum[v]) st.push(v);
		}
	}

	printf("%ld\n", (n-count));
	return 0;
}