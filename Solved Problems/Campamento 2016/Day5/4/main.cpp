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
	int size;

	int cassosososoo = 1;
	while(true)
	{
		
		scanf("%d",&size);
		if(size == 0)
		{
			break;
		}
		if(cassosososoo!=1)printf("\n");
		printf("Case %d:\n",cassosososoo);
		cassosososoo++;
		int agg[size+1];
		long long sum[size+1];
		FenwickTree ft(size+1);
		for(int i = 1; i<size+1; i++)
		{
			scanf("%d",&agg[i]);
			sum[i] = agg[i];
			sum[i] += sum[i-1];
			//ft.adjust(i,v);
		}
		while(true)
		{
			string op;
			cin >> op;
			if(op[0] == 'E')
			{
				break;
			}
			else if(op[0] == 'M')
			{	
				int ini,end;
				scanf("%d %d",&ini,&end);
				long long answer;
				answer = (sum[end]-sum[ini-1]) + ft.rsq(ini,end);
				printf("%lld\n", answer);
			}
			else
			{
				int x,r;
				scanf("%d %d",&x,&r);
				long long v = agg[x] + ft.rsq(x,x);
				ft.adjust(x,(r-v));
			}
			scanf("\n");
		}
	}
}
