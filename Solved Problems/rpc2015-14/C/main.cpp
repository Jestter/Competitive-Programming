#include <bits/stdc++.h>

using namespace std;

char per[3]={'P','E','R'};

int main()
{
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]!=per[i%3])count++;
	}
	cout << count << endl;
    return 0;
}