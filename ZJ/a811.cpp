#include<iostream>
#include<stdio.h>
#include<algorithm>
#define ll long long int

using  namespace std;

ll gcd(ll a,ll b)
{
    //cout<<a<<" "<<b<<endl;
    if(a>b)swap(a,b);
    if(a==0)return b;
    else return gcd(b-a*(b/a),a);
}

ll X[10005];
int n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&X[i]);
        }
        sort(X,X+n);
        ll ans=X[1]-X[0];
        for(int i=1;i<n-1;i++)
        {
            ans=min(ans,gcd(ans,X[i+1]-X[i]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}