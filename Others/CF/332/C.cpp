#include <iostream>
#include <stdio.h>
#define MAXN 100005
#define INF 2147483647
using namespace std;

int H[MAXN];
int MAXV[MAXN],MINV[MAXN];
int N;
int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d",&H[i]);
        }
        int ans=0;
        MAXV[0]=MINV[0]=H[0];
        for(int i=0;i<N;i++)
        {
            if(i)MAXV[i]=max(MAXV[i-1],H[i]);
            if(i)MINV[i]=min(MINV[i-1],H[i]);
        }
        int l,r;
        for(l=0,r=0;r<N;r++)
        {
            if(MINV[r]>=MAXV[l]){ans++;l=r+1;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
