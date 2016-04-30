#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

//map<pair<ll,ll>, ll > Mgcd;

ll gcd(ll a,ll b)
{
    //pll p(min(a,b),max(a,b));
    //ll mgcd = Mgcd[p];
    //if(mgcd != 0)return mgcd;
    ll tmp;
    while(b){a%=b; tmp=a; a=b; b=tmp;}
    return a;//Mgcd[p] = a;
}

int main()
{
    int TC;
    scanf("%d",&TC);
    while(TC--)
    {
        //cout << "----------------" << endl;
        long n;
        scanf("%ld",&n);
        ll meh,msf;
        scanf("%lld",&meh);
        msf = meh;
        long count = 1;
        for (long i = 1; i < n; ++i)
        {
            ll num; scanf("%lld",&num);
            ll g = gcd(num,meh);
            //cout << "gcd: " << num << " " << meh << " = " << g << endl;
            if(g >= num)
            {
                //cout << meh << " >= " << num << endl;
                meh = g;
                count++;
            }
            else
            {
                //cout << (g*(count+1)) << " < " << num << endl;
                meh = num;
                count = 1;
            }

            //cout << "msf: " << (meh*count) << " vs " << msf << " = " ;
            msf = max(meh*count,msf);
            //cout << msf << endl;

        }
        printf("%lld\n", msf);
    }
    return 0;
}