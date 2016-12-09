#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 105
#define INF 0x3f3f3f3f

using namespace std;

char S[MAXN];
char T[MAXN];
int N;
int dp[MAXN][MAXN];
int F[MAXN];

int main()
{
    while(scanf("%s%s",S,T)==2)
    {
        N=strlen(S);
        for(int i=0;i<N;i++)
        {
            dp[i][i]=1;
            if(i+1<N)dp[i][i+1]=(T[i]==T[i+1] ? 1 : 2);
        }
        for(int gap=2;gap<N;gap++)
        {
            //deal with interval [i,i+gap]
            for(int i=0;i+gap<N;i++)
            {
                int j=i+gap;
                dp[i][j]=INF;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if(T[i]==T[j])dp[i][j]=min(dp[i][j], min(dp[i+1][j],dp[i][j-1]) );
            }
        }
        F[0]=0;
        for(int i=1;i<=N;i++)
        {
            F[i]=INF;
            if(S[i-1]==T[i-1])F[i]=F[i-1];
            for(int j=0;j<i;j++)
            {
                F[i]=min(F[i],F[j]+dp[j][i-1]);
            }
        }
        printf("%d\n",F[N]);
    }
    return 0;
}
