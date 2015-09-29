#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		if(!n)break;
		queue<int> cards;
		for(int i=1;i<=n;i++)cards.push(i);
		
		cout<<"Discarded cards:";
		if(n!=1){cout<<" "<<cards.front();
		cards.pop();
		cards.push(cards.front());
		cards.pop();
		}
		while(cards.size()>=2){
			cout<<", "<<cards.front();
			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}
		/*if(n!=1)*/cout<<endl;
		cout<<"Remaining card: "<<cards.front()<<endl;
		
	}
	return 0;
}
