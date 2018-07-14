#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;
ll cnt[262144];
ll ans[1][262144];
ll z1[20][262144], tmp1[20][262144], tmp2[20][262144];

void karatsuba(ll *res, ll *a, ll *b, int n, int dep){
	//cout<<"a and b at "<<dep<<": " <<endl;
	//for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
	//for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
	//cout<<endl;
	if(n==2){
		res[0] = a[0]*b[0];
		res[1] = a[0]*b[1] + a[1]*b[0];
		res[2] = a[1]*b[1];
		res[3] = 0;
		return ;
	}
	int m = n/2;
	karatsuba(res, a, b, m, dep+1);
	karatsuba(res+n, a+m, b+m, m, dep+1);
	//cout<<"tmp res at "<<dep<<endl;
	//for(int i=0; i<2*n; i++)cout<<res[i]<<" ";cout<<endl;
	for(int i=0; i<m; i++){
		tmp1[dep][i] = a[i] + a[m+i];
		tmp2[dep][i] = b[i] + b[m+i];
	}
	karatsuba(z1[dep], tmp1[dep], tmp2[dep], m, dep+1);
	for(int i=0; i<n; i++){
		z1[dep][i] -= res[i];
		z1[dep][i] -= res[n+i];
	}
	for(int i=0; i<n; i++){
		res[m+i] += z1[dep][i];
	}
	//cout<<"final res at "<<dep<<endl;
	//for(int i=0; i<2*n; i++)cout<<res[i]<<" ";cout<<endl;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	ll maxv=0;
	for(int i=0; i<n; i++){
		ll v;
		scanf("%lld", &v);
		maxv=max(maxv,v);
		cnt[v]++;
	}
	int _n = 1; while(_n <= maxv)_n<<=1;
	karatsuba(ans[0], cnt, cnt, _n, 0);
	for(int i=0; i<(1<<17); i++){
		ans[0][i]/=2;
		if(i%2 == 0){
			ans[0][i] -= cnt[i/2]/2;
		}
	}
	for(int i=0; i<m; i++){
		ll q;
		scanf("%lld", &q);
		printf("%lld\n", ans[0][q]);
	}
	return 0;
}
