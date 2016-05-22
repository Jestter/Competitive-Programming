#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;

string iii_to_s(iii x)
{
	return to_string(x.first)+","+to_string(x.second.first)+","+to_string(x.second.second);
}

int main()
{
	int  r,c,h;
	while(scanf("%d %d %d\n",&r,&c,&h))
	{
		if(!r&&!c&&!h)break;
		//printf("%d %d %d\n",r,c,h);
		char lab[h][r][c];
		iii s,e;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				for (int k = 0; k < c; ++k)
				{
					scanf("%c",&lab[i][j][k]);
					//printf("%c",lab[i][j][k]);
					if(lab[i][j][k]=='S'){s= make_pair(i,ii(j,k));}
					if(lab[i][j][k]=='E'){e= make_pair(i,ii(j,k));}
				}
				scanf("\n");
				//printf("\n");
			}
			scanf("\n");
			//printf("\n");
		}

		unordered_map<string,int> dist; dist[iii_to_s(s)] = 0;
		queue<iii> q; q.push(s);
		unordered_map<string,string> p;
		while (!q.empty()) 
		{
			//cout << "agg"<<endl;
			iii u = q.front(); q.pop();
			int f=u.first,x = u.second.second,y=u.second.first;
			if(y+1<r && lab[f][y+1][x]!='#')
			{
				iii v = make_pair(f,ii(y+1,x));
				if (dist.count(iii_to_s(v))==0)
				{
					dist[iii_to_s(v)] = dist[iii_to_s(u)] + 1;
					p[iii_to_s(v)]=iii_to_s(u);
					q.push(v);
				}
			}
			if(y>0 && lab[f][y-1][x]!='#')
			{
				iii v = make_pair(f,ii(y-1,x));
				if (dist.count(iii_to_s(v))==0)
				{
					dist[iii_to_s(v)] = dist[iii_to_s(u)] + 1;
					p[iii_to_s(v)]=iii_to_s(u);
					q.push(v);
				}
			}
			if(x+1<c && lab[f][y][x+1]!='#')
			{
				iii v = make_pair(f,ii(y,x+1));
				if (dist.count(iii_to_s(v))==0)
				{
					dist[iii_to_s(v)] = dist[iii_to_s(u)] + 1;
					p[iii_to_s(v)]=iii_to_s(u);
					q.push(v);
				}
			}
			if(x>0 && lab[f][y][x-1]!='#')
			{
				iii v = make_pair(f,ii(y,x-1));
				if (dist.count(iii_to_s(v))==0)
				{
					dist[iii_to_s(v)] = dist[iii_to_s(u)] + 1;
					p[iii_to_s(v)]=iii_to_s(u);
					q.push(v);
				}
			}
			if(f+1<h && lab[f][y][x]=='-' && lab[f+1][y][x]=='-')
			{
				iii v = make_pair(f+1,ii(y,x));
				if (dist.count(iii_to_s(v))==0)
				{
					dist[iii_to_s(v)] = dist[iii_to_s(u)] + 1;
					p[iii_to_s(v)]=iii_to_s(u);
					q.push(v);
				}
			}
			if(f>0 && lab[f][y][x]=='-' && lab[f-1][y][x]=='-')
			{
				iii v = make_pair(f-1,ii(y,x));
				if (dist.count(iii_to_s(v))==0)
				{
					dist[iii_to_s(v)] = dist[iii_to_s(u)] + 1;
					p[iii_to_s(v)]=iii_to_s(u);
					q.push(v);
				}
			}
			
		}

		printf("%d\n",dist[iii_to_s(e)]);

	}

}