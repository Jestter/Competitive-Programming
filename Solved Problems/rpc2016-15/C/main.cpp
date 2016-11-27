#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<string,string> &p1,const pair<string,string> &p2)
{
	if(p1.first.compare(p2.first)==0)
	{
		return (p1.second.compare(p2.second) > 0);
	}

	return (p1.first.compare(p2.first) < 0);
}

int main()
{
	int total;
	cin >> total;

	vector<pair<string,string> > v (total, make_pair("",""));

	for (int i = 0; i < total; ++i)
	{
		//cout << i << endl;
		string name;
		cin >> name;
		v[i].second = name.substr(0,name.length()-1);
		string aux;
		cin >> aux;
		while(aux[0] != 'c')
		{
			//cout << aux << endl;
			v[i].first = aux[0] + v[i].first;
			cin >> aux;
		}

		if(v[i].first.length() < 45)
		{
			int l = v[i].first.length();
			//cout << v[i].first.length()<< endl;
			for (int j = 0; j < 45-l; ++j)
			{
				v[i].first += "m";
			}
		}
		scanf("\n");
	}
	
	sort(v.begin(), v.end(),comp);
	for (int i = v.size()-1; i >= 0; --i)
	{
		cout << v[i].second << endl;
	}
}