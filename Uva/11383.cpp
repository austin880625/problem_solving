#include <iostream>
#include <stdio.h>
#define MAXN 505
#define INF 0x3f3f3f3f
using namespace std;

int w[MAXN][MAXN];
int Lx[MAXN],Ly[MAXN];
int LEFT[MAXN];
bool visS[MAXN],visT[MAXN];
int N;

void update()
{
    int a=INF;
    for(int i=1;i<=N;i++)
    {
        if(visS[i])
        for(int j=1;j<=N;j++)
        {
            if(!visT[j])
                a=min(a,Lx[i]+Ly[j]-w[i][j]);
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(visS[i])Lx[i]-=a;
        if(visT[i])Ly[i]+=a;
    }
}

bool match(int i)
{
    visS[i]=true;
    for(int j=1;j<=N;j++)
    {
        if(Lx[i]+Ly[j]==w[i][j]&&!visT[j])
        {
            visT[j]=true;
            if(!LEFT[j]||match(LEFT[j]))
            {
                LEFT[j]=i;
                return true;
            }
        }
    }
    return false;
}

void KM()
{
    for(int i=1;i<=N;i++)LEFT[i]=0;
    for(int i=1;i<=N;i++)
    {
        while(1)
        {
            for(int j=1;j<=N;j++)visS[j]=visT[j]=false;
            if(match(i))break;
            else update();
        }
    }
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d",&w[i][j]);
                Lx[i]=max(Lx[i],w[i][j]);
            }
            Ly[i]=0;
        }
        KM();
        int ans=Lx[1]+Ly[1];
        printf("%d",Lx[1]);
        for(int i=2;i<=N;i++)printf(" %d",Lx[i]),ans+=Lx[i];
        puts("");
        printf("%d",Ly[1]);
        for(int i=2;i<=N;i++)printf(" %d",Ly[i]),ans+=Ly[i];
        puts("");
        printf("%d\n",ans);
    }
    return 0;
}
