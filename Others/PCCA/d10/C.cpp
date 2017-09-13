#include <stdio.h>
#include <iostream>
#include <set>
#include <string.h>
using namespace std;

int N,M;
set<string> P;
int common,E;

int main(){
    while(cin>>N>>M){
        common=0;E=0;
        string s;
        for(int i=0;i<N;i++){
            cin>>s;
            P.insert(s);
        }
        for(int i=0;i<M;i++){
            cin>>s;
            set<string>::iterator it=P.find(s);
            if(it!=P.end()){
                common++;
            }
            else E++;
        }
        int P=N-common;
        int ans=1;
        if(common&1){
            if(P<E)ans=0;
            else ans=1;
        }
        else{
            if(P<=E)ans=0;
            else ans=1;
        }
        cout<<(ans ? "YES" : "NO")<<endl;
    }
    return 0;
}
