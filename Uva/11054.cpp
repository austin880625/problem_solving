#include <iostream>
#include <stdio.h>
#define MAXN 100000
using namespace std;
int N;
int A[MAXN];
int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        long long int ans=0,rate=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
            ans+=rate>0 ? rate : -rate;
            rate-=A[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
