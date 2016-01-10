#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
int d1,d2,d3;
int main()
{
    while(scanf("%d%d%d",&d1,&d2,&d3)==3)
    {
        long long int ans=min(d1*2+d2*2,min(d1+d3+d2,min(d2*2+d3*2,d1*2+d3*2)));
        printf("%I64d\n",ans);
    }
    return 0;
}
