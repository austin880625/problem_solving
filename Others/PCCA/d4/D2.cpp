#include <stdio.h>
#include <iostream>
#define MAXN 50005

using namespace std;

int maxv[2*MAXN],minv[2*MAXN],ch[2*MAXN][2];
int pointer;
int newNode(){minv[++pointer]=100000000;maxv[pointer]=-100000000;ch[pointer][0]=ch[pointer][1]=0;return pointer;}

int T;
int N,Q;
int A[MAXN];
int L,R;

inline int getmin(int o)
{
    return o?minv[o]:100000000;
}
inline int getmax(int o)
{
    return o ? maxv[o]:-100000000;
}

void build(int &o,int l,int r)
{
    if(!o)o=newNode();
    if(l==r){maxv[o]=minv[o]=A[l];return ;}
    int mid=(l+r)>>1;
    build(ch[o][0],l,mid);
    build(ch[o][1],mid+1,r);
    minv[o]=min(getmin(ch[o][0]),getmin(ch[o][1]));
    maxv[o]=max(getmax(ch[o][0]),getmax(ch[o][1]));
}

int querymax(int o,int l,int r)
{
    //cout<<L<< " " <<R<<" "<<l<<" "<<r<<endl;
    if(L<=l&&r<=R){return maxv[o];}
    int mid=(l+r)>>1;
    int res=-100000000;
    if(L<=mid)res=max(res,querymax(ch[o][0],l,mid));
    if(R>mid)res=max(res,querymax(ch[o][1],mid+1,r));
    return res;
}
int querymin(int o,int l,int r)
{
    if(L<=l&&r<=R){return minv[o];}
    int mid=(l+r)>>1;
    int res=100000000;
    if(L<=mid)res=min(res,querymin(ch[o][0],l,mid));
    if(R>mid)res=min(res,querymin(ch[o][1],mid+1,r));
    return res;
}

int main()
{
    while(scanf("%d%d",&N,&Q)==2)
    {
        T=0;
        pointer=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&A[i]);
        }
        build(T,1,N);
        //cout<<T<<" "<<ch[T][0]<<endl;
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&L,&R);
            printf("%d\n",querymax(T,1,N)-querymin(T,1,N));
        }
    }
    return 0;
}
