#include <bits/stdc++.h>
using namespace std;

vector<int> sieve[10001];
int GCD;

int gcd(int a, int b) {
  int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

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
		long list[10001];
		int size = 0;
		memset(list,0,sizeof(list));
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
					list[n]+=1;
					size++;
					if(!size)
					{
						GCD = n;
					}
					else
					{	
						GCD = gcd(GCD,n);
					}
				}
				else if(s2=="REM")
				{
					list[n]-=1;
					size--;
					if(list[n]==0 && size>0)
					{	
						GCD = 0;
						for (int i = 0; i < 10001; ++i)
						{
							if(list[i]>0)
							{
								if(!GCD)GCD = i;
								else GCD = gcd(GCD,i);
							}
						}
					}
				}
			}
			else if(s1=="CON")
			{
				if(!size)printf("-1\n");
				else
				{
					for (int i = 0; i < sieve[GCD].size(); ++i)
					{
						if(!isPrime(sieve[GCD][i]))
						{
							if(i+1<sieve[GCD].size())printf("%d ",sieve[GCD][i]);
							else printf("%d",sieve[GCD][i]);
						}
					}
					printf("\n");
				}
			}
		}
	}
    return 0;
}
