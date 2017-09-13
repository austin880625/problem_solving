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
string tim[10005];
multiset<string> car;
int ontime(string bus,string pas)
{
	int h=bus[0]-pas[0];
	h=h*10+bus[1]-pas[1];
	int m=bus[2]-pas[2];
	m=m*10+bus[3]-pas[3];
	return h*60+m;
}
string add9(string s)
{
	int h=(s[0]-'0')*10+(s[1]-'0');
	int m=(s[2]-'0')*10+(s[3]-'0');
	m+=90;
	while(m>=60){
		h++;
		m-=60;
	}
	//cout<<h<<' '<<m<<endl;
	string r="";
	if(h<10) r=r+"0"+char(h+'0');
	else r=r+char(h/10+'0')+char(h%10+'0');
	if(m<10) r=r+"0"+char(m+'0');
	else r=r+char(m/10+'0')+char(m%10+'0');
	//cout<<"add"+r<<endl;
	return r;
}
main()
{
	int n;
	cin>>n;
	inc(i,n) cin>>tim[i];
	//sort(tim,tim+n);
	int l=1,r=10005;
	while(l+1<r){
		bool gf=1;
		car.clear();
		inc(i,mid){
			car.insert("0600");
		}
		for(int i=0;i<n;){
			int j;
			string bus=*car.begin();
			//cout<<bus;
			//cout<<ontime(bus,tim[i]);
			if(ontime(bus,tim[i])>=30){
				gf=0;
				break;
			}
			for(j=1;j<7&&i+j<n;j++){
				if(ontime(tim[i+j],tim[i])>=30){
					break;
				}
			}
			//cout<<"("<<i<<","<<j<<endl;
			//cout<<"bye "+bus<<endl;
			car.erase(car.begin());
			car.insert(add9(max(tim[i+j-1],bus)));
			//cout<<"00"<<add9(max(tim[i+j-1],bus))<<endl;
			i+=j;
		}
		//printf("%d %d %d\n",l,r,gf);
		if(gf){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	cout<<max(0,l+1 -2)<<endl;
}
