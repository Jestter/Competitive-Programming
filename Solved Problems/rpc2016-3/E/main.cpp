#include <bits/stdc++.h>

using namespace std;

string extract(string s)
{
	string r;
	for (int i = 1; i < s.length(); i+=2)
	{
		r+=s[i];
	}
	return r;
}

int main()
{
	long long N;long long T;
	char D;

	while(cin >> N)
	{
		cin >> T;
		cin >> D ;cin.get();
		string ue,le,text;
		getline(cin,ue);
		getline(cin,text);
		getline(cin,le);

		text = extract(text);
		T%=N;
		if(D == 'R') T = N-T;
		cout << ue << endl;
		for (int i = T; i < N; i++)
		{
			cout << "|" << text[i];
		}
		for (int i = 0; i < T; i++)
		{
			cout << "|" << text[i];
		}
		cout << "|" << endl << le << endl;

	}
}