#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		bool b = true; int last;
		cin >> last;
		for (int i = 0; i < 4; ++i)
		{
			int n; cin >> n;
			if(n != last+1)b = false;
			last = n;
		}
		cout << (b?"Y":"N") << endl;
	}
}