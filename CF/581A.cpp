#include <stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a>b)
        {
            printf("%d %d\n",b,(a-b)/2);
        }
        else
        {
            printf("%d %d\n",a,(b-a)/2);
        }
    }
    return 0;
}