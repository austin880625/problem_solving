#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>

#define MAXN 100005
#define LL long long int

using namespace std;

struct Node{
    int v,minv,sz;
    Node(int _v){minv=v=_v;}
};

LL BIT[MAXN];
int A[MAXN];
int vis[MAXN];
vector<int> POS[MAXN];
int N;

void add(int pos,LL v){
    while(pos<=N){
        //cout<<pos<<endl;
        BIT[pos]+=v;
        pos+=(pos&(-pos));
    }
}
LL sum(int pos){
    LL res=0;
    while(pos){
        res+=BIT[pos];
        pos-=(pos&(-pos));
    }
    return res;
}

int main(){
    while(scanf("%d",&N)==1){
        for(int i=0;i<=N;i++)BIT[i]=0,POS[i].clear();
        int maxa=0;
        for(int i=1;i<=N;i++){
            scanf("%d",A+i);
            POS[A[i]].push_back(i);
            maxa=max(maxa,A[i]);
            //cout<<"YEE"<<endl;
            add(i,1);
        }
        //cout<<" YEE";
        int lastpos=0;
        LL t=0;
        for(int i=1;i<=maxa;i++){
            //cout<<"now at "<<i<<" "<<POS[i].size()<<endl;
            if(!POS[i].size())continue;
            int j=0;
            for(j=0;j<POS[i].size()&&POS[i][j]<=lastpos;j++);
            for(int x=0;x<POS[i].size();x++)vis[x]=0;
            for(j=j%POS[i].size();vis[j]!=1;j=(j+1)%POS[i].size()){
                vis[j]=1;
                int nowpos=POS[i][j];
                //cout<<lastpos<<" "<<nowpos<<endl;
                if(nowpos>lastpos){
                    t+=sum(nowpos-1)-sum(lastpos);
                    lastpos=nowpos-1;
                    add(nowpos,-1);
                }
                else{
                    t+=sum(N)-sum(lastpos)+sum(nowpos-1);
                    lastpos=nowpos-1;
                    add(nowpos,-1);
                }
                t++;
                //cout<<t<<endl;
            }
        }
        printf("%I64d\n",t);
    }
    return 0;
}
