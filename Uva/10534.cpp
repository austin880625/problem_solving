#include <iostream>
#include <stdio.h>
#define MAXN 10005
#define INF 2147483647
using namespace std;
int A[MAXN];
int dpl[MAXN],dpr[MAXN];
int g[MAXN],h[MAXN];
int N;
int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<=N;i++)
        {
            if(i<N)scanf("%d",&A[i]);
            g[i]=INF;h[i]=INF;
            dpl[i]=dpr[i]=0;
        }
        g[0]=0;g[1]=A[0];
        for(int i=0;i<N;i++)
        {
            int l=0,r=i+1;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(g[mid]<A[i])l=mid+1;
                else r=mid;
            }
            dpl[i]=l;
            g[dpl[i]]=min(g[dpl[i]],A[i]);
        }
        h[0]=0;h[1]=A[N-1];
        for(int  i=N-1;i>=0;i--)
        {
            int l=0,r=N-i;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(h[mid]<A[i]){l=mid+1;}
                else r=mid;
            }
            dpr[i]=l;
            //if(i==0)cout<<dpr[i]<<endl;
            h[dpr[i]]=min(h[dpr[i]],A[i]);
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            //cout<<dpl[i]<<" "<<dpr[i]<<endl;
            int len=min(dpl[i],dpr[i]);
            ans=max(len*2-1,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
