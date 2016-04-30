#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,Q;
	while(cin >> N)
	{
		int A[N+1][10];memset(A,0,sizeof(A));
		for (int i = 1; i < N+1; ++i)
		{
			int n;cin >> n;A[i][n]++;
		}

		for (int i = 1; i < N+1; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				A[i][j]+=A[i-1][j];
				//cout << A[i][j] ;
			}
			//cout << endl;
		}

		//cout << endl;

		cin >> Q;
		for (int i = 0; i < Q; ++i)
		{
			int q1,q2; cin >> q1 >> q2;
			q1--;
			int counter= 0;
			for (int j = 0; j < 10; ++j)
			{
				if(A[q1][j]!=A[q2][j]){counter++;}
				//cout << j<<" : "<< (A[q2][j]-A[q1][j])<< endl;
			}
			cout << counter << endl;
		}
	}
}