#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vector<int> unvisited;

int dest = -1;

void bfs(int s)
{
	unvisited[s] = s;
    queue<int> q; q.push(s);
	while (!q.empty()) 
	{
		int u = q.front(); q.pop();
		for (int j = 0; j < (int)AdjList[u].size(); j++) 
		{
			ii v = AdjList[u][j];
			if (unvisited[v.first]==-1)
			{
				unvisited[v.first] = u;

				if(dest == v.first)return;
				q.push(v.first);
			}
		} 
	}
}

map<int,string> names;
map<string,int> numbers;

int main()
{
	int N;
	cin >> N;
	scanf("\n");
	int ns = 0;
	unvisited.clear();
	unvisited.assign(N*N,-1);
	AdjList.clear();
	AdjList.assign(N*N,vii());

	for (int i = 0; i < N; ++i)
	{
		string line;
		getline(cin, line);
		istringstream iss(line);
		string name;
		iss >> name;
		
		if(numbers.count(name)==0)
		{
			names[ns]=name;
			numbers[name]=ns;
			ns++;
		}
		string s;

		while ( iss >> s)
		{    
			
	   		if(numbers.count(s)==0)
			{
				
				names[ns]=s;
				numbers[s]=ns;
				ns++;
			}
			int ori=numbers[name],des=numbers[s];
			
			AdjList[ori].push_back(make_pair(des,0));
			AdjList[des].push_back(make_pair(ori,0));
	    }
	}

	string origin,destination;
	cin >> origin;
	cin >> destination;
	if(numbers.count(origin)==0 || numbers.count(destination)==0)
	{
		cout << "no route found" << endl;
		return 0;
	}
	dest = numbers[origin];
	bfs(numbers[destination]);

	if(unvisited[dest]==-1)
	{
		cout << "no route found" << endl;
		return 0;
	}

	while(dest != numbers[destination])
	{
		cout << names[dest] << " ";
		dest = unvisited[dest];
	}
	cout << destination << endl;
}