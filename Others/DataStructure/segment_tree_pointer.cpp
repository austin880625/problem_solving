#include<iostream>

using namespace std;

const int MAX_N=1000;
int ar[MAX_N];
int ST[MAX_N*4];
int n,res;

void dfs(int left,int right,int pos){
	int mid=(left+right)/2;
	if(left==right)ST[pos]=ar[left];
	else{
		dfs(left,mid,pos*2);
		dfs(mid+1,right,pos*2+1);
		ST[pos]=ST[pos*2]+ST[pos*2+1];
	}
}

void query(int left,int right,int L,int R,int pos){
	//int res=0;
	int M=(L+R)/2;
	//cout<<pos<<endl;
	if(left<=L&&right>=R)res+=ST[pos];
	else{
	if(left<M)query(left,right,L,M,pos*2);
	if(right>M)query(left,right,M+1,R,pos*2+1);
	}
	//cout<<res<<endl;
}

int main(){
	while(cin>>n){
		for(int i=0;i<=4*n;i++)ST[i]=0;
		for(int i=0;i<n;i++)cin>>ar[i];
		dfs(0,n-1,1);
		//for(int i=1;i<4*n;i++)cout<<ST[i]<<" ";
		//cout<<endl;
		int ql,qr;
		cin>>ql>>qr;
		res=0;
		query(ql-1,qr-1,0,n-1,1);
		cout<<res<<endl;
	}
}

