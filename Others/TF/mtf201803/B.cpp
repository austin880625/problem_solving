#include <stdio.h>
#include <iostream>
#include <assert.h>

typedef long long int ll;
ll c[4];
ll v,V;

using namespace std;

int main()
{
	int T;
	
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++)cin>>c[i];
		cin>>V;
		ll v=V;
		while(c[1]*5+c[2]*10+c[3]*50>=v){
			ll n3 = min(v/50+1, c[3]);
			ll n2=0,n1=0;
			v-=n3*50;
			if(v>=0){
				n2 = min(v/10+1, c[2]);
				v-=n2*10;
			}
			if(v>=0){
				n1 = min(v/5+1, c[1]);
				v-=n1*5;
			}
			if(v>=0)break;
			v=-v;
			ll num = 2147483647;
			if(n1){num = min(num, c[1]/n1);} 
			if(n2){num = min(num, c[2]/n2);}
			if(n3){num = min(num, c[3]/n3);}
			c[1]-=num*n1;
			c[2]-=num*n2;
			c[3]-=num*n3;
			c[0]+=(v%5)*num;
			c[3]+=(v/50)*num; v%=50;
			c[2]+=(v/10)*num; v%=10;
			c[1]+=(v/5)*num; v%=5;
			//cout<<c[0]<<endl;

			v=V;
		}
		cout<<c[0]<<endl;
	}
	return 0;
}
