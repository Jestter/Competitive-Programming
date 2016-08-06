#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC; cin >> TC;
	while(TC--)
	{
		long cont; cin >> cont;
		unordered_map<string,long> numbers;
		vector<vector<long> > V(3000, vector<long>());
		int contador = 0;
		for (long i = 0; i < cont; ++i)
		{
			string s1,s2;
			cin >> s1 >> s2;
			if(numbers.count(s1)==0)numbers[s1]=contador++;
			if(numbers.count(s2)==0)numbers[s2]=contador++;
			//cout << numbers[s1] << " to " << numbers[s2] << endl;
			V[numbers[s1]].push_back(numbers[s2]);
			V[numbers[s2]].push_back(numbers[s1]);
		}

		long onlist = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			vector<long> dist(numbers.size(),-1);
			dist[i]=0;
			queue<long> Q; Q.push(i);
			bool endq = false;
			while(!Q.empty() && !endq)
			{
				long u = Q.front(); Q.pop();
				//cout << u << " " << dist[u] << " | ";
				for (long j = 0; j < V[u].size(); ++j)
				{
					long v = V[u][j];
					if(dist[v] == -1)
					{
						dist[v] = dist[u] +1;
						if(dist[v]>6) 
						{
							onlist++;
							endq = true;
							break;
						}
						Q.push(v);
					}
					
				}
			}
			//cout << endl;
		}
		//cout << onlist << " " << numbers.size() << endl;
		cout << (onlist*20 > numbers.size()?"NO":"YES") << endl;
		
	}
}