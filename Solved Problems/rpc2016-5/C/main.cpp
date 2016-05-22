#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	while(cin >> s)
	{
		unordered_map<char,int> mp;
		int count = 1;
		for(char c:s)
		{
			if(mp.count(c)==0)mp[c]=count++;
		}
		string res="";
		for(char c:s)
		{
			res += to_string(mp[c]);
		}

		for(char c:res)
		{
			if(c == '2')cout << '5';
			else if(c == '5')cout << '2';
			else if(c == '6')cout << '9';
			else if(c == '9')cout << '6';
			else cout << c;
		}
		cout << endl;
	}
}