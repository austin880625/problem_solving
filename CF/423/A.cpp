#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 200005

using namespace std;

int N,A,AA,AB;
int T[MAXN];

int main(){
    while(scanf("%d%d%d",&N,&A,&AA)==3){
        int ans=0;
        AB=0;
        for(int i=0;i<N;i++){
            scanf("%d",T+i);
            if(T[i]==1){
                if(A)A--;
                else if(AA)AA--,AB++;
                else if(AB)AB--;
                else ans++;
            }
            else{
                if(AA)AA--;
                else ans+=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
