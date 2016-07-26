#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 305
#define INF 999999999
 
typedef vector<long> vi;
 
 
vector<vector<long> > res;
vector<vi> maggtriz;
 
long mf, f, s, t; // global variables
vi p; // p stores the BFS spanning tree from s
 
 
void augment(long v, long minEdge) 
{ // traverse BFS spanning tree from s->t
	if (v == s) { f = minEdge; return; } // record minEdge in a global var f
	else if (p[v] != -1) 
	{
	 	augment(p[v], min(minEdge,maggtriz[p[v]][v]));
		maggtriz[p[v]][v] -= f; maggtriz[v][p[v]] += f; 
	}
}
 
 
 
int main()// inside int main(): set up ‘res’, ‘s’, and ‘t’ with appropriate values
{
 	int tc;
 	cin >> tc;
	maggtriz.assign(1000,vi(1000,0));
 
	int persons, taxis;
	long speed,tlimit;
	while(tc--)
	{
		scanf("%d" , &persons);
		scanf("%d", &taxis);
		scanf("%ld", &speed);
		scanf("%ld", &tlimit);

		long total = taxis+persons;
		mf = 0;
		res.assign(total+5,vector<long>());
		s = 0;
		t = total+1;

		vector<pair<long,long> > p_persons;
		for (int i = 0; i < persons; ++i)
		{
			long x,y;
			scanf("%ld %ld",&x,&y);
			p_persons.push_back(make_pair(x,y));
		}

		for (int i = 1; i <= taxis; ++i)
		{
			long x,y;
			scanf("%ld %ld",&x,&y);
			for (int j = 1; j <= persons; ++j)
			{
				long distance = abs(x-p_persons[j-1].first)+abs(y-p_persons[j-1].second);
				if(distance/speed <= tlimit)
				{
					res[i].push_back(taxis+j);
					res[taxis+j].push_back(i);
					maggtriz[i][taxis+j] = 1;
					maggtriz[taxis+j][i] = 1;
				}
			}
		}

		for(int i = 1; i <= taxis ; i++)
		{ 
			res[s].push_back(i);
			res[i].push_back(s);
		 	maggtriz[s][i] = 1;
		  	maggtriz[i][s] = 1;
		}
		for(int i = taxis+1; i <= persons+taxis ; i++)
		{ 
			res[t].push_back(i);
			res[i].push_back(t); 
			maggtriz[t][i] = 1; 
			maggtriz[i][t] = 1;
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