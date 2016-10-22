#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int N;
        scanf("%d",&N);
        int N2 = 2*N;
        int arr[N2][N2];
        memset(arr,0,sizeof arr);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                scanf("%d",&arr[i][j]);
                arr[i+N][j] = arr[i][j];
                arr[i][j+N] = arr[i][j];
                arr[i+N][j+N] = arr[i][j];
            }

        long long GMAX = INT_MIN;
        int temp[N2];
        
        for (int i = 0; i < N2; ++i)
        {
            memset(temp,0,sizeof(temp));
            for (int j = i; j < N+i && j < N2; ++j)
            {
                for (int k = 0; k < N2; ++k)
                    temp[k] += arr[k][j];
                int meh = temp[0];
                int msf = temp[0];
                int counter = 1;
                vector<int> v,tempv;
                for (int l = 1; l < N2; ++l)
                {   
                    if(temp[l]>(meh+temp[l]) || counter >= N) 
                    {
                        tempv.clear();
                        tempv.push_back(arr[l][j]);
                        meh = temp[l];
                        counter = 1;
                    }
                    else
                    {
                        meh = (meh+temp[l]); 
                        tempv.push_back(arr[l][j]);
                        counter++;
                    }
                    if(meh > msf) {v.clear();v.insert(v.begin(),tempv.begin(),tempv.end());}
                    msf = msf>meh?msf:meh;
                    
                    
                }
                /*if(GMAX < msf)
                {
                    cout << "list: ";
                    for(int lp:v)cout << lp << " ";
                    cout << endl;
                }*/
                if(GMAX < msf) GMAX = msf;
            }

        }
        printf("%lld\n",GMAX);
    }
    
    return 0;
}
