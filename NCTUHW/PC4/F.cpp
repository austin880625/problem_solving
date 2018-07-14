#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

long long int p,q;
vector<int> pr;
typedef long long ll;
#define MAXN 1000005
ll isp[MAXN];
int pi[MAXN];
int rub[MAXN];

void pre(){
	pi[0]=0;
	for(int i=2; i<=MAXN; i++)isp[i]=1;
	for(int i=2; i<=MAXN; i++){
		pi[i]=pi[i-1]+isp[i];
		if(!isp[i])continue;
		pr.push_back(i);
		for(int j=i*2; j<=MAXN; j+=i){
			isp[j]=0;
		}
	}
}

char tmp[20];

void prerub(){
	rub[0]=0;
	for(int i=1; i<=MAXN; i++){
		int l = sprintf(tmp, "%d", i);
		int f=1;
		for(int i=0; i*2<l; i++)if(tmp[i] != tmp[l-i-1])f=0;
		if(f)rub[i] = rub[i-1]+1;
		else rub[i] = rub[i-1];
	}
}

int main()
{
	pre();
	prerub();
	scanf("%d%d", &p, &q);
	int ans=-1;
	for(int i=MAXN-1; i>=1; i--){
		if(q*pi[i] <= p*rub[i]){ans=i; break;}
	}
	printf("%d\n", ans);
	return 0;
}
