#include <stdio.h>
#include <iostream>
#define LL long long int
#define MAXN 1005

using namespace std;

int N;
LL dp[MAXN][MAXN];
LL b[MAXN][MAXN];

int main(){
    while(scanf("%d",&N)==1){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                scanf("%lld",&b[i][j]);
                if(b[i][j]%10==2||b[i][j]%10==5)b[i][j]=b[i][j]%10;
                else b[i][j]=1;
            }
        }
    }
    return 0;
}
