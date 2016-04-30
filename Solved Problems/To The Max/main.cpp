#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            scanf("%d",&arr[i][j]);
        }

    int GMAX = INT_MIN;
    int temp[N];

    for (int i = 0; i < N; ++i)
    {
    	memset(temp,0,sizeof(temp));
    	for (int j = i; j < N; ++j)
    	{
    		for (int k = 0; k < N; ++k)
				temp[k] += arr[k][j];
    		int meh = temp[0];
    		int msf = temp[0];
    		for (int l = 1; l < N; ++l)
    		{
    			meh = temp[l]>(meh+temp[l])?temp[l]:(meh+temp[l]);
    			msf = msf>meh?msf:meh;
    		}
    		if(GMAX < msf) GMAX = msf;
    	}
    }
    printf("%d",GMAX);
    return 0;
}
