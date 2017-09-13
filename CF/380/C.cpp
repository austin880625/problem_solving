#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 200005

using namespace std;

int needt[MAXN];
int needc[MAXN];
int N,K;
long long int S,T;
long long int c[MAXN],v[MAXN];
long long int g[MAXN];

int main()
{
    while(scanf("%d%d%I64d%I64d",&N,&K,&S,&T)==4)
    {
        for(int i=0;i<N;i++)scanf("%I64d%I64d",v+i,c+i);
        for(int i=1;i<=K;i++)scanf("%I64d",g+i);
        g[0]=0;
        g[K+1]=S;
        sort(g+1,g+K+2);
        long long int M=0;
        for(int i=1;i<=K+1;i++)
        {
            M=max(M,g[i]-g[i-1]);
        }
        long long int l=M,r=2*S+1;
        while(l<r)
        {
            long long int mid=(l+r)/2;
            long long int t=0;
            for(int i=1;i<=K+1;i++)
            {
                t+=max(3LL*(g[i]-g[i-1])-mid,g[i]-g[i-1]);
            }
            if(t<=T)r=mid;
            else l=mid+1;
        }
        long long int ans=1000000001;
        for(int i=0;i<N;i++)
        {
            if(c[i]>=l)ans=min(ans,v[i]);
        }
        printf("%d\n",(l==2*S+1||ans==1000000001 ? -1 : ans));
    }
    return 0;
}
