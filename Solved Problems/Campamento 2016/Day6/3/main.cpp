#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 305
#define INF 999999999
 
typedef vector<long> vi;
 
 
vector<vector<long> > res;
long maggtriz[MAX_V][MAX_V];
 
long mf, f, s, t; // global variables
vi p; // p stores the BFS spanning tree from s
 
 
void augment(long v, long minEdge) { // traverse BFS spanning tree from s->t
	if (v == s) { f = minEdge; return; } // record minEdge in a global var f
	else if (p[v] != -1) { augment(p[v], min(minEdge,maggtriz[p[v]][v]));
	maggtriz[p[v]][v] -= f; maggtriz[v][p[v]] += f; } }
 
 
 
int main()// inside int main(): set up ‘res’, ‘s’, and ‘t’ with appropriate values
{
 
	memset(maggtriz,0, sizeof maggtriz);
 
	int nodes, edges;
	while(1)
	{
		scanf("%d" , &nodes);
		scanf("%d", &edges);
		if(nodes == 0 && edges == 0){break;}
		mf = 0;
		res.assign(nodes+2,vector<long>());
		s = 0;
		t = nodes+1;
		for(int i = 1; i <= nodes ; i++)
		{
			int agg;
			scanf("%d", &agg);
 
			if( agg == 1){res[s].push_back(i);res[i].push_back(s); maggtriz[s][i] = 1; maggtriz[i][s] = 1;}
			else{res[t].push_back(i);res[i].push_back(t); maggtriz[t][i] = 1; maggtriz[i][t] = 1;}
		}
		for (int i = 0; i < edges; ++i)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			res[a].push_back(b);
			res[b].push_back(a);
			maggtriz[a][b] = 1;
			maggtriz[b][a] = 1;
		}
		while (1) {
		f = 0;
		// run BFS, compare with the original BFS shown in Section 4.2.2
 
		vi dist(MAX_V, INF); dist[s] = 0; queue<long> q; q.push(s);
		p.assign(MAX_V, -1); // record the BFS spanning tree, from s to t!
		while (!q.empty()) {
 
		long u = q.front(); q.pop();
		if (u == t) break; // immediately stop BFS if we already reach sink t
		for (long v:res[u]) // note: this part is slow
		if (maggtriz[u][v] > 0 && dist[v] == INF)
		dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1!
		}
 
		augment(t, INF); // find the min edge weight ‘f’ in this path, if any
		if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
		mf += f; // we can still send a flow, increase the max flow!
		}
		printf("%d\n", mf);
	}
}