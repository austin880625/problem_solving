#include<bits/stdc++.h>

using namespace std;



int main(){
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	string deck; cin>>deck;
	for(int i=0;i<deck.size()&&a>1;){
		int flag = 0, j;
		for(j=0;i+j<deck.size() && j<b;++j){
			if(deck[i+j] == '1') {flag = 1; break;};
		}
		if(flag==0 && a>1) {
			for(int k=0;k<b;++k) deck[i+k] = '1';
			--a;
			i += b;
		} else i += j+1;
	}
	//cout << deck <<"\n\n";
	vector<int> mark;
	for(int i=0;i<deck.size();){
		int flag = 0, j;
		for(j=0;i+j<deck.size() && j<b; ++j){
			if(deck[i+j] == '1') {flag = 1; break;}
		}
		if(flag == 0){
			mark.push_back(i+b);
			i += b;
		} else i += j+1;
	}
	printf("%d\n",mark.size());
	for(int i=0;i<mark.size();++i){
		if(i) printf(" ");
		printf("%d",mark[i]);
	}
	puts("");

	return 0;
}
