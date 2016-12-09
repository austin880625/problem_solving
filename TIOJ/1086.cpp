#include <stdio.h>
#include <iostream>
#define LL long long int

using namespace std;

LL frac[25];
LL dp[25];

int main()
{
    frac[0]=1;
    for(int i=1;i<25;i++)frac[i]=frac[i-1]*i;
    dp[0]=1;
    dp[1]=0;
    for(int i=2;i<25;i++)
    {
        dp[i]=frac[i];
        for(int j=1;j<=i;j++)
        {
            dp[i]-=((frac[i]/frac[j])/frac[i-j])*dp[i-j];
        }
    }
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        printf("%lld\n",dp[n]);
    }
    return 0;
}
