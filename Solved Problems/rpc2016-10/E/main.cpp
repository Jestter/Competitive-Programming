#include <bits/stdc++.h>

using namespace std;


#define NMAX 100005

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
		long n;
		scanf("%ld",&n);
		printf("%ld\n", (n-sieve[n].size()));
	}
}