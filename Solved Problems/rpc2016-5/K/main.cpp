#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC,sudo;
	cin >> TC;
	while(TC--)
	{
		cin >> sudo;
		int ggrid[sudo][sudo];
		for (int i = 0; i < sudo; ++i)
		{
			for (int j = 0; j < sudo; ++j)
			{
				cin >> ggrid[i][j];
			}
		}

		int sq = (int)sqrt(sudo);
		string res = "yes";


		for (int k = 0; k < sq; ++k)
		{
			for (int l = 0; l < sq; ++l)
			{
				unordered_set<int> set_;
				int mx = k*sq;
				int my = l*sq;
				for (int i = 0; i < sq; ++i)
				{
					for (int j = 0; j < sq; ++j)
					{
						if(set_.count(ggrid[mx+i][my+j]))res = "no";
						else set_.insert(ggrid[mx+i][my+j]);
					}
				}
			}
		}

		for (int i = 0; i < sudo; ++i)
		{
			unordered_set<int> set_;
			for (int j = 0; j < sudo; ++j)
			{
				if(set_.count(ggrid[i][j]) || ggrid[i][j]<1||ggrid[i][j]>sudo) res = "no";
				else set_.insert(ggrid[i][j]);
			}
		}

		for (int j = 0; j < sudo; ++j)
		{
			unordered_set<int> set_;
			for (int i = 0; i < sudo; ++i)
			{
				if(set_.count(ggrid[i][j]) || ggrid[i][j]<1||ggrid[i][j]>sudo) res = "no";
				else set_.insert(ggrid[i][j]);
			}
		}

		cout << res <<endl;
	}
}