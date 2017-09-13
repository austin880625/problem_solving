#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>

#define MAXN 2005
#define INF 2147483647
#define LL long long int

using namespace std;

int A[MAXN];
int B[MAXN];
int dp[MAXN][MAXN];
int N,K,P;

int main(){
    while(scanf("%d%d%d",&N,&K,&P)==2){
        for(int i=0;i<N;i++)scanf("%d",A+i);
        for(int i=0;i<K;i++)scanf("%d",B+i);
        sort(A,A+N);
        sort(B,B+N);
        for(int i=0;i<=K;i++)for(int j=0;j<=N;j++)dp[i][j]=INF;dp[0][0]=0;
        for(int i=1;i<=K;i++){
            dp[i][i]=dp[i-1][i-1]+abs(A[i]-B[i])+abs(B[i]-P);
        }
    }
    return 0;
}
