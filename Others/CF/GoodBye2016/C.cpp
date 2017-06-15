#include <stdio.h>
#include <iostream>
#define INF 2147483647
#define ING 2147483647000
#define LL long long int

using namespace std;

int N;
long long int low,high;
int c,d;
long long int ans;

int main()
{
    while(scanf("%d",&N)==1)
    {
        low=-INF,high=ans=ING;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&c,&d);
            if(d==1)
            {
                if(high<1900){ans=-1; } //impossible
                high+=(LL)c;
                low=max(low,1900LL)+(LL)c;
            }
            else
            {
                if(low>=1900){ans=-1;}
                high=min(high,1899LL)+(LL)c;
                low+=(LL)c;
            }
            if(low>high){ans=-1;}
        }
        if(ans==-1)puts("Impossible");
        else if(high>INF)puts("Infinity");
        else printf("%I64d\n",high);
    }
    return 0;
}
