#include <bits/stdc++.h>

using namespace std;

int countones(unsigned long long n)
{
	int c =0;
	while(n>0)
	{
		if(n&1)c++;
		n = n>>1;
	}
	return c;
}

int main()
{
	unsigned long long num;
	while(cin >> num)
	{
		int op;
		cin >> op;
		int pos[op];
		for (int i = 0; i < op; ++i)
		{
			cin >> pos[i];
		}
		sort(pos,pos+op);
		int ones =  countones(num);
		int i = op-1;
		for (; i >= 0 && ones>0; --i)
		{
			num |= (1<<pos[i]);
			ones--;
		}
		for (; i >=0 ; ++i)
		{
			num &= ~(1<<pos[i]);
		}
		int resto = num % 7;
		if(resto!=0)
		{
			num |= (1<<(resto));
			num &= ~(1<<(resto+1));
		}
		cout << num << endl;
	}
}