#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int A,B;
int dp[5005][5005];

int f(int a,int b)
{
    if(a<b)swap(a,b);
    if(!(a&&b))return dp[a][b]=dp[b][a]=(a%2==1 ? 1 : 0);
    if(dp[a][b]!=-1)return dp[a][b];
    int res=1;
    if(a)res&=f(a-1,b);
    if(b)res&=f(a,b-1);
    if(a&&b)res&=f(a-b,b);
    return dp[a][b]=dp[b][a]=1-res;
}

int main()
{
    for(int i=0;i<5005;i++)for(int j=0;j<5005;j++)dp[i][j]=-1;
    dp[0][1]=dp[1][0]=1;int T;
    scanf("%d",&T);
while(T--){
    scanf("%d%d",&A,&B);

        printf((f(A,B) ? ">//<" : ">\\\\<"));
        puts("");
    }
    return 0;
}
