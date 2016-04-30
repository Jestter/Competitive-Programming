#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<long long, long long> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vector<int> unvisited;
vector<int> bribery;

long long pay,gain;

vector<pll> comps;

int d,p,r,b;

void bfs(int s)
{
	unvisited[s] = 0;
    queue<int> q; q.push(s);
    gain += (s<d?-1:1);
    pay += bribery[s];
	while (!q.empty()) 
	{
		int u = q.front(); q.pop();
		for (int j = 0; j < (int)AdjList[u].size(); j++) 
		{
			ii v = AdjList[u][j];
			if (unvisited[v.first])
			{
				unvisited[v.first] = 0;
				gain += (v.first<d?-1:1);
				//cout << "paying " << bribery[v.first] << endl;
				pay += bribery[v.first];
				q.push(v.first);
			}
		} 
	}
}

bool comp(pll a,pll b)
{
	return a.first/(double)a.second > b.first/(double)b.second;
}

int main()
{
	while(cin >> d)
	{
		cin >> p; cin >> r;cin >> b;

		bribery.clear();
    	bribery.assign(d+p,0);

    	for (int i = 0; i < d; ++i)
    	{
    		int mon; cin >> mon;
    		bribery[i]=mon;
    	}
    	for (int i = 0; i < p; ++i)
    	{
    		int mon; cin >> mon;
    		bribery[i+d] = mon;
    	}

		unvisited.clear();
    	unvisited.assign(d+p,1);
    	AdjList.clear();
    	AdjList.assign(d+p,vii());

    	for (int i = 0; i < r; ++i)
    	{
    		int from,to; 
    		cin >> from;cin >> to;
    		to--;
    		from--;
    		ii a(to+d,0);
    		ii b(from,0);
    		AdjList[from].push_back(a);
    		AdjList[to+d].push_back(b);
    	}
    	comps.clear();
    	for (int i = 0; i < d+p; ++i)
    	{
    		if(unvisited[i])
    		{
    			pay = gain = 0;
    			bfs(i);
    			comps.push_back(make_pair(gain,pay));
    		}
    	}

    	stable_sort(comps.begin(),comps.end(),comp);

    	for (int i = 0; i < comps.size(); ++i)
    	{
    		cout << "comp " << i << " : " << comps[i].first << "," << comps[i].second << endl;
    	}
    	long people = d;
    	long budget = b;
    	int c =0;
    	while(budget>0 && comps[c].first>0)
    	{
    		if(budget - comps[c].second > 0)
    		{
    			people += comps[c].first;
    		}
    		budget -= comps[c].second;
    		c++;
    	}
    	cout << people << " ";
    	people = p;
    	budget = b;
    	c = comps.size()-1;
    	while(budget>0 && comps[c].first < 0)
    	{
    		if(budget - comps[c].second > 0)
    		{
    			people += -1*comps[c].first;
    		}
    		budget -= comps[c].second;
    		c--;
    	}
    	cout << people << endl;
	}
    return 0;
}