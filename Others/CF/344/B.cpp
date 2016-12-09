#include <stdio.h>
#include <iostream>
#define MAXN 5005

using namespace std;

int grid[MAXN][MAXN];
int N,M,K;
int opROW[MAXN][2];
int opCOL[MAXN][2];

int main()
{
    while(scanf("%d%d%d",&N,&M,&K)==3)
    {
        for(int i=0;i<=N;i++)opROW[i][0]=opROW[i][1]=0;
        for(int i=0;i<=M;i++)opCOL[i][0]=opCOL[i][1]=0;

        for(int i=1;i<=K;i++)
        {
            int op,t,a;
            scanf("%d%d%d",&op,&t,&a);
            if(op==1) opROW[t][0]=a,opROW[t][1]=i;
            else opCOL[t][0]=a,opCOL[t][1]=i;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(j>1)printf(" ");
                printf("%d",opROW[i][1] > opCOL[j][1] ? opROW[i][0] : opCOL[j][0]);
            }
            puts("");
        }
    }
    return 0;
}
