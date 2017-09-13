#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int d[1000005];
int n;
int t0,t1;

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<=1000000;i++)d[i]=0;
        for(int i=0;i<n;i++)scanf("%d%d",&t0,&t1),d[t0]++,d[t1]--;

        long long int x=0,ans=0;
        for(int i=1;i<=1000000;i++)x+=d[i],ans+=x*x;
        printf("%I64d\n",ans);
    }
    return 0;
}
