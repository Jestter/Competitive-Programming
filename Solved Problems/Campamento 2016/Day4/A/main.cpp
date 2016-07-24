#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii> > vii;


int main()
{
	int n,m,a,b,k,g;
	cin >> n >> m;
	cin >> a >> b >> k >> g;

	vector<ii> gpath;
	char loRecorre[1001][1001];
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			loRecorre[i][j]=0;
		}
	}

	map<int,int> grange;
	int last = -1;
	for (int i = 0; i < g; ++i)
	{
		int in; cin >> in;
		if(last!=-1)
		{
			gpath.push_back(ii(last,in));
			loRecorre[last][in] = 1;
			loRecorre[in][last] = 1;
			cout << last << " -> " << in << endl;
		}
		last = in;
	}
	cout << m << endl;
	vii adjList(n+1,vector<ii>());

	for (int i = 0; i < m; ++i)
	{
		int A,B,L;
		cin >> A >> B >> L;
		adjList[A].push_back(ii(B,L));
		adjList[B].push_back(ii(A,L));
		cout << A << " " << B << " " << L << endl;
	}

	int sumr = 0;
	for (int i = 0; i < gpath.size(); ++i)
	{
		grange[gpath[i].first] = sumr;

		int A= gpath[i].first,B = gpath[i].second;
		if(i+1<=gpath.size())
		{
			for (int j = 0; j < adjList[A].size(); ++j)
			{
				if(adjList[A][j].first==B){sumr+=adjList[A][j].second;break;}
			}
		}
		if(i+1 == gpath.size())grange[gpath[i].second] = sumr;
	}
	//revisando
	for (int i = 0; i < gpath.size(); ++i)
	{
		cout << "desde " << gpath[i].first << " comienza en t " << grange[gpath[i].first] << " y se demora " << (grange[gpath[i].second]-grange[gpath[i].first]) << " hasta " << gpath[i].second << endl;
	}

	int s = a; //cambiar
	vi dist(n+1,INF); dist[s]=k;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(k,s));
	while(!pq.empty())
	{
		ii front = pq.top();pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u])continue;
		cout << u << " to ";
		for (int j = 0; j < adjList[u].size(); ++j)
		{
			ii v = adjList[u][j];
			cout << v.first << " ";
			int wait = 0;
			int A = min(u,v.first); B = max(u,v.first);
			if(loRecorre[u][v.first]==1 && dist[u] + v.second >= grange[u] && dist[u] + v.second < grange[v.first])
			{
				wait = grange[v.first] - (dist[u] + v.second);
				cout << " wait:" << wait << " ";
			}

			if(dist[u] + v.second + wait < dist[v.first])
			{
				if(wait != 0) cout << " asdsad ";
				dist[v.first] = dist[u] + v.second + wait;
				pq.push(ii(dist[v.first],v.first));
			}
		}
		cout << endl;
	}


	cout << (dist[b]-k);
	return 0;
}