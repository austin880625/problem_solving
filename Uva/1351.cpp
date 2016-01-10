#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 205
#define INF 2147483647
using namespace std;

char S[MAXN];
int dp[MAXN][MAXN];
int T,N;
int dignum(int x)
{
    int res=0;
    while(x>0){res++,x/=10;}
    return res;
}
bool check(int l,int r,int k)
{
    int len=r-l+1,blocks=len/k;
    if(len%k)return false;
    for(int i=1;i<blocks;i++)
    {
        for(int j=l;j<l+k;j++)
        {
            if(S[j]!=S[j+k*i])return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",S);
        N=strlen(S);
        for(int i=0;i<N;i++)dp[i][i]=1;

        for(int gap=1;gap<N;gap++)
        {
            for(int i=0;i+gap<N;i++)
            {
                int j=i+gap;
                dp[i][j]=INF;
                for(int k=i;k<=j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                int len=j-i+1;
                for(int k=1;k<=len;k++)
                {
                    if(check(i,j,k))dp[i][j]=min(dp[i][j],2+dignum(len/k)+dp[i][i+k-1]);
                }
            }
        }
        printf("%d\n",dp[0][N-1]);
    }
    return 0;
}
