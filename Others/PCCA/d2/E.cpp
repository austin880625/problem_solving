#include <stdio.h>
#include <iostream>
#define MAXN 505


using namespace std;

int A[MAXN];
int dp[MAXN][MAXN];
int N;

int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)scanf("%d",A+i);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++){
                if(i<j)dp[i][j]=MAXN+100;
                if(i==j)dp[i][j]=dp[i+1][j]=1;
            }
        }
        for(int gap=1;gap<N;gap++)
        {
            for(int i=0;i<N;i++)
            {
                int j=i+gap;
                if(j>=N)break;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if(A[i]==A[j])dp[i][j]=min(dp[i][j],dp[i+1][j-1]);//cout<<i<<" "<<j<<" "<<dp[i+1][j-1]<<endl;
            }
        }
        //cout<<dp[1][2]<<endl;
        printf("%d\n",dp[0][N-1]);
    }
    return 0;
}
