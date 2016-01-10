#include <iostream>
#include <stdio.h>
#define MAXN 105
#define INF 2147483646
using namespace std;
int N;
int A[MAXN];
int dp[MAXN][MAXN];
int S[MAXN];

int DP(int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    if(dp[i][j]!=-INF)return dp[i][j];
    int res=0;
    for(int k=i;k<j;k++)res=min(DP(i,k),res);
    for(int k=j;k>i;k--)res=min(DP(k,j),res);
    return dp[i][j]=S[j]-S[i-1]-res;
}
int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        S[0]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)dp[i][j]=-INF;
            scanf("%d",&A[i]);
            dp[i][i]=A[i];
            S[i]=S[i-1]+A[i];
        }
        int ans=DP(1,N);
        printf("%d\n",ans-(S[N]-S[0]-ans));
    }
    return 0;
}
