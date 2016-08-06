#include <bits/stdc++.h>

using namespace std;

int main()
{
	int TC; cin >> TC;
	while(TC--)
	{
		long arr[6]; memset(arr,0,sizeof arr);
		for (int i = 0; i < 6; ++i)
		{
			int a;
			cin >> a;
			cout << a << (i+1!=6?" ":"");
			arr[i] = a;
		}
		cout << endl;
		bool count = (arr[0]+arr[1]+arr[2] > arr[3]+arr[4]+arr[5]);
		bool colour = arr[0] >= arr[3];
		if(colour && arr[0] == arr[3]) colour = arr[1] >= arr[4];
		if(colour && arr[0] == arr[3] && arr[1] == arr[4]) colour = arr[2] > arr[5];

		if(count && colour)
		{
			cout << "both" << endl;
		}
		else if(count)
		{
			cout << "count" << endl;
		}
		else if(colour)
		{
			cout << "color" << endl;
		}	
		else cout << "none" << endl;
	}
}