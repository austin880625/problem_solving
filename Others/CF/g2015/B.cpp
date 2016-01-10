#include <iostream>
#include <stdio.h>
#include <assert.h>
#define LL long long int
using namespace std;

int cnt(LL x)
{
    int res=0;
    while(x>0)res++,x>>=1;
    return res;
}

int main()
{
    LL A,B;
    while(scanf("%I64d%I64d",&A,&B)==2)
    {
        int ans=0;
        //cout<<cnt(A)<<endl;
        for(LL X=(1LL<<(cnt(A)-1LL))-1LL;(X>>1LL)<=B;X=(X<<1LL)^1LL)
        {
            //cout<<X;
            //assert(X>=A);
            int C=cnt(X);
            for(int i=0;i<C;i++)
            {
                LL t=X^(1LL<<i);
                //cout<<t<<endl;
                if(t<=B&&t>=A&&i!=C-1)ans++;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
