#include <bits/stdc++.h>

using namespace std;
typedef vector<long long> vi;

class FenwickTree {
private: vi ft;
	// recall that vi is: typedef vector<long long> vi;
public: 
	FenwickTree(long long n) { ft.assign(n + 1, 0); }
	// init n + 1 zeroes
	long long LSOne(long long n){return (n & (-n));}
	long long rsq(long long b) 
	{
		// returns RSQ(1, b)
		long long sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum; 
	}
	long long rsq(long long a, long long b) 
	{
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(long long k, long long v)
	{
		// note: n = ft.size() - 1
		for (; k < (long)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int main()
{
	long long cases;
	scanf("%lld",&cases);
	long long count = 0;
	while(cases--)
	{
		if(count!=0)printf("\n");
		count++;
		long size, queries;
		scanf("%ld %ld",&size,&queries);
		FenwickTree ft(size+1);
		FenwickTree ft2(size+1);
		while(queries--)
		{
			long long op;
			scanf("%lld",&op);
			if(op == 0)
			{
				long long ini,end,v;
				scanf("%lld %lld %lld",&ini,&end,&v);
				ft.adjust(ini,v);
				ft.adjust(end+1,-v);
				ft2.adjust(ini,-v*(ini-1));
				ft2.adjust(end+1,v*end);
			}
			else
			{
				long long ini,end;
				scanf("%lld %lld",&ini,&end);
				long long answer = (ft.rsq(end)*end + ft2.rsq(end)) - (ft.rsq(ini-1)*(ini-1) + ft2.rsq(ini-1));
				printf("%lld", answer);
				if(queries!=0)printf("\n");
			}
		}
	}
}
