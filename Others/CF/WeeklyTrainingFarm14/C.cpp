#include <stdio.h>
#include <iostream>
#define MAXN 200005

using namespace std;

int x,y;
LL ANS[MAXN];

int main()
{
    while(scanf("%d%d",&x,&y)==2)
    {
        //S[y+1]<=S[x]-S[x-y]
        //S[y]>S[x]-S[x-y+1]=S[x]-S[x-y]-A[x-y+1]
        //S[y]+A[x-y+1]>S[x]-S[x-y]>=S[y]+A[y+1]
        if(x-y+1<=y+1)puts("impossible");
        else
        {
            printf("%d\n",x);

        }
    }
    return 0;
}
