#include <bits/stdc++.h>

using namespace std;

// return a % b (positive value)
long long mod(long long a, long long b) {
  return ((a%b)+b)%b;
}

// computes gcd(a,b)
long long gcd(long long a, long long b) {
  long long tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

long long extended_euclid(long long a, long long b, long long &x, long long &y) {  
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a/b;
    long long t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

long long mod_inverse(long long a, long long n) {
  long long x, y;
  long long d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x,n);
}

void linear_diophantine(long long a, long long b, long long c, long long &x, long long &y) {
  long long d = gcd(a,b);
  if (c%d) {
    x = y = -1;
  } else {
    x = c/d * mod_inverse(a/d, b/d);
    y = (c-a*x)/b;
  }
}

int main()
{
	int TC; scanf("%d",&TC);
	while(TC--)
	{
		long long r,s,q;
		scanf("%lld %lld %lld",&r,&s,&q);
		long long x,y;
		linear_diophantine(r,s,q,x,y);
		printf("%lld %lld\n",x,y);
	}
}