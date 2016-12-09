#include <stdio.h>
#define MAXN 1000005
int N;
int a[MAXN];
int lastone;

int main()
{
    while(scanf("%d",&N)==1)
    {
        lastone=-1;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            if(a[i])lastone=i;
        }
        int zeros=N-lastone-1;
        if(zeros>=3||zeros==1)puts("YES");
        else puts("NO");
    }
    return 0;
}
