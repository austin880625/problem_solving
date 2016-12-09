#include <stdio.h>
#include <iostream>

#define MAXN 225

using namespace std;

int C[MAXN];
int dp[MAXN][MAXN][MAXN];
int T;
int N;

int DP(int l,int r,int k)
{
    //cout<<l<<" "<<r<<" "<<k<<endl;
    if(dp[l][r][k]!=0)return dp[l][r][k];
    int res=0;
    int c=C[r],pos1=r,pos2;
    for(;C[pos1]==c&&pos1>=l;pos1--);
    if(pos1==l-1)return dp[l][r][k]=(k+r-l+1)*(k+r-l+1);
    res=max(res,DP(l,pos1,0)+(k+r-pos1)*(k+r-pos1));

    pos2=pos1;
    while(1)
    {
        for(;C[pos2]!=c&&pos2>=l;pos2--);
        if(pos2>=l)res=max(res,DP(l,pos2,k+r-pos1)+DP(pos2+1,pos1,0));
        else break;
        for(;C[pos2]==c;pos2--);
    }
    //cout<<l<<" "<<r<<" "<<k<<" "<<res<<endl;

    return dp[l][r][k]=res;
}

int main()
{
    int kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)for(int k=0;k<N;k++)dp[i][j][k]=0;
        }
        for(int i=0;i<N;i++)
        {
            scanf("%d",C+i);
            dp[i][i][0]=1;
        }
        int ans=DP(0,N-1,0);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
