#include <iostream>
#include <stdio.h>
#define MAXN 500005
using namespace std;

int F[MAXN][3];
int T,N,K;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);
        F[3][2]=(K-1)%3;F[3][1]=((F[3][2]+1)%3+(K-1)%2)%3;F[3][0]=0;
        while(F[3][0]==F[3][2]||F[3][0]==F[3][1])F[3][0]=(F[3][0]+1)%3;
        //cout<<F[3][2]<<F[3][1]<<F[3][0];
        for(int i=3;i<N;i++)for(int j=0;j<3;j++)F[i+1][j]=(K+F[i][j])%(i+1);
        printf("%d %d %d\n",F[N][2]+1,F[N][1]+1,F[N][0]+1);
    }
    return 0;
}
