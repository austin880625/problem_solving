#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXN 1000005
#define LL long long int

using namespace std;

int N;
LL A[MAXN];

int main()
{
    while(scanf("%d", &N)==1)
    {
        for(int t=0;t<N;t++)
        {
            scanf("%lld",A+t);
        }
        if(N==1){cout<<A[0]<<endl;continue;}
        sort(A,A+N);
        int i;
        for(i=0;i<N&&A[i]<=0;i++);
        LL ans=0;
        if(i==N)
        {
            ans=A[N-1];
            for(int j=0;j<N-1;j++)
            {
                ans-=A[j];
            }
        }
        else if(i==0)
        {
            ans=-A[i];
            for(int j=0;j<N;j++)
            {
                if(i!=j)ans+=A[j]>0 ? A[j] : -A[j];
            }
        }
        else
        {
            for(int j=0;j<N;j++)
            {
                ans+=A[j]>0 ? A[j] : -A[j];
            }
        }
        printf("%lld\n",ans);
    }
}
