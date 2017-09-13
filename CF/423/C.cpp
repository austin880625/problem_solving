#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAXN 100005

using namespace std;

struct Node {
    int sum,tag;
    Node *ch[2];
    Node(int x){sum=x;}
};
Node *Tree;
int L,R,X;
void build(Node *&o,int l,int r){
    if(!o)o=new Node(0);
    if(l==r){o->sum=0;return ;}
    int mid=(l+r)>>1;
    build(o->ch[0],l,mid);
    build(o->ch[1],mid+1,r);
}
int modify(Node *&o,int l,int r){
    if(L<=l&&r<=R){o->tag=X;return ;}
}

int N;
int K[MAXN];
string T[MAXN];
vector<int> X[MAXN];
int S[MAXN*10];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>N){
        for(int i=0;i<N;i++){
            cin>>T[i]>>K[i];
            X[i].clear();
            for(int j=0,x;j<K[i];j++){
                cin>>x;
                X[i].push_back(x);
            }
        }
    }
    return 0;
}
