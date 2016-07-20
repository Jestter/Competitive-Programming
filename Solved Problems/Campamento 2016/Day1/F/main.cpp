#include <bits/stdc++.h>

using namespace std;

vector<int> memo(30001,-1);

bool checkFree(int time, int nb)
{
	if(memo[nb] == -1)return true;
	if(time - memo[nb] >= 600) return true;
	return false;
}

int main()
{
	string in;

	while(getline(cin,in))
	{
		int time,block;
		char cha;
		stringstream ss;
		ss << in;
		
		ss >> time >> cha;
		if(cha == '.')
		{
			ss >> block;
			if(checkFree(time,block))
			{
				cout << "-" << endl;
			}
			else
			{
				cout << "+" << endl;
				memo[block] = time;
			}
		}
		else
		{
			for (int i = 1; i < 30001; ++i)
			{
				if(checkFree(time,i)){cout << i << endl;memo[i]=time;break;}
			}
		}
	}
	return 0;
}