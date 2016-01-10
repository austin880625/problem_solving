#include <iostream>
#include <stdio.h>
#define MAXN 1000000
using namespace std;

int A[MAXN];
int st[MAXN*4];
int N,M;
int L,R;
void build(int o,int l,int r)
{
    if(l==r){st[o]=A[l];return ;}
    int mid=(l+r)/2;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);
    st[o]=st[o*2]+st[o*2+1];
}
int query(int o,int l,int r)
{
    if(L<=l&&r<=R)return st[o];
    int mid=(l+r)/2;
    int res=0;
    if(L<=mid)res+=query(o*2,l,mid);
    if(R>mid)res+=query(o*2+1,mid+1,r);
    return res;
}
int main()
{
    while(scanf("%d %d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)scanf("%d",&A[i]);
        build(1,0,N-1);
        for(int i=0;i<M;i++)
        {
            scanf("%d %d",&L,&R);
            printf("%d\n",query(1,0,N-1));
        }
    }
}
