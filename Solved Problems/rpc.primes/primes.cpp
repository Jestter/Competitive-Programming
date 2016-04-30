#include <bits/stdc++.h>

#define EPS 1e-7

using namespace std;

typedef long long LL;

int conv[10]= {0, 1, 2, -1, -1,5,9,-1,8,6};

bool IsPrimeSlow(LL x)
{
	if(x<=1)return false;
	if(x<=3)return true;
	if(!(x%2)||!(x%3))return false;
	LL s=(LL)(sqrt((double)(x))+EPS);
	for(LL i=5;i<=s;i+=6)
	{
		if(!(x%i)||!(x%(i+2)))return false;
	}
	return true;
}

LL func(LL num)
{
	LL aux = 0;
	int exp=1;
	bool start1 = false;
	int n = 0;
	while(num>0)
	{
		n = num%10;
		if((n==1||n==9)&&exp==1)start1=true;
		if(n==3||n==4||n==7)return -1;
		aux+=conv[n];
		aux*=10;
		num/=10;
		exp++;
	}	
	if(start1 && (n==1||n==6))return aux/10;
	else return -1;

}

int main()
{
	LL num;
	scanf("%lld",&num);
	LL inv = func(num);
	if(num == 2||num==5) printf("yes");
	else if(inv!=-1)
	{
		if(IsPrimeSlow(num)&&IsPrimeSlow(inv))printf("yes");
		else printf("no");
	}
	else printf("no");
	return 0;
}
