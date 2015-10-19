#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define ll long long int
using namespace std;

ll x,y,a,b;

ll gcd(ll a,ll b)
{
    if(a>b)swap(a,b);
    if(a==0)return b;
    else return gcd(b%a,a);
}

ll lcm(ll a,ll b)
{
    if(a==0||b==0)return 0;
    ll d=gcd(a,b);
    ll k1=a/d,k2=b/d;
    ll K1=k1,K2=k2;
    int A=0,B=0;
    while(1)
    {
        if(!K1&&!K2)break;
        if(K1)
        {
            K1/=10;
            A++;
        }
        if(K2)
        {
            K2/=10;
            B++;
        }
    }
    if(A+B>=18)return 0;
    ll res=d*k1*k2;
    return res;
}

ll getQ(ll a,ll b)
{
    if(b==0)
    {
        if(a>=0)return 1;
        else return 0;
    }
    if(a<0&&a%b!=0)return (a/b)-1;
    if(a<0&&a%b==0)return a/b;
    else return a/b;
}
ll getR(ll a,ll b)
{
    if(b==0)
    {
        return a!=0;
    }
    return a%b;
}

int main()
{
    
    while(scanf("%lld %lld %lld %lld",&a,&b,&x,&y)==4)
    {
        x=x>0 ? x : -x;
        y=y>0 ? y : -y;
        ll D=lcm(x,y);
        ll ans=((getQ(b,x)-getQ(a,x))+(getQ(b,y)-getQ(a,y))-(getQ(b,D)-getQ(a,D)));
        //cout<<ans<<endl;
        if(getR(a,x)==0)ans++;
        if(getR(a,y)==0)ans++;
        if(getR(a,D)==0)ans--;
        printf("%lld\n",ans);
    }
    
}