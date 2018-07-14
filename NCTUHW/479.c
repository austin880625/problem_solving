#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#define MAXN 1048576
#define eps 0.5
#define PI 3.14159265358979323846264338327950288419716939937510
#define max(a,b) (((a) > (b)) ? (a) : (b))
int _n;
typedef double complex comp;
comp ww[MAXN], rw[MAXN];

comp A[MAXN], B[MAXN];
comp AB[MAXN];

void init(int n, int m){ // n terms in polynomial
	_n=1; while(_n<n+m)_n<<=1;
	ww[0] = rw[0] = 1.0 + 0.0*I;
	for(int k=1; k<_n; k++){
		ww[k]=cos(2*k*PI/_n) + sin(2*k*PI/_n)*I;
		rw[_n-k]=ww[k];
	}
}
int rev(int n,int x){int res=0;while(n){res<<=1;res|=x&1;x>>=1;n>>=1;}return res;}
void dft(int n, comp *res, comp *w){
	for(int i=0; i<n; i++){int j=rev(n>>1,i);if(i<j){comp tmp=res[j];res[j]=res[i];res[i]=tmp;}}
	for(int m=1; m<=n; m<<=1){ 
		if(m==1)continue;
		int mp = m>>1;
		for(int o = 0; o<n; o+=m){
			for(int i=0; i<mp; i++){
				comp tmp = w[i*(n/m)]*res[o+i+mp];
				res[o+i + mp] = res[o+i] - tmp;
				res[o+i] = res[o+i] + tmp;
			}
		}
	}
}

void FFT(comp *A, comp *B){
	dft(_n, A, ww); dft(_n, B, ww);
	for(int i=0; i<_n; i++)AB[i] = A[i]*B[i];
	dft(_n, AB, rw);
}
typedef long long int ll;
ll a[100005];
ll ans[1048576];
ll cnt[1048576];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init(1<<16, 1<<16);
	for(int i=0; i<n; i++){scanf("%lld", a+i); A[a[i]] += 1+0*I; B[a[i]] += 1+0*I; cnt[a[i]]++; }
	FFT(A, B);
	for(int i=0; i<1<<17; i++){
		ans[i] = (ll)(creal(AB[i])/_n + eps );
		ans[i]/=2;
		if(i%2 == 0){
			ans[i] -= cnt[i/2]/2;
		}
	}
	//for(int i=0; i<10; i++)printf("%f ", creal(AB[i])/_n);puts("");
	for(int i=0; i<m; i++){
		int s;
		scanf("%d", &s);
		printf("%lld\n", ans[s]);
	}
	return 0;
}
