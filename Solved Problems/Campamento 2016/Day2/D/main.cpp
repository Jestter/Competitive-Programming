#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

double maxd = 99999999999;


vector<ii> parts;

bool check(double T)
{
	vector<double> postpos(parts.size(),0);
	double anterior;
	double lala = -maxd;
	for (int i=0;i<parts.size();i++)
	{
		postpos[i] = parts[i].first + ((double)parts[i].second) * T;
		
		if(parts[i].second > 0 && postpos[i]>lala)
		{
			lala = postpos[i];
		}
		else if(postpos[i] <= lala && parts[i].second < 0)
		{
			return true;
		}
	}
	return false;

}

int main()
{
	int ps;
	cin >> ps;

	int bigbang = 2;
	while(ps--)
	{
		int x,v;
		cin >> x >> v;
		parts.push_back(make_pair(x,v));
		//cout << x << " " << v << endl;
		if(v > 0 && bigbang==2)bigbang--;
		else if(v < 0 && bigbang==1)bigbang--;
	}

	if(bigbang!=0)
	{
		cout << -1;return 0;	
	}

	double ini=0,end=1000000001;
	if(!check(end))
	{
		cout << -1;return 0;
	}
	double last = 2000000001;
	while(true)
	{
		double value = (end+ini)/2;
		//printf("%.15f\n",value);
		bool b = check(value);
		if(fabs(value-last) < 0.000000001)
		{
			printf("%.10f",value);
			return 0;
		}
		if(!b)
		{
			//cout << "f" << endl;
			ini = value;
		}
		if(b)
		{
			//cout << "t" << endl;
			end = value;
		}
		last = value;
	}

	return 0;
}