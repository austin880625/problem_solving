#include <iostream>
#include <stdio.h>
#define LL long long int
#define MAXN 10
using namespace std;

int N,M;
int Pow[11]={1,3,9,27,81,243,729,2187,6561,19683,59049};
int dp[MAXN*MAXN][Pow[MAXN]];

int getbit(int x,int k)
{
    for(int i=0;i<k;i++)
    {
        x/=3;
    }
    return x-((x/3)*3);
}
void print(int x,int nl)
{
    for(int i=0;;i<=N;i++)
    {
        printf("%d",x%3);
        x/=3;
    }
    if(nl)puts("");
}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }
        dp[0][0]=0;
        int cur=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                for(int state=0;state<Pow[M+1];state++)
                {
                    int LEFT=getbit(state,N),UP=getbit(state,N-1);
                    if(grid[i][j]==0)
                    {
                        if(LEFT||UP)continue;
                        
                    }
                }
                cur++;
            }
        }
    }
}
