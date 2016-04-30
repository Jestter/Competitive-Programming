#include <bits/stdc++.h>
using namespace std;

long long calc(vector<long long> v)
{
	long long res = 0;
	long long  sum = 0;
	bool b = false;
	long long count = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
		sum+= v[i];
		if(v[i]==0)
		{
			b = true;
			count++;
		}
		else if(b)
		{
			b = false;
			res += count*(count+1)/2;
			count = 0;
		}
	}
	cout << endl;
	res += count*(count+1)/2 + sum/2;
	return res;
}

int main()
{	
	string in;
	while(getline(cin,in))
	{
		vector< vector<long long> > v;
		vector<long long> v2;
		bool b=false;
		for (int i = 0; i < in.length(); ++i)
		{
			if('0'<= in[i] && in[i] <='9')
			{
				v2.push_back((in[i]-'0')%3);
				b = true;
				if(i+1==in.length())
				{
					v.push_back(v2);
					v2.clear();
					b = false;
				}
			}
			else if(b)
			{
				v.push_back(v2);
				v2.clear();
				b = false;
			}
		}
		
		long long res = 0;
		for(int i=0;i<v.size();i++)
		{
			res +=  calc(v[i]);
		}
		cout << res << endl;
	}
    return 0;
}
