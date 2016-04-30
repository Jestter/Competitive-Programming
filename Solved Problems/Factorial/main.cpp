#include <bits/stdc++.h>

using namespace std;

long fact[9] = {1,1,2,6,24,120,720,5040,40320};

int main()
{
    int n;
    while(scanf("%d\n",&n)!=EOF)
    {
        int f = 8;
        int count = 0;
        while(n>0)
        {
            if(fact[f]<=n){n-=fact[f];count++;}
            else f--;
        }
        cout << count << endl;
    }
}