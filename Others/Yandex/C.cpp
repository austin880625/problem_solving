#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const ll mod = 1000000007;
ll d;
void ext_gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){d=a;x=1;y=0;return ;}//ax-by==a has solution (1,0)
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
	if(a==0)return 1;
	ll x,y;
	ext_gcd(a, mod, x,y);
	return (x%mod+mod)%mod;
}

const ll MAXN = 100005;
ll V[MAXN];
int S[MAXN];
ll P[MAXN];
vector<int> G[MAXN];
ll T[MAXN];
ll C[MAXN];
int N,M,K;

ll mpow(ll b, ll p){
	ll t=b, res=1;
	while(p){
		if(p&1){
			res*=t;
			res%=mod;
		}
		p>>=1;
		t=(t*t)%mod;
	}
	return res;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	ll inv2 = inv(2);
	for(int i=0; i<=N; i++)P[i]=0,T[i]=0,G[i].clear();
	for(int i=0; i<N; i++)scanf("%lld", V+i);
	for(int i=0; i<K; i++)scanf("%d", S+i), S[i]--;
	for(int i=0,s,t; i<M; i++){
		scanf("%d%d",&s,&t);
		s--; t--;
		G[s].push_back(t);
		C[s]+=V[t];
		G[t].push_back(s);
		C[t]+=V[s];
	}
	for(int i=0; i<K; i++){
		int u=S[i];
		int num=0;
		for(num=0; i+num<K&&S[i+num] == u; num++);
		for(int j=0; j<G[u].size(); j++){
			int v = G[u][j];
			T[v] += (num*V[v])%mod;
			T[v] %= mod;
		}
		P[u]+=num;
		V[u]*=mpow(inv2, num); V[u]%=mod;
		i+=num-1;
	}
	ll ans=0;
	for(int i=0; i<N; i++){
		//cout<<P[i]<<" "<<part[i].size()<<endl;
		if(T[i]&&P[i] == 0){ans=-1; break;}
		if(T[i]==0)continue;
		
		ll mp = mpow(2, P[i]);
		T[i] *= mp; T[i]%=mod;
		T[i] *= inv(mp-1); T[i]%=mod;
		ans+=T[i]; ans%=mod;
	}
	printf("%lld\n",ans);

	return 0;
}
