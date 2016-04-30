#include <bits/stdc++.h>

#define X1    1e10
#define X5    X1,X1,X1,X1,X1
#define X25   X5,X5,X5,X5,X5
#define X100  X25, X25, X25,X25
#define X500  X100,X100,X100,X100,X100
#define X1000  X500,X500
#define X10000  X1000,X1000,X1000,X1000,X1000,X1000,X1000,X1000,X1000,X1000

using namespace std;

int windValue[1000][10] = {0};
long long fuel[1000][10] = {X10000};
int X;
queue<pair<int,int> > A;

int state[3]={20,30,60};

int main()
{
	string line;
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&X);
		X=X/100;
		for (int i = 9; i >=0 ; --i)
		{
			for (int j = 0; j < X; ++j)
			{
				scanf("%d",&windValue[9-i][j]);
			}
		}

		printf("%lld\n",fuel[X][0]);
	}
    return 0;
}