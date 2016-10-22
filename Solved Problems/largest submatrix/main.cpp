#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d\n",&tc);
    while(tc--)
    {
        vector<string> lines;
        string line = "";
        while(getline(cin,line) && !line.empty())
        {
            lines.push_back(line);
        }

        int M = lines.size(),N = lines[0].length();
        int arr[M][N];
        
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                arr[i][j] = (lines[i][j] == '1'? 1: -200000);
            }
        }

        int GMAX = INT_MIN;
        int temp[M];

        for (int i = 0; i < N; ++i)
        {
            memset(temp,0,sizeof(temp));
            for (int j = i; j < N; ++j)
            {
                for (int k = 0; k < M; ++k)
                    temp[k] += arr[k][j];
                int meh = temp[0];
                int msf = temp[0];
                for (int l = 1; l < M; ++l)
                {
                    meh = temp[l]>(meh+temp[l])?temp[l]:(meh+temp[l]);
                    msf = msf>meh?msf:meh;
                }
                if(GMAX < msf) GMAX = msf;
            }
        }
        if(GMAX == -200000) GMAX = 0;
        printf("%d\n",GMAX);
        if(tc != 0) printf("\n");
    }
    
    return 0;
}
