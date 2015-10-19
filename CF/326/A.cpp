#include<iostream>
#include <stdio.h>
#include<math.h>
#define inf 105
int p[100005];
int A[100005];
int main()
{
    int n;
    
    while(scanf("%d",&n)==1)
    {
        int sum=0,ans=0,mincost;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&A[i],&p[i]);
            sum+=A[i];
        }
        ans=p[0]*sum;
        mincost=p[0];
        for(int i=0;i<n;i++)
        {
            if(p[i]<mincost)
            {
                ans-=(mincost-p[i])*sum;
                mincost=p[i];
            }
            sum-=A[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
