#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 200005

using namespace std;

int N,K;

int main(){
    while(scanf("%d%d",&N,&K)==2){
        int ans=(N-1);
        if(ans%K==0)ans=2*ans/K;
        else if(ans%K==1)ans=2*(ans/K)+1;
        else ans=2*(ans/K+1);
        printf("%d\n",ans);
        for(int i=2;i<=K+1;i++){
            printf("%d %d\n",1,i);
        }
        for(int i=K+2;i<=N;i++){
            printf("%d %d\n",i,i-K);
        }
    }
    return 0;
}
