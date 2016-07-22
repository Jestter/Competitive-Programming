#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cant;
	while(scanf("%d\n",&cant),cant!=0)
	{
		unordered_map<string,int> IDS;
		vector<string> names;
		vector<vector<int> > G(cant,vector<int>());
		vector<vector<int> > to(cant,vector<int>());
		int count = 0;
		for (int i = 0; i < cant; ++i)
		{
			string line; getline(cin,line);
			stringstream ss; ss << line;
			string wd; ss >> wd;
			if(IDS.count(wd)==0)
			{
				IDS[wd]=count++;
				names.push_back(wd);
			}
			int id = IDS[wd];
			//cout << id << "." <<wd << " : ";
			while(ss >> wd)
			{
				if(IDS.count(wd)==0)
				{
					IDS[wd]=count++;
					names.push_back(wd);
				}
				G[IDS[wd]].push_back(id);
				to[id].push_back(IDS[wd]);
				//cout << IDS[wd] << "." <<wd << " ";
			}
		}

		vector<string> solu;
		int erased[cant]; memset(erased,0,sizeof(erased));
		int au[cant]; memset(au,0,sizeof(au));

		queue<int> Q;
		for (int i = 0; i < cant; ++i)
		{
			Q.push(i);
		}

		while(!Q.empty())
		{
			int n = Q.front();Q.pop();
			if(G[n].size()-au[n]==0 && !erased[n])
			{
				erased[n]=1;
				for (int i = 0; i < to[n].size(); ++i)
				{
					au[to[n][i]]++;
					Q.push(to[n][i]);
				}
			}
		}

		for (int i=0;i<G.size();i++)
		{
			if(G[i].size()-au[i]>0)solu.push_back(names[i]);
		}

		sort(solu.begin(),solu.end());

		cout << solu.size() << endl;
		for(int i = 0;i<solu.size();i++)
		{
			cout << solu[i] << ((i+1==solu.size())?"":" ");
		}
		cout << endl;
	}
	return 0;
} 