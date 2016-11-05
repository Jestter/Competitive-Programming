#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


int main()
{
    vi v;
    int a;
   	while(scanf("%d",&a)!=EOF)
   	{
		v.push_back(a);
   	}

   	vi p(v.size(),-1);
   	vi m(v.size()+1,0);
   	int l = 0;

   	for (int i = 0; i < v.size(); ++i)
   	{
   		int lo=1,hi=l;

   		while(lo <= hi)
   		{
   			int mid = ceil((lo+hi)/2);
			if( v[m[mid]] < v[i]) lo = mid+1;
			else hi = mid-1;
   		}
   		int newL = lo;
   		p[i] = m[newL-1];
   		m[newL] = i;

   		l = max(newL,l);
   	}
   	printf("%d\n-\n", l);
   	vi s(l,0);
   	int k = m[l];
   	for (int i = l-1; i >=0; --i)
   	{
   		s[i] = v[k];
   		k = p[k];
   	}

   	for (int i = 0; i < l; ++i)
   	{
   		printf("%d\n", s[i]);
   	}
    return 0;
}
