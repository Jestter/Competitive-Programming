#include <bits/stdc++.h>
using namespace std;


int main()
{	
	string in;
	while(getline(cin,in))
	{
		long long a,b;
		sscanf(in.c_str(),"%lld  %lld",&a,&b);
		getline(cin,in);
		long long c = a-b;

		deque<int> ws;
		deque<int> bs;
		for (int i = 0; i < in.length(); ++i)
		{
			if(in[i]=='W')
			{
				ws.push_back(i);
			}
			else
			{
				bs.push_back(i);	
			} 
		}

		int cut = bs.size();
		long long total = 0;
		
		while(ws.size()&&bs.size())
		{
			int bx = bs.back();bs.pop_back();
			int wx = ws.front();ws.pop_front();
			if(bx<cut)break;
			if(abs(bx-wx)*c>=a)
			{
				total += a;
			}
			else
			{
				total += c*abs(bx-wx);
			}
		}
		cout << total << endl;
	}
    return 0;
}
