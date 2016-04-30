#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	string simon = "Simon says ";
	while(TC--)
	{
		string s;
		scanf("\n");
		getline(cin,s);
		
		int i = 0;
		for (; i < 11; ++i)
		{
			if(s[i]!=simon[i])
			{
				i = -1;
				break;
			}
		}
		if(i!=-1)
		{
			cout << " " << (s.substr(i,s.length())) << endl;
		}
	}
    return 0;
}