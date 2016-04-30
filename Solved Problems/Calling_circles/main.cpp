#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter,numSCC,UNVISITED=-1,VISITED=1;

int INF = INT_MAX;

map<string,int> toNum;
map<int,string> toName;

void tarjanSCC(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	S.push_back(u);
	// stores u in a vector based on order of visitation
	visited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) 
	{
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED)
		tarjanSCC(v.first);
		if (visited[v.first])
		// condition for update
		dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}
	if (dfs_low[u] == dfs_num[u])
	{
		bool agg = false;
		while (1) 
		{
			int v = S.back(); S.pop_back(); visited[v] = 0;
			cout << toName[v] << ((u==v)?"":", ");
			if (u == v) break; 
		}
		printf("\n");
	} 
}

int main()
{
	int n,m;
	int asd=1;
    while(scanf("%d %d\n",&n,&m)&& (n||m))
    {
    	if(asd>1)printf("\n");
    	AdjList.clear();
    	AdjList.assign(n,vii());
    	toName.clear();
    	toNum.clear();

    	int c=0;
    	for (int i = 0; i < m; ++i)
    	{
    		string from,to;
    		cin >> from;
    		cin >> to;
    		if(toNum.count(from)==0)
    		{
    			toNum[from]=c;
    			toName[c]=from;
    			c++;
    		}
    		if(toNum.count(to)==0)
    		{
    			toNum[to]=c;
    			toName[c]=to;
    			c++;
    		}
    		AdjList[toNum[from]].push_back(ii(toNum[to],0));
    	}
    	printf("Calling circles for data set %d:\n", asd);
    	dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0); visited.assign(n, 0);
		dfsNumberCounter = numSCC = 0;
		for (int i = 0; i < n; i++)
			if (dfs_num[i] == UNVISITED)
				tarjanSCC(i);
		asd++;
    }
    return 0;
}