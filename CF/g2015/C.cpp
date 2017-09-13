#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 505
using namespace std;

int H,W;
char grid[MAXN][MAXN];
int G[2][MAXN][MAXN];

int main()
{
    while(scanf("%d%d",&H,&W)==2)
    {
        for(int j=0;j<=W;j++)
        {
            G[0][0][j]=G[1][0][j]=0;
        }
        for(int i=1;i<=H;i++)
        {
            scanf("%s",grid[i]+1);
            for(int j=0;j<=W;j++)
            {
                G[0][i][j]=G[1][i][j]=0;
            }
        }
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(i>1)
                {
                    if(grid[i][j]!='#'&&grid[i-1][j]!='#')G[0][i][j]=G[0][i-1][j]+1;
                    else G[0][i][j]=G[0][i-1][j];
                }
                if(j>1)
                {
                    if(grid[i][j]!='#'&&grid[i][j-1]!='#')G[1][i][j]=G[1][i][j-1]+1;
                    else G[1][i][j]=G[1][i][j-1];
                }
            }
        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int r1,c1,r2,c2;
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            //r1--,r2--,c1--,c2--;
            int ans=0;
            for(int i=r1;i<=r2;i++)
            {
                ans+=G[1][i][c2]-G[1][i][c1];
            }
            for(int i=c1;i<=c2;i++)
            {
                ans+=G[0][r2][i]-G[0][r1][i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
