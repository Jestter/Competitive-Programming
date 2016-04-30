#include <bits/stdc++.h>

using namespace std;

int main()
{

	string ss[100]={
		"aa",
		"ab",
		"ac",
		"ad",
		"ae",
		"af",
		"ag",
		"ah",
		"ai",
		"aj",
		"ak",
		"al",
		"am",
		"an",
		"ao",
		"ap",
		"aq",
		"ar",
		"as",
		"at",
		"au",
		"av",
		"aw",
		"ax",
		"ay",
		"az",
		"ba",
		"bb",
		"bc",
		"bd",
		"be",
		"bf",
		"bg",
		"bh",
		"bi",
		"bj",
		"bk",
		"bl",
		"bm",
		"bn",
		"bo",
		"bp",
		"bq",
		"br",
		"bs",
		"bt",
		"bu",
		"bv",
		"bw",
		"bx",
		"by",
		"bz",
		"ca",
		"cb",
		"cc",
		"cd",
		"ce",
		"cf",
		"cg",
		"ch",
		"ci",
		"cj",
		"ck",
		"cl",
		"cm",
		"cn",
		"co",
		"cp",
		"cq",
		"cr",
		"cs",
		"ct",
		"cu",
		"cv",
		"cw",
		"cx",
		"cy",
		"cz",
		"da",
		"db",
		"dc",
		"dd",
		"de",
		"df",
		"dg",
		"dh",
		"di",
		"dj",
		"dk",
		"dl",
		"dm",
		"dn",
		"do",
		"dp",
		"dq",
		"dr",
		"ds",
		"dt",
		"du",
		"dv",
	};
	cout << 100 <<"  "<< 100 << endl;

	long long sumver[100];
	memset(sumver,0,sizeof(sumver));
	for (int i = 1; i <= 100; ++i)
	{
		long long sum = 0;
		for (int j = 0; j < 100; ++j)
		{
			cout << ss[j%i] << "  ";
			sum += (j%i);
			sumver[j] += (j%i);
			if(j+1==100)cout << sum;
		}
		cout << endl;
	}

	for (int i = 0; i < 100; ++i)
	{
		cout << sumver[i] << (i+1!=100?"  ":"");
	}

	return 0;
}