#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 10005
using namespace std;
int R[MAXN];
int S;
int N;

int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        S=0,R[0]=0;
        for(int i=1;i<=N;i++)scanf("%d",&R[i]),R[i]*=2,S+=R[i];
        sort(R+1,R+1+N);
        int ans=N;
        for(int i=N;i>=0;i--)
        {
            S-=R[i];
            if(S>=R[i]){ans=i;break;}
        }
        printf("%d\n",ans);
    }
}
