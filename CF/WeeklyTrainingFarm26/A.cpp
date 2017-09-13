#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int x,d;
    while(scanf("%d%d",&x,&d)==2)
    {
        if(d>0)
        {
            printf("%d\n",x*2+d-1);
        }
        else if(d==0)
        {
            printf("%d\n",x*2+d-1);
        }
        else
        {
            printf("%d\n",x*2-2);
        }
    }
    return 0;
}
