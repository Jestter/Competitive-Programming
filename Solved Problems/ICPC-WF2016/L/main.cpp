#include <bits/stdc++.h>

using namespace std;

typedef pair<long,long> ii;

bool comp(const ii& a,const ii& b)
{
	return a.first < b.first;
}

bool invcomp(const ii& a,const ii& b)
{
	return a.first > b.first;
}

int main()
{
	long n;
	cin >> n;
	vector<ii> inc,dec;
	long long extra=0,swap=0,used_swap=0;
	for(long i=0;i<n;i++)
	{
		long n1,n2;cin >> n1 >> n2;
		if(n2-n1>=0)inc.push_back(make_pair(n1,n2));
		else dec.push_back(make_pair(n1,n2));
	}
	sort(inc.begin(),inc.end(),comp);
	sort(dec.begin(),dec.end(),invcomp);

	for(ii p:inc)
	{
		if(extra+swap<p.first)
		{
			swap += p.first-extra-swap;
			extra += p.second-p.first;
		}
		else
		{
			extra += p.second-p.first;
		}
		//cout << swap << " " << extra <<endl;
	}

	for(ii p:dec)
	{
		if(extra+swap-used_swap<p.first)
		{
			swap += p.first-extra-swap+used_swap;
			used_swap += max(p.first-p.second-extra,(long long)0);
			extra += p.second-p.first;

		}
		else
		{
			extra += p.second-p.first;
		}
		if(extra<0)
		{
			extra =0;
		}
		//cout << swap <<" "<<extra<< " " << used_swap <<endl;
	}

	cout << swap;
    return 0;
}