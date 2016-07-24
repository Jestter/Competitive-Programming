#include <bits/stdc++.h>

using namespace std;

class UnionFind 
{
	private: unordered_map<int,int> p, rank; // remember: vi is vector<int>
	public:
		UnionFind(int N) 
		{ 
			//rank.assign(N, 0);
			//p.assign(N, 0); 
			//for (int i = 0; i < N; i++) p[i] = i; 
		}
		int findSet(int i) { if(p.count(i)==0)p[i]=i; return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j) 
		{
			if (!isSameSet(i, j)) 
			{ // if from different set
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
				else 
				{ 
					p[x] = y;
					if (rank[x] == rank[y]) rank[y] = rank[y]+1; 
				}
			} 
		} 
};

int main()
{
	int l;
	while(cin >> l)
	{
		if(l==-1)continue;
		UnionFind uf((l+1)*2);
		int q; cin >> q;
		int i;
		int res = q;
		for (i = 0; i < q; ++i)
		{
			int a,b;
			string p;
			cin >> a >> b >> p;
			if(p[0]=='e')
			{
				uf.unionSet((a-1)*2, b*2);
				uf.unionSet((a-1)*2+1, b*2+1);
			}
			else
			{
				uf.unionSet((a-1)*2, b*2+1);
				uf.unionSet((a-1)*2+1, b*2);
			}

			if((uf.isSameSet((a-1)*2,(a-1)*2+1) || uf.isSameSet(b*2,b*2+1))&& res == q)res = i;
		}
		cout << res << endl;
	}
	return 0;
}