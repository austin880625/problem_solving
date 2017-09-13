#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN
#define LL long long int

using namespace std;

int main()
{
    int N,p,q;
    while(scanf("%d",&N)==1)
    {
        q=0,p=N;
        for(int i=1;i*2<=N;i++)
        {
            if(__gcd(i,N-i)==1)
            {
                if(i*p>q*(N-i))q=i,p=N-i;
            }
        }
        printf("%d %d\n",q,p);
    }
    return 0;
}
