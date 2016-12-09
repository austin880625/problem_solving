#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 151
#define LL long long
#define MOD 1000000009

using namespace std;

int N,M;
int Q,L;

struct mat
{
    LL M[MAXN][MAXN];
    void reset(int x)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                M[i][j]=0;
                if(i==j&&x)M[i][j]=1LL;
            }
        }
    }
    void operator *=(const mat &r)
    {
        mat res;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                res.M[i][j]=0;
                for(int k=0;k<N;k++)
                {
                    res.M[i][j]+=((M[i][k]%MOD)*(r.M[k][j]%MOD))%MOD;
                    res.M[i][j]%=MOD;
                }
            }
        }
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)M[i][j]=res.M[i][j];
    }
};
mat DP[2];
int main()
{
    while(scanf("%d%d%d%d",&N,&M,&Q,&L)==4)
    {
        DP[0].reset(1);DP[1].reset(0);
        int u,v;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&u,&v);
            DP[1].M[u][v]+=1LL;
        }

        while(L)
        {
            if(L&1)DP[0]*=DP[1];
            DP[1]*=DP[1];
            L>>=1;
        }

        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&u,&v);
            printf("%lld\n",DP[0].M[u][v]);
        }
    }
    return 0;
}
