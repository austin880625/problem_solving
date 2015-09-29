#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N,Q;
	int cases=0;
	while(cin>>N>>Q){
		if(!(N||Q))break;
		int M[N];
		int P[Q];
		for(int i=0;i<N;i++)cin>>M[i];
		for(int i=0;i<Q;i++)cin>>P[i];
		sort(M,M+N);
		cout<<"CASE# "<<++cases<<":"<<endl;
		for(int q=0;q<Q;q++){
		int found=0;
		for(int i=0;i<N;i++){
			if(M[i]>=P[q]){
				if(M[i]>=P[q]){
					if(M[i]==P[q]){
						cout<<P[q]<<" found at "<<i+1<<endl;
						found=1;
					}
				}
				break;
			}
		}
		if(!found)cout<<P[q]<<" not found"<<endl;
		}
	}
	return 0;
}
