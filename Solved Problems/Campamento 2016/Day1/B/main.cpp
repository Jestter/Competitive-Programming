#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 0

typedef pair<int,int> ii;

int size,steps;
char forest[800][800];

vector<ii> iniBee;
ii bear;
ii house;

bool simulate(int time)
{
	set<ii> bees(iniBee.begin(),iniBee.end());  
	for (int i = 0; i < time; ++i)
	{
		for (set<ii>::iterator it = bees.begin(); it != bees.end(); ++it)
		{
			if((*it).first+1<size && forest[(*it).first+1][(*it).second]=='G')bees.insert(make_pair((*it).first+1,(*it).second));
			if((*it).first-1>=0 && forest[(*it).first-1][(*it).second]=='G')bees.insert(make_pair((*it).first-1,(*it).second));
			if((*it).second+1<size && forest[(*it).first][(*it).second+1]=='G')bees.insert(make_pair((*it).first,(*it).second+1));
			if((*it).second-1>=0 && forest[(*it).first][(*it).second-1]=='G')bees.insert(make_pair((*it).first,(*it).second-1));
		}
	}

	ii weon = bear;
	while(weon.first != house.first || weon.second != house.second)
	{
		map<ii,int> dist;
		map<ii,ii> parent;
		queue<ii> Q;
		dist[weon] = 1;parent[weon] = weon; Q.push(weon);
		while(!Q.empty())
		{
			ii u = Q.front();Q.pop();
			if(u == house) break;
			if(u.first+1<size && (forest[u.first+1][u.second]=='G'||forest[u.first+1][u.second]=='D') && bees.count(make_pair(u.first+1,u.second))==0)
			{
				ii par = make_pair(u.first+1,u.second);
				if(dist[par] == UNVISITED)
				{
					dist[par] = dist[u]+1;
					parent[par] = u;
					Q.push(par);
				}
			}
			if(u.first-1>=0 && (forest[u.first-1][u.second]=='G'||forest[u.first-1][u.second]=='D') && bees.count(make_pair(u.first-1,u.second))==0)
			{
				ii par = make_pair(u.first-1,u.second);
				if(dist[par] == UNVISITED)
				{
					dist[par] = dist[u]+1;
					parent[par] = u;
					Q.push(par);
				}
			}
			if(u.second+1<size && (forest[u.first][u.second+1]=='G'||forest[u.first][u.second+1]=='D') && bees.count(make_pair(u.first,u.second+1))==0)
			{
				ii par = make_pair(u.first,u.second+1);
				if(dist[par] == UNVISITED)
				{
					dist[par] = dist[u]+1;
					parent[par] = u;
					Q.push(par);
				}
			}
			if(u.second-1>=0 && (forest[u.first][u.second-1]=='G'||forest[u.first][u.second-1]=='D') && bees.count(make_pair(u.first,u.second-1))==0)
			{
				ii par = make_pair(u.first,u.second-1);
				if(dist[par] == UNVISITED)
				{
					dist[par] = dist[u]+1;
					parent[par] = u;
					Q.push(par);
				}
			}
		}

		if(dist[house]==UNVISITED)return false;

		ii next = house;
		while(dist[next]>steps)
		{
			next = parent[next];
		}

		weon = next;

		for (set<ii>::iterator it = bees.begin(); it != bees.end(); ++it)
		{
			if((*it).first+1<size && forest[(*it).first+1][(*it).second]=='G')bees.insert(make_pair((*it).first+1,(*it).second));
			if((*it).first-1>=0 && forest[(*it).first-1][(*it).second]=='G')bees.insert(make_pair((*it).first-1,(*it).second));
			if((*it).second+1<size && forest[(*it).first][(*it).second+1]=='G')bees.insert(make_pair((*it).first,(*it).second+1));
			if((*it).second-1>=0 && forest[(*it).first][(*it).second-1]=='G')bees.insert(make_pair((*it).first,(*it).second-1));
		}
	}
	return true;
}

int main()
{
	int TC;
	cin >> TC;
	while(TC--)
	{
		cin >> size >> steps;
		for (int i = 0; i < size; ++i)
		{
			string s; getline(cin,s);
			for (int j = 0; j < size; ++j)
			{
				forest[j][i] = s[j];
				if(s[j]=='M')bear = make_pair(j,i);
				if(s[j]=='D')house = make_pair(j,i);
				if(s[j]=='H')iniBee.push_back(make_pair(j,i));
			}
		}
		int lower =0,upper=800*800+1;
		int putotiempo = (upper-lower)/2;
		cout << "empezando bs" << endl;
		while(true)
		{
			bool b = simulate(putotiempo);
			bool bma1 = simulate(putotiempo+1);
			if(b && !bma1)break;
			if(b)
			{
				lower = putotiempo;
				putotiempo = (upper-lower)/2;
				cout << "true "<< putotiempo << endl;
			}
			else
			{
				upper = putotiempo;
				putotiempo = (upper-lower)/2;
				cout << "false "<<putotiempo << endl;
			}
		}
		cout << putotiempo << endl;
	}
	return 0;
}