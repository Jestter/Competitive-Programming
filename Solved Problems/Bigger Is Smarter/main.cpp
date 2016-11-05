#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int> > vii;
typedef vector<int> vi;
typedef pair<int,int> ii;


string toStr(ii p)
{
    return to_string(p.first)+"_"+to_string(p.second);
}

bool comparePairs(const ii& lhs, const ii& rhs)
{
  	if (lhs.first > rhs.first)return true;
  	if(lhs.first == rhs.second) return lhs.second < rhs.second;
  	return false;
}

int main()
{
    vii v;
    int w,s;
    unordered_map<string,int> indexOf;
    int idx = 1;
	while(scanf("%d %d",&w,&s)!=EOF)
	{
        ii p = make_pair(s,w);
        v.push_back(p);
        indexOf[toStr(p)] = idx++;
	}
    stable_sort(v.begin(), v.end(),comparePairs);

    /*for(ii p:v)
    {
    	cout << indexOf[toStr(p)] <<" : "<<p.second << " " << p.first << endl;
    }*/

	vi p(v.size(),-1);
	vi m(v.size()+1,0);
	int l = 0;
	int last = -1;
	for (int i = 0; i < v.size(); ++i)
	{
		int lo=1,hi=l;

		while(lo <= hi)
		{
			int mid = ceil((lo+hi)/2);
		if( v[m[mid]].second < v[i].second) lo = mid+1;
		else hi = mid-1;
		}
		int newL = lo;
		p[i] = m[newL-1];
		m[newL] = i;

		if(l < newL && last!= v[i].first)
		{
			l = newL;
			last = v[i].first;
		}
	}
    printf("%d\n", l);
	vi S(l,0);
	int k = m[l];
	for (int i = l-1; i >=0; --i)
	{
		S[i] = indexOf[toStr(v[k])];
		cout << indexOf[toStr(v[k])] <<" : "<<v[k].second << " " << v[k].first << endl;
		k = p[k];
	}

	for (int i = 0; i < l; ++i)
	{
		printf("%d\n", S[i]);
	} 
    return 0;
}
