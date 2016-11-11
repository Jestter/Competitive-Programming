#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 0

unordered_map<string, int> toNum;
vector<vector<int> > graph;
vector<int> ranking;
vector<pair<int,int> > llegan;
bool posible = true;
int maxnum = 0;

void dfs(int u, int rk)
{
	ranking[u] = rk;
	for( int r: graph[u])
	{
		if(ranking[r]==UNVISITED)
		{
			dfs(r,ranking[u]+1);
		}
		else if(ranking[r] < ranking[u])
		{
			//cout << "falla cuz " << r << " < " << u << endl;
			posible = false;
			return;
		}

		
	}
}

bool comp(const pair<int,int> i1,const pair<int,int> i2)
{
	return i1.second < i2.second;
}

int main()
{
	int L;
	cin >> L;

	graph.assign(10005,vector<int>());
	ranking.assign(10005,UNVISITED);
	llegan.assign(10005,make_pair(0,0));
	
	while(L--)
	{
		string name1,name2,symbol;
		cin >> name1 >> symbol >> name2;

		if(toNum.count(name1) == 0)toNum[name1] = maxnum++;
		if(toNum.count(name2) == 0)toNum[name2] = maxnum++;

		if(symbol[0] == '>')
		{
			graph[toNum[name1]].push_back(toNum[name2]);
			llegan[toNum[name2]] = make_pair(toNum[name2],llegan[toNum[name2]].second+1);
		}
		else
		{
			graph[toNum[name2]].push_back(toNum[name1]);
			llegan[toNum[name1]] = make_pair(toNum[name1],llegan[toNum[name1]].second+1);
		}
	}

	stable_sort(llegan.begin(), llegan.end(),comp);

	for (int i = 0; i < maxnum; ++i)
	{
		int a = llegan[i].first;
		if(ranking[a] == UNVISITED)
		{
			dfs(a,1);
		}
	}

	cout << (posible?"possible":"impossible") << endl;
	return 0;
}