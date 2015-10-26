#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct sculp
{
    int h,w,order;
    bool operator <(const sculp &rhs)const
    {
        if(h<rhs.h)return true;
        else if(h==rhs.h&&w<rhs.w)return true;
        else if(h==rhs.h&&w==rhs.w&&order<rhs.order)return true;
        return false;
    }
}S[10005];

int N;

int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d %d",&S[i].h,&S[i].w);
            S[i].order=i;
        }
        sort(S,S+N);
        int ans=0;
        for(int i=0;i<N;i++)
        {
            ans+=abs(S[i].order-i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
