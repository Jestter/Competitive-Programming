#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class FenwickTree {
private: vi ft;
	// recall that vi is: typedef vector<int> vi;
public: 
	FenwickTree(int n) { ft.assign(n + 1, 0); }
	// init n + 1 zeroes
	int LSOne(int n){return (n & (-n));}
	int rsq(int b) 
	{
		// returns RSQ(1, b)
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum; 
	}
	int rsq(int a, int b) 
	{
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v)
	{
		// note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int size;

int getReflex(int idx)
{
	return (size-idx+1);
}

int main()
{
	string s;
	cin >> s;
	size = s.length();
	int m;
	cin >> m;
	FenwickTree ft(2e5+100);
	for (int i = 0; i < m; ++i)
	{
		int agg;
		cin >> agg;
		ft.adjust(agg,1);
		ft.adjust(getReflex(agg)+1,-1);
	}

	for (int i = 0; i < size; ++i)
	{
		if(ft.rsq(i+1)%2==0)cout << s[i];
		else cout << s[getReflex(i+1)-1];
	}

    return 0;
}