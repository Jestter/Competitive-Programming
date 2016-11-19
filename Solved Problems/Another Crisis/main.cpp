#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VII;

int employees,parameter;
VII adjList;

int traverse(int node)
{
	int n_emps = adjList[node].size();
	if(n_emps == 0)return 1;
	priority_queue<int, VI, greater<int> > pq; //cola de prioridad para menores
	for (int i = 0; i < n_emps; ++i)
	{
		int min_emps_i = traverse(adjList[node][i]);
		pq.push(min_emps_i);
	}

	int threshold = (int)ceil(n_emps*(parameter/100.0));
	
	int direct_emps_count = 0;
	int min_emps_node = 0;
	while(direct_emps_count < threshold && !pq.empty())
	{
		int emps = pq.top();
		pq.pop();
		direct_emps_count++;
		min_emps_node += emps;
	}

	return min_emps_node;
}

int main()
{
	scanf("%d %d",&employees, &parameter);
	while(employees && parameter)
	{
		adjList.clear();
		adjList.assign(employees+1, VI());

		for (int i = 1; i <= employees; ++i)
		{
			int boss;
			scanf("%d",&boss);
			adjList[boss].push_back(i);
		}

		printf("%d\n", traverse(0));
		scanf("%d %d",&employees, &parameter);
	}
}