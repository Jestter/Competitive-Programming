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
	long days;
	scanf("%ld",&days);
	FenwickTree ft(100005);
	long long Arr[100005];memset(Arr,0,sizeof Arr);
	for (long i = 0; i < days; ++i)
	{
		long x1,x2;
		scanf("%ld %ld",&x1,&x2);
		if(i==0){ft.adjust(x1+1,+1);ft.adjust(x2,-1);printf("0\n");continue;}

		long long atravesaos = ft.rsq(x1);
		long long atravesaos2 = ft.rsq(x2);
		printf("%lld\n",(atravesaos-Arr[x1])+(atravesaos2-Arr[x2]));
		Arr[x1]= atravesaos;
		Arr[x2]= atravesaos2;
		ft.adjust(x1+1,+1);ft.adjust(x2,-1);
	}
	return 0;	
}