#include<iostream>
#include<stack>
using namespace std;

int main(){
	int N;
	while(cin>>N){
		if(N==0)break;
		else{
		int flag=1;
		while(flag){
		stack<int> t;
		int a[1010];
		a[0]=0;
		for(int i=0;i<N;i++){
			a[i]=0;
			cin>>a[i];
			if(a[0]==0){cout<<endl;flag=0;break;}
		}
		if(flag==0)break;
		int c=1;
		//cout<<c;
		t.push(c);
		for(int i=0;i<N;i++){
			while(t.top()!=a[i]&&c<N){
				t.push(++c);
				//c++;
				//cout<<c<<endl;
			}
			if(t.top()==a[i])t.pop();
			if(t.empty()&&c!=N)t.push(++c);
		}
		cout<<(t.empty() ? "Yes" : "No")<<endl;
		}
	}
	}
}
