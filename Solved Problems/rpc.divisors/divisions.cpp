#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
	//cout << "entro gcd para " << a << endl;
  LL tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

LL g(LL x,LL n)
{
	return (x*x+1)%n;
}

LL findFactor(LL n)
{
	if(n%2==0)return 2;
	LL x = 2,y=2,d=1;
	while(d==1)
	{
		x = g(x,n);
		y = g(g(y,n),n);
		d = gcd(abs(x-y),n);
	}
	return d;
}

LL divisors(LL n)
{
	LL res = 1;
	LL c=0;
	LL last = findFactor(n);
	n = n/last;
	c++;
	while(n>1 && last!=1)
	{
		LL aux = findFactor(n);
		n = n/aux;
		if(aux!=last)
		{
			res*= (c+1);
			c=0;
			last=aux;
		}
		c++;
	}
	res*= (c+1);
	return res;
}

int main()
{
	LL num;
	scanf("%lld",&num);
	printf("%lld\n",divisors(num));
    return 0;
}
