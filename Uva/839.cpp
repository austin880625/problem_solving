#include<iostream>

using namespace std;

int isbalance(int& W){
	int wl,dl,wr,dr;
	int bl=1,br=1;
	cin>>wl>>dl>>wr>>dr;
	if(wl==0)bl=isbalance(wl);
	if(wr==0)br=isbalance(wr);
	W=wl+wr;
	return bl&&br&&wl*dl==wr*dr;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int W=0;
		cout<<(isbalance(W) ? "YES" : "NO")<<endl;
		if(T)cout<<endl;
	}
}
