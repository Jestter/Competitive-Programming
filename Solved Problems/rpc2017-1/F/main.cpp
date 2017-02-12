#include <bits/stdc++.h>

using namespace std;

int main()
{
	int reg,fs;
	cin >> reg >> fs;
	int maxS = 1,minB = fs;
	for (int i = 0; i < reg; ++i)
	{
		int f;string st;
		cin >> f >> st;
		if(st[0] == 'B' && f < minB) minB = f;
		if(st[0] == 'S' && f > maxS) maxS = f;
	}
	if(minB-maxS == 1){
		cout << minB << " " << maxS << endl;
	}
	else{
		cout << (maxS+1) << " " << (minB-1) << endl;
	}
}