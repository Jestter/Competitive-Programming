#include <bits/stdc++.h>
using namespace std;

long long calc(vector<long long> v)
{
	long long res = 0;
	vector<long long > v2(v);
	int end = v.size();
	int jump = 1;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < end; ++j)
		{
			if(v2[j]%3==0)res++;
			if(j+jump < v.size())v2[j] += v[j+jump];
		}
		end--;
		jump++;
	}
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
				v2.push_back(in[i]-'0');
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
