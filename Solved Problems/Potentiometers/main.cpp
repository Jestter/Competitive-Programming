//Uva 12086
#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;

class FenwickTree {
private: vi ft;
	// recall that vi is: typedef vector<int> vi;
public: 
	FenwickTree(long n) { ft.assign(n + 1, 0); }
	// init n + 1 zeroes
	long LSOne(long n){return (n & (-n));}
	long long rsq(long b) 
	{
		// returns RSQ(1, b)
		long long sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum; 
	}
	long long rsq(long a, long b) 
	{
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(long k, long v)
	{
		// note: n = ft.size() - 1
		for (; k < (long)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int main()
{
	int pots,cases = 1;
	scanf("%d",&pots);
	while(pots!=0)
	{
		printf("Case %d:\n", cases);
		cases++;
		FenwickTree ft(pots);
		vector<int> values(pots+1,0);

		for (int i = 1; i <= pots; ++i)
		{
			int p; scanf("%d\n",&p);
			values[i] = p;
			ft.adjust(i,p);
		}
		char op;
		scanf("%c",&op);
		while(op != 'E')
		{
			if(op == 'S')
			{
				int a,v;
				scanf("%d %d\n",&a,&v);
				ft.adjust(a, (v-values[a]));
				values[a] = v;
			}

			else
			{
				int a,b;
				scanf("%d %d\n",&a,&b);
				long long r = ft.rsq(a,b);
				printf("%lld\n", r);
			}
			scanf("%c",&op);
		}
		scanf("%c",&op);scanf("%c\n",&op);

		scanf("%d",&pots);
		if(pots!=0)printf("\n");
	}
	return 0;
}
