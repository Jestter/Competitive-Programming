#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int count = 1;
	for (int i = 1; i < s.length(); ++i)
	{
		if(s[i]!=s[i-1])count =0;
		count++;
		if(count == 7)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}