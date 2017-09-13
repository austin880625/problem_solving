#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int N;
long long int T[MAXN];

int main(){
    while(scanf("%d",&N)==1){
        for(int i=1;i<=N;i++){
            scanf("%I64d",T+i);
        }
        sort(T+1,T+1+N);
        long long int waited=0;
        int ans=0;
        for(int i=1;i<=N;i++){
            if(waited<=T[i])ans++,waited+=T[i];

        }
        printf("%d\n",ans);
    }
    return 0;
}
