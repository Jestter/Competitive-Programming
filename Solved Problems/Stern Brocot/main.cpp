//Uva 11350
#include <bits/stdc++.h>

using namespace std;

struct fraction
{
	long nume;
	long deno;

	fraction(long n,long d):nume(n),deno(d){}

	fraction& operator+=(const fraction& other)
    {
        deno += other.deno;
        nume += other.nume;
        return *this;
    }
};

int main()
{
	int tc;
	scanf("%d\n",&tc);
	while(tc--)
	{
		string s;
		getline(cin,s);
		fraction upper(1,0),lower(0,1),curr(1,1);
		for (char c: s)
		{
			if(c == 'R')
			{
				lower = curr;
				curr += upper;
			}
			else
			{
				upper = curr;
				curr += lower;
			}
		}

		printf("%ld/%ld\n",curr.nume,curr.deno);
	}
	return 0;
}