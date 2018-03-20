#include <stdio.h>
#include <iostream>
#include <string.h>
#include <assert.h>
#define MAXN 205
#define INF 100000000

int T,N,M;
int w[MAXN][MAXN];
int det[MAXN][MAXN];

using namespace std;

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int j=0;j<=N;j++)for(int k=0;k<=N;k++){w[j][k]=INF;det[j][k]=0;if(k==j)w[j][k]=0;}
        for(int i=0,u,v,w0;i<M;i++){
            scanf("%d%d%d",&u,&v,&w0);
            w[u][v]=min(w[u][v],w0);
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++){
                    if(w[j][i]>=INF||w[i][k]>=INF)continue;
                    w[j][k]=min(w[j][k],w[j][i]+w[i][k]);
                }
            }
        }
        int ans[2]={0,0};
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++){
                    if(det[j][k])continue;
                    if(w[j][k]>=INF){ans[0]++,det[j][k]=1;continue;}
                    if(w[j][i]>=INF||w[i][k]>=INF)continue;
                    if(w[i][i]<0){det[j][k]=1;ans[1]++;}
                }
            }
        }
        printf("%d %d %d\n",ans[0],ans[1],N*N-ans[0]-ans[1]);
    }
    return 0;
}
