#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>

#define MAXN 1005
#define LL long long int

using namespace std;

char layout1[300];
string A,B,S,ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>A>>B){
        ans.clear();
        for(int i=0;i<A.length();i++){layout1[A[i]-'a']=B[i]-'a';}
        for(int i='0';i<='9';i++)layout1[i]=i;
        cin>>S;
        for(int i=0;i<S.length();i++){
            int c,b;
            if('A'<=S[i]&&S[i]<='Z')c=S[i]-'A',b='A';
            else if('a'<=S[i]&&S[i]<='z')c=S[i]-'a',b='a';
            else if('0'<=S[i]&&S[i]<='9')c=S[i],b=0;
            else c=S[i],b=0;
            char newc=layout1[c];
            ans.push_back(newc+b);
        }
        cout<<ans<<endl;
    }
    return 0;
}
