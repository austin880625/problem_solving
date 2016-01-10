#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXN 505
#define BASE 2520
#define INF 1000000000000
#define LL long long int
using namespace std;

int T,M,N,K;
LL w[MAXN][MAXN];
LL Lx[MAXN],Ly[MAXN];
bool visS[MAXN],visT[MAXN];
int LEFT[MAXN];

bool match(int i)
{
    visS[i]=true;
    for(int j=1;j<=N;j++)
    {
        //cout<<j<<endl;
        if(Lx[i]+Ly[j]==w[i][j]&&!visT[j])
        {
            //cout<<M<<endl;
            //printf("i:%d j:%d %d\n",i,j,M);
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

void update()
{
    LL a=INF;
    for(int i=1;i<=M;i++)
    {
        if(visS[i])
        for(int j=1;j<=N;j++)
        {
            if(!visT[j])
            a=min(a,Lx[i]+Ly[j]-w[i][j]);
        }
    }
    for(int i=1;i<=M;i++)
    {
        if(visS[i])Lx[i]-=a;
        //printf("%lld %lld\n",Lx[i],Ly[i]);
    }
    for(int i=1;i<=N;i++)
    {
        if(visT[i])Ly[i]+=a;
    }
}

void KM()
{
    for(int i=0;i<=M;i++)
    {
        Lx[i]=0;
        for(int j=1;j<=N;j++)
        {
            Lx[i]=max(Lx[i],w[i][j]);
        }
    }
    for(int i=0;i<=N;i++)Ly[i]=LEFT[i]=0;
    //for(int i=1;i<=N;i++)printf("%d %d\n",Lx[i],Ly[i]);
    for(int i=1;i<=M;i++)
    {
        while(1)
        {
            //cout<<M<<endl;
            for(int j=1;j<=M;j++)visS[j]=0;
            for(int j=1;j<=N;j++)visT[j]=0;
            if(match(i))break;
            else update();
            //printf("matching %d\n",i);
        }
    }
}

LL gcd(LL a,LL b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(a%b,b);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&M,&N,&K);
        //cout<<M<<endl;
        if(M>N)N=M;
        memset(w,0,sizeof(w));
        for(int i=0;i<K;i++)
        {
            int u,v;
            LL p,q;
            scanf("%d%d%lld%lld",&u,&v,&q,&p);
            q*=(BASE/p);
            w[u][v]=q;
        }
        KM();
        LL ans=0;
        for(int i=1;i<=M;i++)ans+=Lx[i];
        for(int i=1;i<=N;i++)ans+=Ly[i];
        LL d=gcd(ans,BASE);
        printf("%lld %lld\n",ans/d,BASE/d);
    }
}
/*
1
2 2 4
1 1 1 1
1 2 2 1
2 1 2 1
2 2 4 1

*/
