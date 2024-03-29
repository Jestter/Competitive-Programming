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
	vii times(1001,vector<ii>(1001,ii(-1,-1)));//[1001][1001];
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			times[i][j].first = -1;
			times[i][j].second = -1;
		}
	}
	int last = -1;
	for (int i = 0; i < g; ++i)
	{
		int in; cin >> in;
		if(last!=-1)
		{
			gpath.push_back(ii(last,in));
			//cout << last << " -> " << in << endl;
		}
		last = in;
	}
	//cout << m << endl;
	vii adjList(n+1,vector<ii>());

	for (int i = 0; i < m; ++i)
	{
		int A,B,L;
		cin >> A >> B >> L;
		adjList[A].push_back(ii(B,L));
		adjList[B].push_back(ii(A,L));
		//cout << A << " " << B << " " << L << endl;
	}	
	int sumr = 0;
	for (int i = 0; i < gpath.size(); ++i)
	{
		int inir = sumr;

		int A= gpath[i].first,B = gpath[i].second;
		if(i+1<=gpath.size())
		{
			for (int j = 0; j < adjList[A].size(); ++j)
			{
				if(adjList[A][j].first==B){sumr+=adjList[A][j].second;break;}
			}
		}
		times[A][B].first = inir;
		times[A][B].second = sumr;
		times[B][A].first = inir;
		times[B][A].second = sumr;
	}
	
	int s = a; //cambiar
	vi dist(n+1,INF); dist[s]=k;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(k,s));
	while(!pq.empty())
	{
		ii front = pq.top();pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u])continue;
		for (int j = 0; j < adjList[u].size(); ++j)
		{
			ii v = adjList[u][j];
			int wait = 0;
			if(times[u][v.first].first <= dist[u] && times[u][v.first].second >= dist[u])
			{
				wait = times[u][v.first].second - dist[u];
			}

			if(dist[u] + v.second + wait < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second + wait;
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}


	cout << (dist[b]-k);
	return 0;
}