#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXN 1010
#define INF 0x3f3f3f3f
using namespace std;
int N,V,X;
struct poi
{
    int P,C,D;
    bool operator <(const poi &rhs)const
    {
        return P<rhs.P;
    }
}SEC[MAXN];
double dp[2][MAXN][MAXN];
int unfixed[MAXN];
int ans;

double cost(int L,int R,int pos,int dir)
{
    int rate=(unfixed[N+1]-unfixed[R])+(unfixed[L-1]-unfixed[0]);
    double t=0;
    if(pos)
    {
        if(dir)t=(double)(SEC[R+1].P-SEC[R].P)/(double)V;
        else t=(double)(SEC[R].P-SEC[L-1].P)/(double)V;
    }
    else
    {
        if(dir)t=(double)(SEC[R+1].P-SEC[L].P)/(double)V;
        else t=(double)(SEC[L].P-SEC[L-1].P)/(double)V;
    }
    return rate*t;
}
int main()
{
    while(scanf("%d%d%d",&N,&V,&X)==3&&(N||X||V))
    {
        ans=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%d",&SEC[i].P,&SEC[i].C,&SEC[i].D);
            ans+=SEC[i].C;
        }
        SEC[N+1].P=X;SEC[N+1].C=0;SEC[N+1].D=0;
        sort(SEC+1,SEC+N+2);
        unfixed[0]=0;
        for(int i=0;i<=N+1;i++)
        {
            for(int k=0;k<2;k++)for(int j=0;j<=N+1;j++)dp[k][i][j]=INF;
            if(i)unfixed[i]=unfixed[i-1]+SEC[i].D;
            //cout<<unfixed[i]<<endl;
        }
        int sp=0;
        for(int i=1;i<=N+1;i++)if(SEC[i].P==X){sp=i;break;}
        dp[0][sp][sp]=dp[1][sp][sp]=0;
        //cout<<sp<<endl;
        for(int L=sp;L>=1;L--)
        {
            for(int R=sp;R<=N+1;R++)
            {
                if(L==R)continue;
                double LS,RS;
                LS=RS=INF;
                if(L!=sp)
                {
                    if(dp[0][L+1][R]!=INF)LS=dp[0][L+1][R]+cost(L+1,R,0,0);
                    if(dp[1][L+1][R]!=INF)RS=dp[1][L+1][R]+cost(L+1,R,1,0);    //走到左邊，所以前一個狀態是L+1,R
                    dp[0][L][R]=min(LS,RS);
                }
                LS=RS=INF;
                if(R!=sp)
                {
                    if(dp[0][L][R-1]!=INF)LS=dp[0][L][R-1]+cost(L,R-1,0,1);
                    if(dp[1][L][R-1]!=INF)RS=dp[1][L][R-1]+cost(L,R-1,1,1);    //走到右邊，所以前一個狀態是L,R-1
                    dp[1][L][R]=min(LS,RS);
                }
                //cout<<L<<" "<<R<<" "<<dp[0][L][R]<<" "<<dp[1][L][R]<<endl;
            }
        }
        printf("%d\n",ans+min((int)dp[0][1][N+1],(int)dp[1][1][N+1]));
    }
    return 0;
}
