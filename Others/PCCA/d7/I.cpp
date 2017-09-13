#include <stdio.h>
#include <iostream>
#define MAXN 105

using namespace std;

int c[MAXN];
int cnt[MAXN];
int N,C;

int main(){
    while(scanf("%d%d",&N,&C)==2){
        for(int i=0;i<=C;i++)cnt[i]=0;
        for(int i=0;i<N;i++){
            scanf("%d",c+i);
            cnt[c[i]]++;
        }
        int k=N/C,ans=0;
        for(int i=1;i<=C;i++){
            if(cnt[i]>k)ans+=cnt[i]-k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
