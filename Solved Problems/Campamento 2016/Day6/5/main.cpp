#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 1405
#define INF 999999999
 
typedef vector<long> vi;
 
unordered_map<char, long> mapita; 

vector<vector<long> > res;
vector<vi> maggtriz;
 
long mf, f, s, t; // global variables
vi p; // p stores the BFS spanning tree from s
 
 
void augment(long v, long minEdge) { // traverse BFS spanning tree from s->t
	if (v == s) { f = minEdge; return; } // record minEdge in a global var f
	else if (p[v] != -1) { augment(p[v], min(minEdge,maggtriz[p[v]][v]));
	maggtriz[p[v]][v] -= f; maggtriz[v][p[v]] += f; } }
 
 
 
int main()// inside int main(): set up âresâ, âsâ, and âtâ with appropriate values
{
 
	maggtriz.assign(MAX_V,vi(MAX_V,0));
 
	int tubes;
	
	scanf("%d" , &tubes);
	mf = 0;
	res.assign(MAX_V,vector<long>());

	int cont = 3;
	mapita['A'] = 1;mapita['Z'] = 2;
	for(int i = 1; i <= tubes ; i++)
	{
		char a, b;
		long cap;
		cin >> a >> b >> cap;
		if( mapita.count(a) == 0){mapita[a] = cont++;}
		if(mapita.count(b) == 0){mapita[b] = cont++;}
		res[mapita[a]].push_back(mapita[b]);
		res[mapita[b]].push_back(mapita[a]);
		maggtriz[mapita[a]][mapita[b]]+=cap;
		maggtriz[mapita[b]][mapita[a]]+=cap; 
	}

	s = mapita['A'];
	t = mapita['Z'];

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

	augment(t, INF); // find the min edge weight f in this path, if any
	if (f == 0) break; // we cannot send any more flow (f = 0), terminate
	mf += f; // we can still send a flow, increase the max flow!
	}
	printf("%d\n", mf);	
}