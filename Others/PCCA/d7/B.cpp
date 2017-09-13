#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXN 4005
#define ll long long int
#define MAXA 2000000000000

using namespace std;

int N;
ll ans=0;

struct rect{
    ll l,w;
    bool operator <(const rect &x)const{
        return l<x.l ? true : w<x.w;
    }
};

rect r[MAXN];

int main(){

    while(scanf("%d",&N)==1){
        ans=0;
        ll ml=0,mw=0;
        for(int i=1;i<=N;i++){
            scanf("%I64d%I64d",&r[i].l,&r[i].w);
            if(r[i].l>r[i].w)swap(r[i].l,r[i].w);
        }
        sort(r+1,r+1+N);
        for(int i=1;i<=N;i++){
            ll t=1,s=0;
            if(ans<r[i].l*r[i].w){
                ans=r[i].l*r[i].w;
                ml=r[i].l,mw=r[i].w;
            }
            for(int j=i+1;j<=N;j++){
                if(r[j].w>=r[i].w){
                    if(ans<r[i].l*r[i].w*(j-i-s+1)){
                        ans=r[i].l*r[i].w*(j-i-s+1);
                        ml=r[i].l,mw=r[i].w;
                    }
                }else{
                    s++;
                    if(ans<r[i].l*r[j].w*(t+1)){
                        ans=r[i].l*r[j].w*(t+1);
                        t++;
                        ml=r[i].l,mw=r[j].w;
                    }
                }
            }
        }
        printf("%I64d\n%I64d %I64d\n",ans,ml,mw);
    }
}
