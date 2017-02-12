#include <bits/stdc++.h>

using namespace std;

#define UNVISITED -1

int dirx[4] = {-1, 0, 1, 0};
int diry[4] = { 0, 1, 0,-1};

int m,n;
int grid[500][500];
int dist[500][500];

bool isValid(int x,int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	memset(grid,0,sizeof grid);
	memset(dist,-1,sizeof dist);
	cin >> m >> n; scanf("\n");
	for (int i = 0; i < m; ++i)
	{
		string s; getline(cin, s);
		for (int j = 0; j < n; ++j)
		{
			grid[i][j] = s[j]-'0';
		}
	}
	pair<int,int> ini = make_pair(0,0);
	queue<pair<int,int> > Q;
	Q.push(ini);
	dist[0][0] = 0;
	while(!Q.empty())
	{
		pair<int,int> u = Q.front(); Q.pop();
		int multVal = grid[u.first][u.second];
		for (int i = 0; i < 4; ++i)
		{
			int x = u.second + dirx[i] * multVal,y = u.first + diry[i] * multVal;
			if(isValid(x,y) && dist[y][x] == UNVISITED) {
				dist[y][x] = dist[u.first][u.second] + 1;
				Q.push(make_pair(y,x));
			}
		}
	}

	if(dist[m-1][n-1] == UNVISITED) cout << "IMPOSSIBLE" << endl;
	else cout << dist[m-1][n-1] << endl;
	return 0;

}