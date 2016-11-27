#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t1[3];int t2[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> t1[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		cin >> t2[i];
	}

	sort(t1,t1+3);
	sort(t2,t2+3);

	if(t1[0]*t1[0]+t1[1]*t1[1]!=t1[2]*t1[2])
	{	
		cout << "NO" << endl;
		return 0;
	}

	if(t2[0]*t2[0]+t2[1]*t2[1]!=t2[2]*t2[2])
	{	
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		if(t1[i]!=t2[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}