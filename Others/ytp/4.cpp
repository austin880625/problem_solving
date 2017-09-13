#include<bits/stdc++.h>
using namespace std;
#define inc(i,x) for(int i=0;i<x;i++)
#define onc(i,x) for(int i=1;i<=x;i++)
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

#define mid ((l+r)/2)
#define md ((lo+hi)/2)

#define lson (me*2)
#define rson (me*2+1)
int mp[25];
	int n;
int eval(int msk,int wid)
{
	int ans=n;
	for(int i=0;i+wid<=n;i++){
		int tmp=0;
		for(int j=0;j<wid;j++){
			if((mp[i+j]&msk)!=msk){
				tmp++;
			}
		}
		ans=min(ans,tmp);
	}
	return ans;
}
int sp(int msk,int wid)
{
	int ans=n;
	for(int i=0;i+wid<=n;i++){
		int tmp=0;
		for(int j=0;j<wid;j++){
			if((msk>>(i+j))&1){

			}
			else{
				tmp++;
			}
		}
		ans=min(ans,tmp);
	}
	return ans;
}
main()
{
	cin>>n;
	inc(i,n){
		string s;
		cin>>s;
		mp[i]=0;
		inc(j,n){
			mp[i]=mp[i]*2+((s[j]=='+')?1:0);
		}
	}
	int ans=0,anst=0;
	inc(i,1<<20){
		int k=__builtin_popcount(i);
		int tmp=0;
		inc(j,n){
			if((mp[j]&i)==i){
				tmp++;
			}
		}
		tmp=min(k,tmp);
		int tt=eval(i,tmp)+sp(i,tmp);
		if(tmp>ans||(tmp==ans&&tt<anst)){
			ans=tmp;
			anst=tt;
		}
	}
	cout<<ans<<","<<anst<<endl;
}
