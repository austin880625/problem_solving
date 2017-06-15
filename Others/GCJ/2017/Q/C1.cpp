#include <stdio.h>
#include <iostream>
#include <queue>
#define LL long long int

using namespace std;

int T;
LL N,K;

priority_queue<LL> Q;

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%lld%lld",&N,&K);
        Q.push(N);
        for(int i=0;i<K-1;i++)
        {
            LL t=Q.top();Q.pop();
            //cout<<t<<endl;
            LL l=(t-1)/2,r=t/2;
            if(l)Q.push(l);
            if(r)Q.push(r);
        }
        LL t=Q.top();Q.pop();
        LL l=(t-1)/2,r=t/2;
        printf("Case #%d: %lld %lld\n",kase,r,l);
        while(!Q.empty())Q.pop();
    }
    return 0;
}
