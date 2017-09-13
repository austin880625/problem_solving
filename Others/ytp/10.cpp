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
int dis(int a,int b)
{
	int ax=a/10;
	int ay=a%10;
	int bx=b/10;
	int by=b%10;
	return floor(sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))+0.5);
}
main()
{
	string str;
	cin>>str;
	vector<int> num;
	int l=0;
	for(int i=0;i<sz(str);i++){
		if(str[i]==','){
			num.pb(atoi(str.substr(l,i-l).c_str()));
			l=i+1;
		}
	}
	int ans=0;
	num.pb(atoi(str.substr(l,sz(str)-l).c_str()));
	for(int i=1;i<sz(num);i++){
			//cout<<num[i]<<endl;
		if(dis(num[0],num[i])<=5){
			ans+=5-dis(num[0],num[i]);
		}
	}
	printf("%02d",ans);
}
