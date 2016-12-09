#include <stdio.h>
#include <iostream>
#define MAXT 1005
using namespace std;

int S,T;
int d[MAXT];
bool is_prime[MAXT];

void pre_process()
{
    for(int i=0;i<MAXT;i++)is_prime[i]=true;
    is_prime[1]=false;
    for(int i=2;i<MAXT;i++)
    {
        if(is_prime[i])
        {
            for(int j=2*i;j<MAXT;j+=i)is_prime[j]=false;
        }
    }
}

int main()
{
    int kase=0;
    pre_process();
    while(scanf("%d%d",&S,&T)==2&&(S||T))
    {
        printf("Case %d: ",++kase);
        for(int i=0;i<MAXT;i++)d[i]=-1;
        d[S]=0;
        for(int i=S;i<T;i++)
        {
            if(d[i]!=-1)
                for(int j=2;j*j<=i;j++)
                {
                    if(i%j==0)
                    {
                        if(is_prime[j])
                            d[i+j]=d[i+j]==-1 ? d[i]+1 : min(d[i]+1,d[i+j]);
                        if(is_prime[i/j])
                            d[i+i/j]=d[i+i/j]==-1 ? d[i]+1 : min(d[i]+1,d[i+i/j]);
                    }
                }
        }
        printf("%d\n",d[T]);
    }
}
