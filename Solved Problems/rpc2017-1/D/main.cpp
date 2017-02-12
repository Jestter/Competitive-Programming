#include <bits/stdc++.h>

using namespace std;

#define asize 'z'-'a'+1

int main()
{
	int map[asize];
	memset(map,0,sizeof map);
	char c;
	while(cin >> c){
		map[c-'a']++;
	}
	sort(map,map+asize);
	int sum = 0;
	for (int i = 0; i < asize-2; ++i)
	{
		sum += map[i];
	}
	cout << sum << endl;
}