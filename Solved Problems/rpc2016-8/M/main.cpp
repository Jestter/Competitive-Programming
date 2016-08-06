#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC; cin >> TC;
	while(TC--)
	{
		bool arr[200]; memset(arr,0,sizeof arr);
		for (int i = 0; i < 10; ++i)
		{
			int a;
			cin >> a;
			cout << a << (i+1!=10?" ":"");
			arr[a] = true;
		}
		cout << endl;
		if(arr[17] && arr[18])
		{
			cout << "both" << endl;
		}
		else if(arr[17])
		{
			cout << "zack" << endl;
		}
		else if(arr[18])
		{
			cout << "mack" << endl;
		}	
		else cout << "none" << endl;
	}
}