#include <stdio.h>
#include <iostream>

using namespace std;
typedef long long int ll;
const ll mod = 1000000007LL;
void ext_gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){x=1;y=0;return ;}//ax-by==a has solution (1,0)
    ext_gcd(b,a%b,x,y);//after this we have x=x0,y=y0 and bx0-(a%b)y0==d
    ll x0=x,y0=y;
    /*
    a=bq+r
    bx0-ry0==d
    To solve ax-by==d:
    we have
      ax-by
    == (bq+r)x-by
    == bqx-by + rx

    == b(qx-y) + rx
    == bx0     - ry0
        / qx-y==x0
    => {
        \ x=-y0
    */
    x=-y0;
    y=-(a/b)*y0-x0;
}

ll inv(ll a){
	ll x,y;
	//a*x = 1 mod 10^9+7
	//a*x-10^9+7y = 1
	ext_gcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

ll s1[100005];
ll s2[100005];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	ll lp=1, lq=1;
	ll lps=1, lqs=1;
	ll p,q,ps,qs;
	int z=0;
	for(int i=0; i<n; i++){scanf("%I64d",s1+i);}
	for(int i=0; i<n; i++){scanf("%I64d",s2+i);}
	if(s1[0]==0){
		if(s2[0])lp=m-s2[0],lq=m,lps=1,lqs=m;
		else lp=(m-1),lq=2*m;lps=1,lqs=m;
	}else{
		if(s2[0]==0)lp=s1[0]-1,lq=m,lps=1,lqs=m;
		else {
			if(s1[0]==s2[0]){
				lp=0,lq=1,lps=1,lqs=1;
			}else{
				lp=(s1[0]>s2[0] ? 1:0),lq=1,lps=0,lqs=1;
			}
		}
	}
	lp%=mod;lq%=mod;lps%=mod;lqs%=mod;
	p=lp;q=lq;ps=lps;qs=lqs;
	for(int i=1; i<n; i++){
		if(s1[i]==0){
			if(s2[i]){
				p=(m-s2[i])*((lps*lq)%mod) + m*((lqs*lp)%mod);
				q=m * ((lqs * lq)%mod);
				ps=lps;
				qs=lqs*m;
			}else{
				p=2*m*((lqs*lp)%mod) + (m-1)*((lps*lq)%mod);
				q=2*m*((lqs*lq)%mod);
				ps=lps;
				qs=lqs*m;
			}
		}else{
			if(s2[i]==0){
				p=(s1[i]-1)*((lps*lq)%mod) + m*((lp*lqs)%mod);
				q=m*((q*qs)%mod);
				ps=lps;
				qs=lqs*m;
			}else{
				if(s1[i]==s2[i]){
					p=lp;q=lq;
					ps=lps;qs=lqs;
				}else{
					if(s1[i]>s2[i]){
						p=(lp*lqs)%mod+(lps*lq)%mod;
						q=(lq*lqs)%mod;
					}else{
						p=lp;q=lq;
					}
					ps=0;qs=1;
				}
			}
		}
		p%=mod;q%=mod;ps%=mod;qs%=mod;
		ll d=gcd(p,q), ds=gcd(ps,qs);
		p/=d;q/=d;ps/=ds;qs/=ds;
		lp=p;lq=q;lps=ps;lqs=qs;
		//printf("%lld %lld %lld %lld\n",p,q,ps,qs);
	}
		ll d=gcd(p,q), ds=gcd(ps,qs);
		p/=d;q/=d;ps/=ds;qs/=ds;
	printf("%I64d\n",(p*inv(q))%mod);
	return 0;
}
