#include <iostream>
#include <stdio.h>
#include <assert.h>

#define MAXV 1000005
#define MAXN 10005

using namespace std;

int N;
int backpack[MAXV];
int radix[MAXN];

int main()
{
    for(int i=0;i<MAXV;i++)backpack[i]=0;
    int kase=0;
    while(scanf("%d",&N)==1)
    {
        if(N==0)break;
        int V,ans=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&V);
            backpack[V]++;
            ans=max(ans,backpack[V]);
        }
        int t=0;
        for(int i=0;i<MAXV;i++)
        {
            while(backpack[i])
            {
                radix[t++]=i;
                backpack[i]--;
            }
        }

        if(kase++)puts("");
        printf("%d\n",ans);
        for(int i=0;i<ans;i++)
        {
            printf("%d",radix[i]);
            for(int j=i+ans;j<N;j+=ans)
            {
                printf(" %d",radix[j]);
            }
            puts("");
        }
    }
}
