#include <bits/stdc++.h>
using namespace std;

vector<int> v['z'-'a'+1];
int wl;

int distance(int idx,char c)
{
	vector<int> v2 = v[c-'a'];
	int min = INT_MAX;
	if(v2.size()==0)return wl;
	for (int i = 0; i < v2.size(); ++i)
	{
		int d = abs(idx-v2[i]);
		min = min < d?min:d;
	}
	return min;
}

void printV()
{
	for (int i = 0; i < 'z'-'a'+1; ++i)
	{
		cout << (char)(i+'a') << ":" << endl;
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{	
	int p;
	char nline;
	scanf("%d %d%c",&p,&wl,&nline);
	for (int i = 0; i < wl; ++i)
	{
		char c;
		scanf("%c",&c);
		v[c-'a'].push_back(i);
	}
	scanf("%c",&nline);
	//printV();
	for (int i = 0; i < p; ++i)
	{
		string s;
		getline(cin,s);
		unsigned long long F = 0;
		wl = s.length();
		for (int i = 0; i < wl; ++i)
		{
			int d = distance(i,s[i]);
			F += d;
		}
		cout << F << endl;
	}



    return 0;
}
