#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int c[550][550],s[550][550];
int ans=0;
int n,m;
int p[600010];
int main(){
    memset(p,-1,sizeof(p));
    char cc[550];
    while(scanf("%d %d",&n,&m)==2){

        ans=0;

        for(int i=1;i<=n;i++){
            scanf("%s",cc);
            for(int j=1;j<=m;j++)
                c[i][j]=(int)(cc[j-1]-'B');
        }
        s[0][0]=0;
        for(int i=1;i<=n;i++) s[i][0]=0;
        for(int i=1;i<=m;i++) s[0][i]=0;

        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+c[i][j];
        }

        for(int ii=1;ii<=n;ii++)
        for(int j=1;j<=ii;j++){
            int l=j;int r=ii;
            for(int i=0;i<=m;i++)
            {
                int dl=s[l-1][i],dr=s[r][i];
                p[dr-dl+260000]=-1;
            }
            for(int i=0;i<=m;i++){
                int sum=s[r][i]-s[l-1][i];
                if(p[sum+260000]==-1) p[sum+260000]=i;
                else ans=max(ans,(r-l+1)*(i-p[sum+260000]));
                //cout<<l<<" "<<r<<" "<<i<<" "<<p[sum+260000]<<endl;
                //if(ans==306)printf("%d %d\n",l,r);
            }
        }
        printf("%d\n",ans);



    }


}
