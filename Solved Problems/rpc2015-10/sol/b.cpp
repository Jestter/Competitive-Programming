#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long total,parts;
	scanf("%lld %lld",&total,&parts);
	double avg = total*total/(double)parts;
	//cout << avg << endl;
	long long lvl = 0;
	vector<long long> nums;
	long long i=0;
	while(parts>0)
	{
		//cout << "part " << i+1 << endl;
		long long max_lvls = 1 + total - parts;
		//cout << "max lvls "<< max_lvls << endl;
		long long last = 0;
		for (long long j = 1; j <= max_lvls; ++j)
		{
			long long triangles = (lvl+j)*(lvl+j)-lvl*lvl;
			if(triangles>=avg || j==max_lvls)
			{
				nums.push_back(abs(triangles-avg)<abs(last-avg)?triangles:last);
				if((triangles-avg)<abs(last-avg)){lvl=lvl+j;total-=j;}
				else{lvl = lvl+j-1;total-=j-1;}
				//cout << "final lvl " << lvl << endl;
				parts-=1;
				break;
			}
			else
			{
				//cout << "lvl " << lvl+j << endl;
				last = triangles;
			}
		}
		i++;
	}
	//cout << "------" << endl;
	long long min = LLONG_MAX;
	for(long n:nums)
	{
		if(n<min)min=n;
		//cout << n << endl;
	}
	printf("%lld",min);
}