#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	unordered_set<string> u_set;
	while(n--)
	{
		int tree=0;
		map<long long,long long> arr;
		//cout << "--new tree--"<<endl;
		for (int i = 0; i < k; ++i)
		{
			int val;cin>>val;
			//cout << "val: "<<val<<endl;
			long long idx =1;
			while(arr[idx]!=0)
			{
				//cout << "starts at "<< idx<<" - ";
				if(arr[idx] > val)idx = (idx << 1);
				else idx = (idx << 1) +1;
				//cout << "goes to " << idx<<endl;
			}
			//cout << "inserted at "<<idx<<endl;
			arr[idx]=val;
		}
		string s="";
		for(auto it=arr.begin();it!=arr.end();++it)s+=to_string(it->first)+",";
		//cout << s << endl<<endl;
		u_set.insert(s);
	}
	cout << u_set.size();
    return 0;
}