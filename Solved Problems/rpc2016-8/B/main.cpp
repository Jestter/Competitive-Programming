#include <bits/stdc++.h>

using namespace std;

int main()
{
	long TC; scanf("%ld",&TC);
	while(TC--)
	{
		long N;
		scanf("%ld",&N);
		bool arr[N+1]; memset(arr,0,sizeof arr);
		long cc = 0;
		for (long i = 1; i <= N; ++i)
		{
			long pos; scanf("%ld",&pos);
			if(i < pos){arr[pos] = true;cc++;}
		}
		printf("%ld\n",cc);
		for (long i=0;i<N+1;i++)
		{
			if(arr[i]){printf("%ld", i);cc--;}
			if(!(TC==0 && cc==0) && arr[i]) printf("\n");
		}
	}
}