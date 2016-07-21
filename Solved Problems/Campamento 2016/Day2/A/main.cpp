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
	int n,q;
	scanf("%d",&n);

	vector<int> divisors[n+1];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j*i <= n; ++j)
		{
			divisors[i*j].push_back(i);
		}
	}

	/*for (int i = 1; i < n+1; ++i)
	{
		for (int a:divisors[i])
		{
			cout << a << " ";
		}
		cout << endl;
	}*/

	int charges[n+1];
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&charges[i]);
	}
	FenwickTree ftree(n);

	scanf("%d",&q);
	while(q--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int val;
			scanf("%d",&val);
			long long sum = 0;
			for(int div:divisors[val])
			{
				sum += ftree.rsq(div);
			}
			printf("%lld\n", (sum+charges[val]));
		}
		else
		{
			int l,r,d;
			scanf("%d %d %d",&l,&r,&d);
			ftree.adjust(l,d);
			ftree.adjust(r+1,-d);
		}
	}
	return 0;
}