#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        long long int t=1,ans=1;
        for(int i=n+2;i<=2*n;i++)
        {
            ans*=i;
            while(ans%t==0&&t<=n){ans/=t++;}
        }
        while(ans%t==0&&t<=n){ans/=t++;}
        printf("%lld\n",ans);
    }
    return 0;
}