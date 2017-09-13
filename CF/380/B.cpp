#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 1005
using namespace std;
int N,M;
int A[MAXN][MAXN];
int S[MAXN][MAXN];
int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        S[0][0]=S[0][1]=S[1][0];
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf("%d",&A[i][j]);
                S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+A[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(A[i][j])continue;
                if(S[N][j]-S[N][j-1]-S[i][j]+S[i][j-1])ans++;
                if(S[i][M]-S[i-1][M]-S[i][j]+S[i-1][j])ans++;
                if(S[i][j-1]-S[i-1][j-1])ans++;
                if(S[i-1][j]-S[i-1][j-1])ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
