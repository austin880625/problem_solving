#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000

using namespace std;

char B[MAXN][MAXN];
int N,M;

int main(){
    while(scanf("%d%d",&N,&M)==2){
        int L=M,R=0,D=0,U=N;
        int s=0;
        for(int i=0;i<N;i++){
            scanf("%s",B[i]);
            for(int j=0;j<M;j++){
                if(B[i][j]=='B'){
                    s++;
                    L=min(L,j);
                    R=max(R,j);
                    U=min(U,i);
                    D=max(D,i);
                }
            }
        }
        int len=max(R-L+1,D-U+1);
        int ans=-1;
        //cout<<len<<" "<<R<<" "<<L<<endl;
        if(R-L+1>D-U+1){
            for(int i=0;i<=U;i++){
                if(i+len-1<N&&i+len-1>=D){ans=len*len-s;break;}
            }
        }
        else{
            for(int i=0;i<=L;i++){
                if(i+len-1<M&&i+len-1>=R){ans=len*len-s;break;}
            }
        }
        printf("%d\n",s?ans:1);
    }
    return 0;
}
