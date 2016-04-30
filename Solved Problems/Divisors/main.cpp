#include <bits/stdc++.h>
using namespace std;

vector<int> sieve[10001];

void iniSieve()
{
	sieve[0].push_back(0);
	for (int i = 1; i < 10001; ++i)
	{
		sieve[i].push_back(i);
		for (int j = 2; j*i < 10001; ++j)
		{
			sieve[i*j].push_back(i);
		}
	}

	/*for (int i = 0; i < 10001; ++i)
	{
		cout << i << " : " ;
		for (int j = 0; j < sieve[i].size(); ++j)
		{
			cout << sieve[i][j] << " ";
		}
		cout << endl;
	}*/
}

bool isPrime(int a)
{
	if(a == 1)return false;
	return sieve[a].size()<3;
}

int main()
{	
	iniSieve();
	int cases;
	scanf("%d",&cases);
	for (int c = 0; c < cases; ++c)
	{
		map<int,int> list;
		bool mod = false;
		int maxDiv = 0;
		long divisors[10001];
		int op;
		scanf("%d",&op);
		for (int o = 0; o < op; ++o)
		{
			string s1,s2;
			int n;
			cin >> s1;
			if(s1=="UPD")
			{
				cin >> s2 >> n;
				//cout << s1 << " " << s2 << " " << n << endl;
				if(s2=="ADD")
				{
					if(list.count(n))list[n]+=1;
					else list[n]=1;
					mod = true;
					/*for (int i = 0; i < sieve[n].size(); ++i)
					{
						divisors[sieve[n][i]]+=1;
					}*/
				}
				else if(s2=="REM")
				{
					if(list[n]==1)
					{
						list.erase(n);
						mod = true;
					}
					else list[n]-=1;
					/*for (int i = 0; i < sieve[n].size(); ++i)
					{
						divisors[sieve[n][i]]-=1;
					}*/
				}
			}
			else if(s1=="CON")
			{
				if(list.empty())printf("-1\n");
				else
				{
					if(mod)
					{
						memset(divisors,0,sizeof(divisors));
						maxDiv = 0;
						for ( pair<const int,int> x: list )
						{
							for (int i = 0; i < sieve[x.first].size(); ++i)
							{
								divisors[sieve[x.first][i]]+=1;
								maxDiv = sieve[x.first][i] > maxDiv ? sieve[x.first][i] : maxDiv;
							}
						}
						mod = false;
					}

					bool fst = false;
					for (int i = 1; i <= maxDiv; ++i)
					{
						if(divisors[i]==divisors[1] && !isPrime(i))
						{
							if(!fst)
							{
								printf("%d",i);
								fst = true;
							}
							else printf(" %d",i );
						}
					}
					printf("\n");
				}
			}
		}
	}
    return 0;
}
