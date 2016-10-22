//Uva 10646
#include <bits/stdc++.h>

using namespace std;

struct Card{
	char cvalue;
	int value;
	char suit;

	Card(string s)
	{
		cvalue = s[0];
		if(s[0] >= '2' && s[0] <= '9')value = s[0]-'0';
		else value = 10;
		suit = s[1];
	}

	string toString()
	{
		string s = "  ";
		s[0] = cvalue; s[1] = suit;
		return s;
	}
};

int main()
{
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t)
	{
		deque<Card> deq; //top es back
		deque<Card> rest;  //top es back
		for (int i = 0; i < 52-25; ++i)
		{
			string s;
			cin >> s;
			deq.push_back(Card(s));
		}
		for (int i = 0; i < 25; ++i)
		{
			string s;
			cin >> s;
			rest.push_back(Card(s));
		}

		int y = 0;
		for (int i = 0; i < 3; ++i)
		{
			Card top = deq.back();deq.pop_back();
			y += top.value;
			for (int j = 0; j < (10-top.value); ++j)
			{
				deq.pop_back();
			}
		}

		deq.insert(deq.end(),rest.begin(),rest.end());
		cout << "Case " << t << ": " << (deq[y-1].toString()) << endl;
	}
	
	return 0;
}