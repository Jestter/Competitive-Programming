//Uva 10895
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		vector<pair<int,int> > mat[n+1];
		for (int i = 0; i < m; ++i)
		{
			int cant; scanf("%d",&cant);
			//cout << cant << endl;
			if(cant == 0)continue;
			int cols[cant];
			for (int j = 0; j < cant; ++j)
			{
				scanf("%d",&cols[j]);
				//cout << cols[j] <<" ";
			}
			//cout << endl;
			for (int j = 0; j < cant; ++j)
			{
				int num; scanf("%d",&num);
				//cout << num << " ";
				mat[cols[j]].push_back(make_pair(i+1,num));
			}
			//cout << endl;
		}

		printf("%d %d\n", n,m);

		for (int i = 1; i <= n; ++i)
		{
			stable_sort(mat[i].begin(),mat[i].end());
			printf("%d",((int)mat[i].size()));
			for(pair<int,int> p:mat[i])
			{
				printf(" %d", p.first);
			}
			printf("\n");
			for(int j=0;j<mat[i].size();j++)
			{
				printf("%d", mat[i][j].second);
				if(j+1!=mat[i].size())printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
