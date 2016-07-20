#include <bits/stdc++.h>

#define GREEN 0
#define RED 1
#define YELLOW 2
#define BLUE 3
#define EXIT 4

typedef pair<int,int> ii;

using namespace std;

char matrix[100][100];
int F,C;
int yaee[5];
int ii yaeepos[5];

void bfs(int sx,int sy)
{
	map<int,int> dist;
	queue<ii > Q;
	dist[sy*100+sx]=0;
	Q.push(make_pair(sx,sy));
	while(!Q.empty())
	{
		ii u = Q.top();Q.pop();

		for (int i = -1; i <= 1; i+=2)
		{
			if(u.first + i >= 0 && u.first + i < C)
			{

			}
			if(u.second + i >= 0 && u.second + i < F)
			{

			}
		}
	}
}

int main()
{
 	while(cin >> F >> C)
 	{
 		if(!F && !C)break;
 		int xi,yi;
 		for (int i = 0; i < F; ++i)
 		{
 			for (int j = 0; j < C; ++j)
 			{
 				cin >> matrix[i][j];
 				if(matrix[i][j]=='*'){xi=j;yi=i;}
 			}
 		}

 		while(true)
 		{
 			dist.clear();
 			Q.clear();
 			for (int i = 0; i < 5; ++i){yaee[i]=-1;yaeepos[i]=make_pair(-1,-1);}
 			bfs(xi,yi);
 		}
 	}
	return 0;
}