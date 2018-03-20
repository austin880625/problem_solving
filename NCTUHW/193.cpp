#include <stdio.h>
#include <iostream>
#define MOD 1000000007
#define LL long long int

using namespace std;

LL a,b,M;
LL ff[10005],ffi[10005];

//solving ax-by=1
void extGCD(LL a0, LL b0, LL &x, LL &y)
{
    //cout<<"gg"<<a0<<" "<<b0<<endl;
    if(b0==0){x=1;y=0;return ;}
    extGCD(b0, a0%b0, x, y);
    LL x0=x,y0=y;
    x=-y0;
    y=-(a0/b0)*y0-x0;
}

LL inv(LL t)
{
    //ax=1(mod MOD)
    //ax-MOD*y=1
    LL x,y;
    extGCD(t, MOD, x, y);
    return x;
}

LL calc(LL a, LL b, LL cell)
{

    a=(a/cell)%M,b=(b/cell)%M;
    if(a<b)return 0;
    if(a==b||b==0)return 1;
    LL res=1;
    res*=ff[a];res%=MOD;
    //cout<<res<<" "<<ffi[b]<<endl;
    res*=ffi[b];res%=MOD;
    res*=ffi[a-b];res%=MOD;
    return res;
}

int main()
{
    int T;
    ff[0]=1;ffi[0]=1;
    for(int i=1;i<10005;i++)ff[i]=(ff[i-1]*i)%MOD,ffi[i]=inv(ff[i]),ffi[i]=(ffi[i]%MOD+MOD)%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&M);
        LL cell=1;
        LL ans=1;
        LL m=max(a,b);
        while(cell<=m)
        {
            ans*=calc(a,b,cell);
            ans%=MOD;
            //cout<<ans<<endl;
            cell*=M;
        }
        printf("%lld\n",ans%MOD);
    }
    return 0;
}
