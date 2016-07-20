#include <bits/stdc++.h>

#define UNVISITED 1000000

using namespace std;

int main()
{
	int h; cin >> h;

	vector<vector<int> > adj(h+1,vector<int>());
	for (int i = 0; i < h-1; ++i)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int queries; cin >> queries;
	while(queries--)
	{
		int a,b;
		cin >> a >> b;
		vector<int> dist(h+1,UNVISITED);
		dist[a]=0;dist[b]=0;
		queue<int> Q;Q.push(a);Q.push(b);
		while(!Q.empty())
		{

			int u = Q.front();Q.pop();
			//cout << "desde u = "<< u <<" propaga a "; 
			for (int i = 0; i < adj[u].size(); ++i)
			{
				int v = adj[u][i];
				//cout << v << " " ;
				if(dist[v]==UNVISITED)
				{
					dist[v] = dist[u]+1;
					Q.push(v);
				}
			}
			//cout << endl;
		}

		int max_dist = -1;
		for (int i = 1; i < h+1; ++i)
		{
			max_dist = max(max_dist, dist[i]);
		}

		cout << max_dist << (queries==0?"":"\n");
	}
	return 0;
}