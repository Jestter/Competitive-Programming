//Uva 11503
#include <bits/stdc++.h>

using namespace std;

class UnionFind 
{
	private: unordered_map<int,int> p, rank; unordered_map<int,long> size; // remember: vi is vector<int>
	public:
		UnionFind(int N) 
		{ 
			//rank.assign(N, 0);
			//p.assign(N, 0); 
			//for (int i = 0; i < N; i++) p[i] = i; 
		}
		int findSet(int i) { if(p.count(i)==0){p[i]=i;size[i]=1;} return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j)
		{
			if (!isSameSet(i, j)) 
			{ // if from different set
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) {p[y] = x; size[x] += size[y];} // rank keeps the tree short
				else 
				{ 
					p[x] = y;
					size[y] += size[x];
					if (rank[x] == rank[y]) rank[y] = rank[y]+1; 
				}
			} 
		} 

		int getSize(int i)
		{
			return size[findSet(i)];
		}
};

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		UnionFind uf(0);
		unordered_map<string,int> id;
		int idcount = 0;
		int ppl;
		cin >> ppl;
		for (int i = 0; i < ppl; ++i)
		{
			string p1, p2;
			cin >> p1 >> p2;
			if(id.count(p1)==0)id[p1]=idcount++;
			if(id.count(p2)==0)id[p2]=idcount++;

			uf.unionSet(id[p1],id[p2]);
			cout << uf.getSize(id[p1]) << endl;
		}
	}
	return 0;
}