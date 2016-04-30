#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	string s,t;
	cin >> s;
	cin >> t;
	int pre[26];
	int post[26];
	memset(pre,0,sizeof(pre));
	memset(post,0,sizeof(post));
	post[t[0]-'a'] |= 1 << (t[1]-'a');
	pre[t[t.length()-1]-'a'] |= 1 << (t[t.length()-2]-'a');
	for (int i = 1; i < t.length()-1; ++i)
	{
		pre[t[i]-'a'] |= 1<< (t[i-1]-'a');
		post[t[i]-'a'] |= 1<< (t[i+1]-'a');
	}

	int sets1[s.length()];
	int sets2[s.length()];
	memset(sets1,0,sizeof(sets1));
	memset(sets2,0,sizeof(sets2));
	sets1[0] |= 1 << (s[0]-'a');
	if(!(sets1[0]&pre[s[0]-'a']) && s[0]!=t[0])
	{
		//cout << "idx " << 0 << endl;
		cout << "No";
		return 0;
	}
	for (long i = 1; i < s.length(); ++i)
	{
		int n = s[i]-'a';
		sets1[i] = sets1[i-1] | 1 <<n;
		if(!(sets1[i]&pre[n]) && s[i]!=t[0])
		{
			//cout << "idx " << i << endl;
			cout << "No";
			return 0;
		}
	}
	sets2[s.length()-1] |= 1 << (s[s.length()-1]-'a');
	if(!(sets2[s.length()-1]&post[s[s.length()-1]-'a']) && s[s.length()-1]!=t[t.length()-1])
	{
		//cout << "idx " << (s.length()-1) << endl;
		cout << "No";
		return 0;
	}
	for (long i = s.length()-2; i >= 0; --i)
	{
		int n = s[i]-'a';
		sets2[i] = sets2[i+1] | 1 <<n;
		if(!(sets2[i]&post[n]) && s[i]!=t[t.length()-1])
		{
			//cout << "idx " << i << endl;
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

	return 0;
}