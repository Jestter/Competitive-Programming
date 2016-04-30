#include <bits/stdc++.h>

using namespace std;

int mv[4]={-1,0,1,0};
int mh[4]={0,1,0,-1};
int rotatepe[3]={1,-1,0};
int N,M,S;
char arena[100][100];

bool isValid(int x,int y)
{
    if(x>=M||x<0)return false;
    if(y>=N||y<0)return false;
    if(arena[x][y]=='#')return false;
    return true;
}

int main()
{
    while(scanf("%d %d %d",&N,&M,&S)&&(N||M||S))
    {
        scanf("\n");
        pair<int,int> pos;
        int dir = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%c",&arena[j][i]);
                if(arena[j][i]=='N'||arena[j][i]=='S'||arena[j][i]=='O'||arena[j][i]=='L')
                {
                    pos.first = j;
                    pos.second = i;
                    dir = arena[j][i]=='N'?0:arena[j][i]=='S'?2:arena[j][i]=='O'?3:arena[j][i]=='L'?1:-1;
                }
            }

            scanf("\n");
        }

        int count= 0;
        for (int i = 0; i < S; ++i)
        {
            char inst;
            scanf("%c",&inst);

            dir = (dir+4+rotatepe[inst-'D'])%4;
            if(inst=='F' && isValid(pos.first+mh[dir],pos.second+mv[dir]))
            {
                pos.first = pos.first+mh[dir];
                pos.second = pos.second+mv[dir];
                if(arena[pos.first][pos.second]=='*')
                {
                    count++;
                    arena[pos.first][pos.second]='.';
                }
            }


        }
        scanf("\n");

        printf("%d\n", count);

    }

    return 0;
}