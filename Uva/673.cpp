#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
using namespace std;

char con(char c){
	return c=='[' ? ']' : ')';
}

int main(){
	int T;
	cin>>T;
	getchar();
	while(T--){
		int ans=1;
		string c;
		getline(cin,c);
		if(c.compare("\n")==0){cout<<"Yes"<<endl;continue;}
		stack<char> s;
		for(int i=0;i<c.length();i++){
			if(c[i]=='['||c[i]=='(')s.push(c[i]);
			else{
				if(s.empty())ans=0;
				else if(con(s.top())==c[i])s.pop();
				else ans=0;
			}
		}
		cout<<(ans&&s.empty() ? "Yes" : "No")<<endl;
	}
}
