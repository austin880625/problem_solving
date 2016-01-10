#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;
int U[MAXN];
double P[MAXN],S[MAXN];
double dp[MAXN][MAXN];
int sum;
int N,W;
int T;
bool cmp(int a,int b){return a>b;}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&W);
        sum=0;
        for(int i=1;i<=N;i++)scanf("%d",&U[i]),sum+=U[i];
        sort(U+1,U+N+1,cmp);
        S[0]=0,P[0]=0;
        for(int i=1;i<=N;i++)P[i]=(double)U[i]/(double)sum,S[i]=S[i-1]+P[i];
        for(int i=0;i<=W;i++)dp[0][i]=0;
        for(int i=1;i<=N;i++)
        {
            dp[i][0]=INF;
            for(int j=1;j<=W;j++)
            {
                dp[i][j]=INF;
                for(int k=1;k<=i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k-1][j-1]+i*(S[i]-S[k-1]));
                }
            }
        }
        printf("%.4lf\n",dp[N][W]);
    }
}
