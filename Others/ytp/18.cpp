#include<bits/stdc++.h>
#define F first
#define S second
#define N 50000
using namespace std;
typedef pair<int,int> P;
struct st_{
	int l, r, sc;
}arr[N+5];
int n,sum;
bool used[5005];
int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d%d%d",&arr[i].l,&arr[i].r,&arr[i].sc);
	sort(arr, arr+n, [](st_ &a, st_ &b){
			return a.l < b.l;
		});
	for(int i=0;i<n;++i){

	}
	return 0;
}
