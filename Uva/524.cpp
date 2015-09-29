#include<iostream>

using namespace std;

const int MAX_N=18;

int isprime[35]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0};
int ans[MAX_N];
int vis[MAX_N];
int N;

void dfs(int cur){
	//cout<<cur<<endl;
	if(cur==0){
		ans[cur]=1;
		dfs(cur+1);
	}else if(cur==N){
		if(isprime[ans[0]+ans[cur-1]]){
			for(int i=0;i<N;i++){cout<<ans[i];if(i!=N-1)cout<<" ";}
			cout<<endl;
		}
		//vis[ans[cur]]=0;
	}else{
		for(int i=2;i<=N;i++){
			if((!vis[i])&&isprime[ans[cur-1]+i]){
				vis[i]=1;
				ans[cur]=i;
				//cout<<i<<endl;
				dfs(cur+1);
				vis[i]=0;
			}
		}
	}
}

int main(){
	int cases=1;
	while(cin>>N){
		for(int i=0;i<=N;i++)vis[i]=0;
		vis[1]=1;
		if(cases>1)cout<<endl;
		cout<<"Case "<<cases++<<":"<<endl;
		dfs(0);
		
	}
}

