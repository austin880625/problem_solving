#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int ll;

int T,N;
const int MAXN=100005;
int a[MAXN];
map<int, int> idx;
typedef pair<int, int> pii;

ll C[2][MAXN];
const ll MOD = 1000000007;
void add(int t,int p, ll x){
	while(p<=N){
		C[t][p]+=x;
		C[t][p]%=MOD;
		p+=(p&(-p));
	}
}
ll sum(int t,int p){
	ll res=0;
	while(p){
		res+=C[t][p];
		res%=MOD;
		p-=(p&(-p));
	}
	return res;
}

ll dp[2][MAXN];

int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			scanf("%d", a+i);
			idx.insert(pii(a[i],0));
		}
		int i=1;
		for(map<int, int>::iterator it=idx.begin(); it!=idx.end(); it++){
			idx[it->first] = i;
			i++;
		}
		
		for(int i=0;i<=N;i++)C[0][i]=C[1][i]=0;
		for(int i=0; i<N; i++){
			int des = idx[a[i]];
			dp[0][i]=sum(0,des-1) + sum(1,des-1);
			dp[0][i]%=MOD;
			add(0, des, dp[0][i]);
			add(1, des, 1);
		//	cout<< dp[0][i]<<" ";
		}
		for(int i=0;i<=N;i++)C[0][i]=C[1][i]=0;
		for(int i=N-1; i>=0; i--){
			int des = idx[a[i]];
			dp[1][i]=sum(0,des-1) + sum(1,des-1);
			dp[1][i]%=MOD;
			add(0, des, dp[1][i]);
			add(1, des, 1);
		}
		ll ans=0;
		for(int i=0; i<N; i++){
			ans+=(dp[0][i]*dp[1][i])%MOD; ans%=MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
