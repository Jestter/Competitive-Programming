// Implementation of Dijkstra's algorithm using adjacency lists
// and priority queue for efficiency.
//
// Running time: O(|E| log |V|)

#include <bits/stdc++.h>

using namespace std;
const int INF = 2000000000;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
  
	int N, s, t;
	scanf ("%d %d", &N, &s);
	t = N;
	vector<vector<ii> > edges(N);
	for (int j = 0; j < s; j++)
	{
		int vertex, dist, i;
		scanf ("%d %d %d", &i, &vertex, &dist);
		i--; vertex--;
		edges[i].push_back (make_pair (vertex,dist)); // note order of arguments here
		edges[vertex].push_back (make_pair (i,dist)); // note order of arguments here
	}
	
	vi dist(t, INF); dist[0] = 0;
	vi dist2(t, INF); dist2[0] = 0;
	// INF = 1B to avoid overflow
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, 0));
	while (!pq.empty()) 
	{
		// main loop
		ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
		int d = front.first, u = front.second;
		
		// this is a very important check
		for (int j = 0; j < (int)edges[u].size(); j++) 
		{
			ii v = edges[u][j];
			// all outgoing edges from u
			if (dist[u] + v.second < dist[v.first]) 
			{
				dist2[v.first] = dist[v.first];
				dist[v.first] = dist[u] + v.second;
				// relax operation
				pq.push(ii(dist[v.first], v.first));
			} 
			if (dist2[u] + v.second < dist2[v.first]) 
			{
				dist2[v.first] = dist2[u] + v.second;
				// relax operation
				pq.push(ii(dist2[v.first], v.first));
			} 
			if(edges[u].size()==1)
			{
				dist2[v.first] = dist2[u] + v.second;
				// relax operation
				pq.push(ii(dist2[v.first], v.first));
			}
		} 
	}
	// this variant can cause duplicate items in the priority queue
	cout << dist[t-1]<<" "<< dist2[t-1]<< endl;
    
  return 0;
}
