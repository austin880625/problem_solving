#include <iostream>
#include <stdio.h>
#define MAXN 205
using namespace std;

int w[MAXN][MAXN];
int LEFT[MAXN];
bool visS[MAXN],visT[MAXN];
int N,M;

int match(int i)
{
    visS[i]=true;
    for(int j=1;j<=N;j++)
    {
        if(w[i][j]&&!visT[j])
        {
            visT[j]=true;
            if(!LEFT[j]||match(LEFT[j]))
            {
                LEFT[j]=i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)w[i][j]=0;
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            w[u][v]=1;
        }
        int ans=0;
        for(int i=1;i<=N;i++)LEFT[i]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)visS[j]=visT[j]=0;
            ans+=match(i);
        }
        printf("%d\n",N-ans);
    }
    return 0;
}
