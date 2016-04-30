#include <bits/stdc++.h>

using namespace std;

vector<long> v;

int main()
{
    int TC;
    cin >> TC;
    while(TC--)
    {
    	long l,h;
    	cin >> l;
    	cin >> h;
    	v.clear();
    	for (int i = 0; i < h; ++i)
    	{
    		int pos;
    		cin >> pos;
    		v.push_back(pos);
    	}

    	sort(v.begin(),v.end());

    	vector<long>::iterator it;
    	it = lower_bound(v.begin(),v.end(),l/2);

    	long r1;
    	if(it-v.begin()>0)
    		r1 = abs(l/2-v[it-v.begin()]) < abs(l/2-v[it-v.begin()-1]) ? v[it-v.begin()]: v[it-v.begin()-1];
    	else r1 = v[it-v.begin()];

    	cout << ((r1<l-r1)?r1:l-r1) << " " << ((l-v[0]>v[h-1])?l-v[0]:v[h-1]) << endl;
    }
    return 0;
}