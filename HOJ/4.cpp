#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 100005

using namespace std;

int B[MAXN];
vector<int> C;
int ring[MAXN];
int r;
int N;

int cnt(int i)
{
    int res=0;
    while(!ring[i])
    {
        //printf("%d ",i);
        ring[i]=r;
        i=C[i];
        res++;
    }
    //puts("");
    //printf("%d\n",res);
    return res-1;
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        r=0;
        C.clear();
        for(int i=1;i<=N;i++)ring[i]=0,scanf("%d",B+i);
        C.push_back(0);
        for(int i=1;i<=N;i++)
        {
            if(B[i]!=1)C.push_back(B[i]-1);
        }
        int ans=0;
        for(int i=1;i<N;i++)
        {
            if(!ring[i])r++,ans+=cnt(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
