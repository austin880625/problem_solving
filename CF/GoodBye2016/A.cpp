#include <stdio.h>
#include <iostream>

using namespace std;

int N,K;

int main()
{
    while(scanf("%d%d",&N,&K)==2)
    {
        int tmp=0;
        int i=0;
        for(i=1;i<=N;i++)
        {
            tmp+=5*i;
            if(tmp>240-K){break;}
        }
        i--;
        printf("%d\n",i);
    }
    return 0;
}
