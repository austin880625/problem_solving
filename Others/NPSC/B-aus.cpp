#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 505
#define INF 500005
using namespace std;
int S[MAXN][MAXN];
int sum[MAXN][MAXN];
char C[MAXN][MAXN];
int M,N,ans;
int cnt[INF];
void Go(int l,int r)
{
    for(int i=0;i<=N;i++)
    {
        int dl=sum[i][l-1],dr=sum[i][r];
        cnt[dr-dl+250000]=-1;
    }
    //cout<<l<<" and "<<r<<endl;
    for(int i=0;i<=N;i++)
    {
        int dl=sum[i][l-1],dr=sum[i][r];
        //cout<<dr<<" "<<dl;
        if(cnt[dr-dl+250000]<0){
            cnt[dr-dl+250000]=i;
            //cout<<"YEE"<<endl;
            continue;
        }
        int ur=sum[cnt[dr-dl+250000]][r],ul=sum[cnt[dr-dl+250000]][l-1];
        ans=max(ans,(r-l+1)*(i-cnt[dr-dl+250000]));
        //if(ans==306)printf("%d %d\n",l,r);
        //cout<<" "<<cnt[dr-dl+250000]<<endl;
        //cout<<ans<<endl;
    }
    //puts("");
}
int main()
{
    memset(cnt,-1,sizeof(cnt));
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<=N;i++)for(int j=0;j<=M;j++)sum[i][j]=S[i][j]=0;
        ans=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%s",C[i]+1);
            for(int j=1;C[i][j]!='\0';j++)
            {
                if(C[i][j]=='A')S[i][j]=1;
                else if(C[i][j]=='C')S[i][j]=-1;
                else S[i][j]=0;
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+S[i][j];
                //sum[i][j]+=500000;
                //cout<<sum[i][j]<<endl;
            }
        }
        for(int l=1;l<=M;l++)
        {
            for(int r=l;r<=M;r++)
            {
                Go(l,r);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
