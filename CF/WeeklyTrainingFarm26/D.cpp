#include <stdio.h>
#include <iostream>
#define LL long long int
using namespace std;

LL A,B,N,P;

void gcd(LL m,LL p,LL &x,LL &y)
{
    if(p==1){x=0,y=-1;return ;}
    LL q=m/p,r=m%p; //m=pq+r
    LL xx,yy;
    gcd(p,r,xx,yy);
    x=-yy;
    y=q*x-xx;
}
LL inv(int x)
{
    LL res,t;
    gcd(x,P,res,t);
    res=res+((-res/P)+1)*P;
    return res;
}

int main()
{
    while(scanf("%I64d%I64d%I64d%I64d",&A,&B,&N,&P)==4)
    {
        LL D=1;
        int power=0;
        LL S=max(B,A-B),T=min(B,A-B);
            for(LL i=S+1;i<=A;i++)
            {
                LL t=i;
                while(t%P==0)t/=P,power++;
                D*=t,D%=P;
            }
            for(LL i=2;i<=T;i++)
            {
                LL t=i;
                while(t%P==0)t/=P,power--;
                D*=inv(t),D%=P;
            }
        LL ans;
        if(power==0)ans=D;
        else ans=0;
        for(int k=0;k<N;k++)
        {
            LL t=A+k+1;
            while(t%P==0)t/=P,power++;
            D*=t;D%=P;
            t=B+k+1;while(t%P==0)t/=P,power--;
            D*=inv(t);D%=P;
            if(power==0)ans=max(ans,D);
            else ans=max(ans,0LL);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
