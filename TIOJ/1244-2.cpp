#include <stdio.h>
#include <iostream>
#include <vector>

#define MAXN 10005
#define LL long long
#define MOD 100000007LL

using namespace std;

int N;
LL ans[MAXN];
LL F[MAXN],G[MAXN];

void ext_gcd(LL &x,LL &y,LL a,LL b)
{
    if(b==0){x=1,y=0;return ;}
    LL q=a/b;
    LL r=a-b*q;
    LL x0,y0;
    ext_gcd(x0,y0,b,r);
    x=-y0;
    y=-x0-q*y0;
}

inline LL inv(LL a)
{
    //solve x in ax-My=1
    LL x,y;
    ext_gcd(x,y,a,MOD);
    return x;
}

LL getC(int n, int m)
{
    LL res=(F[n]*G[m]+MOD)%MOD;
    res=(res*G[n-m]+MOD)%MOD;
    return res;
}

int main()
{
    for(int i=0;i<MAXN;i++)ans[i]=0;ans[1]=F[1]=G[1]=F[0]=G[0]=1;
    for(int i=2;i<=10000;i++){F[i]=(F[i-1]*i)%MOD;G[i]=inv(F[i]);}
    //cout<<G[2]<<" "<<getC(2,2)<<endl;
    while(scanf("%d",&N)==1)
    {
        if(ans[N]!=0){printf("%lld\n",ans[N]);continue;}
        for(int i=1;i<=N;i++)
        {
            ans[i]=1;
            for(int j=1;j<i;j++)
            {
                ans[i]=(ans[i]+ans[j]*getC(i-1,j)+MOD)%MOD;
            }
        }
        printf("%lld\n",ans[N]);
    }
    return 0;
}
