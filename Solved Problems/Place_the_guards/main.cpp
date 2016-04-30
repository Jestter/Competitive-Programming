#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vector<int> unvisited;

int INF = INT_MAX;

int main()
{
	int TC;
	scanf("%d",&TC);
    while(TC--)
    {
    	int V,E;
    	scanf("%d %d",&V,&E);
    	unvisited.clear();
    	unvisited.assign(V,1);
    	AdjList.clear();
    	AdjList.assign(V,vii());

    	for (int i = 0; i < E; ++i)
    	{
    		int from,to; 
    		scanf("%d %d",&from,&to);
    		ii a(to,0);
    		ii b(from,0);
    		AdjList[from].push_back(a);
    		AdjList[to].push_back(b);
    	}
    	bool isBipartite = true; // addition of one boolean flag, initially true
    	int gnum = 0;
    	for (int i = 0; i < V && isBipartite; ++i)
    	{
    		if(unvisited[i])
    		{
    			unvisited[i]=0;
    			int s = i;
		        queue<int> q; q.push(s);
				vi color(V, INF); color[s] = 0;
				int gs[2]={1,0};
				while (!q.empty() & isBipartite) // similar to the original BFS routine
				{
					int u = q.front(); q.pop();
					for (int j = 0; j < (int)AdjList[u].size(); j++) 
					{
						ii v = AdjList[u][j];
						unvisited[v.first] = 0;
						if (color[v.first] == INF)// but, instead of recording distance,
						{
							color[v.first] = 1 - color[u]; // we just record two colors {0, 1}
							gs[color[v.first]]+=1;
							q.push(v.first);
						}
						else if (color[v.first] == color[u]) // u & v.first has same color
						{ 
							isBipartite = false; break; // we have a coloring conflict
						} 
					} 
				}
				int minn = min(gs[0],gs[1]);
				gnum += minn>0?minn:1;
			}
		}
		if(!isBipartite)printf("-1\n");
		else printf("%d\n", gnum);
    }
    return 0;
}