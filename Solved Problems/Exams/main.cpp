#include <bits/stdc++.h>
using namespace std;

typedef pair<long,long> ll;

bool compare(ll a,ll  b)
{
	if(a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first > b.first;
}

bool compare2(ll a,ll  b)
{
	if(a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;
	ll agg[n];
	ll last = ll(0,0); 
	for (int i = 0; i < n; ++i)
	{
		cin >> agg[i].first;
		cin >> agg[i].second;
		if(!compare2(agg[i],last))
		{
			last.first = agg[i].first;
			last.second = agg[i].second;
		}
	}

	sort(agg,agg+n, compare);

	bool flag = true;
	long tmre = agg[0].second;
	for (int i = 1; i < n; ++i)
	{
		if(tmre >= agg[i].first)
		{
			tmre = agg[i].first;
		}
		else if(tmre >= agg[i].second)
		{
			tmre = agg[i].second;
		}
		else {flag = false;break;}
	}

	if(flag)
	{
		cout << last.second;
	}
	else cout << last.first;
    return 0;
}