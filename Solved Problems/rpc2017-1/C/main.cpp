#include <bits/stdc++.h>

using namespace std;

struct Name{
	string fn;
	string ln;

	Name(string fn,string ln):fn(fn),ln(ln){}
};

bool comp(Name a,Name b)
{
	if(a.ln.compare(b.ln) == 0){
		return a.fn.compare(b.fn) < 0;
	}
	return a.ln.compare(b.ln) < 0;
}

int main()
{
	int cant = 0;
	cin >> cant;
	vector<Name> names;

	while(cant--)
	{
		string fn,ln;
		cin >> fn >> ln;
		names.push_back(Name(fn,ln));
	}
	stable_sort(names.begin(), names.end(),comp);
	for(int i=0;i<names.size();i++){
		cout << names[i].fn << " " << names[i].ln << endl;
	}
}