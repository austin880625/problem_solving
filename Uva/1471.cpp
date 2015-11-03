#include<iostream>
#include<stdio.h>
#define INF 2147483646
#define MAXN 200005

using namespace std;
int Z;
int N;
int tow[MAXN];
int L[MAXN];
int R[MAXN];
int d[MAXN];
int g[MAXN];

int ans;

int BS(int L,int R,int x)   //find a length that can attach tow[i]
{
    int mid;
    while(L<R)
    {
        mid=(L+R)/2;
        if(x<=g[mid])R=mid;
        else L=mid+1;
    }
    return L-1;
}

int main()
{
    scanf("%d",&Z);
    while(Z--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tow[i]);
            g[i]=INF;
        }
        g[0]=0;
        g[1]=tow[0];
        g[N]=INF;
        for(int i=0;i<N;i++)
        {
            L[i]=1;
            if(i&&tow[i]>tow[i-1])L[i]=L[i-1]+1;
        }
        for(int i=N-1;i>=0;i--)
        {
            R[i]=1;
            if(i<N-1&&tow[i]<tow[i+1])R[i]=R[i+1]+1;
        }
        int ans=R[0];
        for(int i=1;i<N;i++)
        {
            int G=BS(1,i,tow[i]);
            ans=max(ans,R[i]+G);
            g[L[i]]=min(g[L[i]],tow[i]);
        }
        printf("%d\n",ans);
    }
}
