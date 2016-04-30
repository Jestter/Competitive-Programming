#include <bits/stdc++.h>

using namespace std;

typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &p)const{return x > p.x;}
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

typedef pair<PT, PT> ppt;

bool comp(ppt p1,ppt p2)
{
	return p1.first.x < p2.first.x; 
}

typedef vector<long> vi;

class FenwickTree {
private: vi ft;
	// recall that vi is: typedef vector<int> vi;
public: 
	FenwickTree(long n) { ft.assign(n + 1, 0); }
	// init n + 1 zeroes
	long LSOne(long n){return (n & (-n));}
	long long rsq(long b) 
	{
		// returns RSQ(1, b)
		long long sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum; 
	}
	long long rsq(long a, long b) 
	{
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(long k, long v)
	{
		// note: n = ft.size() - 1
		for (; k < (long)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int main()
{
	long p,v;
	while(cin >> p)
	{
		cin >> v;

		vector<PT> plants;
		vector<ppt> tramos;
		set<long long> setqlo;
		map<pair<long long,long long>,long> order;

		bool pb[p];
		memset(pb,0,sizeof(pb));
		for (long i = 0; i < p; ++i)
		{
			long long x,y;
			cin >> x;
			cin >> y;
			setqlo.insert(y);
			plants.push_back(PT(x,y));
			order[make_pair(x,y)]=i;
		}

		long long xant,yant;cin >> xant;cin >> yant;
		long long firstx = xant,firsty=yant;
		setqlo.insert(yant);
		for (long i = 1; i < v; ++i)
		{
			long long x,y;
			cin >> x;cin >> y;
			setqlo.insert(y);
			if(xant==x)
			{
				tramos.push_back(ppt(yant<y?PT(xant,yant):PT(x,y),yant<y?PT(x,y):PT(xant,yant)));
			}
			yant = y;xant = x;
		}
		if(xant == firstx)
		{
			tramos.push_back(ppt(yant<firsty?PT(xant,yant):PT(firstx,firsty),yant<firsty?PT(firstx,firsty):PT(xant,yant)));
		}

		unordered_map<long long,long> mapll;
		long county = 1;
		for(set<long long>::iterator it = setqlo.begin(); it!= setqlo.end();++it)
		{
			mapll[*it]=county++;
		}

		stable_sort(tramos.begin(),tramos.end(),comp);
		stable_sort(plants.begin(),plants.end());

		FenwickTree fen(county+100);
		for (long i = 0; i < tramos.size(); ++i)
		{
			fen.adjust(mapll[tramos[i].first.y],+1);
			fen.adjust(mapll[tramos[i].second.y],-1);
		}

		long lastidx = tramos.size()-1;
		for (long j = 0; j < plants.size(); ++j)
		{
			for (; lastidx >=0 && tramos[lastidx].first.x > plants[j].x; --lastidx)
			{	
				fen.adjust(mapll[tramos[lastidx].first.y],-1);
				fen.adjust(mapll[tramos[lastidx].second.y],+1);
			}
			long long numerito = fen.rsq(mapll[plants[j].y]);
			//cout << numerito << endl;
			pb[order[make_pair(plants[j].x,plants[j].y)]]= numerito%2;
		}

		long long count = 0;
		for (long i = 0; i < p; ++i)
		{
			if(!pb[i])count+=(i+1);
			//cout << pb[i];
		}
		cout << count << endl;
	}
    return 0;
}