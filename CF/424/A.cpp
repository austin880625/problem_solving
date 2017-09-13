#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>

#define MAXN 1005
#define LL long long int

int N;
int A[MAXN];

using namespace std;

int main(){
    while(scanf("%d",&N)==1){
        int b=0;
        A[0]=0;
        for(int i=1;i<=N;i++){
            scanf("%d",A+i);
        }
        A[N+1]=0;
        int ans=1,l=0;
        while(A[b+1]>A[b])b++,l++;
        ans=ans&&(l>0);l=1;
        while(A[b+1]==A[b])b++,l++;
        ans=ans&&(l>0);l=1;
        while(A[b+1]<A[b]&&b<=N)b++,l++;
        ans=ans&&(l>0);l=0;
        printf(ans&&b==N+1 ? "YES\n" : "NO\n");

    }
    return 0;
}
