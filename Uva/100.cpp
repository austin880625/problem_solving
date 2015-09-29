#include<cstdio>

using namespace std;
const int MAX_N=1000005;
unsigned long long int list[MAX_N];
int main(){
	int i,j;
	for(i=1;i<=120000;i++){
		unsigned long long int _ans=0;
		unsigned long long int t=i;
		while(1){
			_ans++;
			if(t==1)break;
			t=(t%2 ? 3*t+1 : t/2);
		}
		list[i]=_ans;
	}

	while(scanf("%d %d",&i,&j)==2){
		unsigned long long int ans=0;int s=i,c=0;
		if(i>j){i=j;j=s;s=i;c=1;}
		for(i=i;i<=j;i++){
			unsigned long long int _ans=0;
			
			if(list[i])_ans=list[i];
			else{
				_ans=0;
				unsigned long long int t=i;
				while(1){
					_ans++;
					if(t==1)break;
					t=(t%2 ? 3*t+1 : t/2);
				}
				list[i]=_ans;
			}
			if(_ans>ans)ans=_ans;
		}
		if(c) printf("%d %d %llu\n",j,s,ans);
		else printf("%d %d %llu\n",s,j,ans);
	}
	return 0;
}

