#include <bits/stdc++.h>

using namespace std;

int main()
{
	long n;
	scanf("%ld",&n);

	long long A[n];
	memset(A,0,sizeof(A));
	scanf("%I64d",&A[0]);
	//cout << "[" << 0 << "] = " << A[0] << endl;
	for (int i = 1; i < n; ++i)
	{
		long long num; scanf("%I64d",&num);
		A[i]=A[i-1]+num;
		//cout << "[" << i << "] = " << A[i] << endl;
	}

	long long count = 0;
	if(A[n-1]%3==0)
	{
		long c1=0,c2=0;
		if(A[0]==A[n-1]/3)c1++;
		for (int i = 1; i < n-1; ++i)
		{
			if(A[i]==A[n-1]/3*2)count += c1;
			if(A[i]==A[n-1]/3)c1++;
		}
	}

	printf("%I64d",count);
	return 0;
}