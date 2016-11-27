#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string type;int oper;
	int actualnum = 0;
	
	vector<pair<string,int> > v;
	for (int i = 0; i < n; ++i)
	{
		cin >> type >> oper;
		v.push_back(make_pair(type,oper));
	}

	int counter = 0;
	for (int i = 1; i <= 100; ++i)
	{
		int num = i;
		for (int j = 0; j < v.size(); ++j)
		{
			//cout << v[j].first <<" "<< v[j].second <<endl;
			if(v[j].first[0]=='A')num+=v[j].second;
			if(v[j].first[0]=='M')num*=v[j].second;
			if(v[j].first[0]=='S')num-=v[j].second;
			if(v[j].first[0]=='D')
			{
				//cout << "dividing" << endl;
				int tmp=num/v[j].second;
				//cout << (tmp*v[j].second) << endl;
				if(tmp*v[j].second != num)
				{
					counter++;
					break;
				}
				num = tmp;
			}

			if(num < 0)
			{
				counter++;
				break;
			}
			//cout << num << endl;
		}
	}
	cout << counter << endl;
}