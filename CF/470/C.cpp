#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;
const int MAXN = 100005;
int N;
ll S[MAXN],V[MAXN],T[MAXN],C[MAXN];
ll sum(int x){
	ll res=0;
	while(x){
		res+=C[x];
		x-=(x&(-x));
	}
	return res;
}
void add(int p, ll x){
	while(p<=N){
		C[p]+=x;
		p+=(p&(-p));
	}
}


int main()
{
	cin>>N;
	for(int i=1; i<=N; i++)cin>>V[i];
	for(int i=1; i<=N; i++)cin>>T[i];
	T[N+1]=0;
	for(int i=N; i>0; i--)T[i] = T[i+1] + T[i];
	for(int i=1; i<=N; i++){
		int l=i,r=N+1;
		while(l<r){
			int mid = (l+r)>>1;
			if(T[i]-T[mid+1] >= V[i])r=mid;
			else l=mid+1;
		}
		C[i]++; C[l]--;
		//cout<< V[i] << " " << T[i] << " " << T[l] <<endl;
		S[l] += (V[i] - (T[i]-T[l]));
	}
	int num = 0;
	for(int i=1; i<=N; i++){
		num += C[i];
		if(i-1)cout<<" ";
		cout<< (S[i] + (T[i]-T[i+1])*num);
	}
	cout<<endl;

	return 0;
}
