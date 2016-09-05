#include <bits/stdc++.h>

using namespace std;

#define NMAX 500005

int main()
{
	vector<unordered_set<long> > sieve(NMAX, unordered_set<long>());
	double sqrt_num = sqrt(NMAX);
	for (long i = 1; i <= sqrt_num; ++i)
	{
		for (long j = i+i; j < NMAX; j+=i)
		{
			sieve[j].insert(i);
			sieve[j].insert(j/i);
		}
	}

	long tc;
	scanf("%ld",&tc);
	while(tc--)
	{
		long n,k;
		scanf("%ld %ld",&n,&k);
		long long sum = 0;
		for (long num: sieve[n])
		{
			if(num%k!=0)sum+=num;
		}
		printf("%lld\n",sum);
	}
}