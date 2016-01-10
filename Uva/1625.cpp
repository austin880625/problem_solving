#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAXN 5005
#define INF 2147483646
using namespace std;

int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];
int sp[2][26],ep[2][26];
string p,q;
int T;
void print()
{
    for(int i=0;i<=p.length();i++)
    {
        for(int j=0;j<=q.length();j++)
        {
            printf("%d\t",dp[i][j]);
        }
        puts("");
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>p>>q;
        int m=p.length(),n=q.length();
        for(int i=0;i<26;i++){sp[0][i]=sp[1][i]=INF;ep[0][i]=ep[1][i]=-1;}
        for(int i=0;i<=m+1;i++)
            for(int j=0;j<=n+1;j++)dp[i][j]=INF;
        for(int i=0;i<m;i++)
        {
            sp[0][p[i]-'A']=min(sp[0][p[i]-'A'],i);
            ep[0][p[i]-'A']=i;
        }
        for(int i=0;i<n;i++)
        {
            sp[1][q[i]-'A']=min(sp[1][q[i]-'A'],i);
            ep[1][q[i]-'A']=i;
        }
        int cnt;
        dp[0][0]=0;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cnt=0;
                for(int k=0;k<26;k++)
                {
                    if((i-1>=sp[0][k]||j-1>=sp[1][k])&&(i-1<ep[0][k]||j-1<ep[1][k])){cnt++;}
                }
                //cout<<cnt;puts("");
                int v=dp[i][j]+cnt;
                int k;
                if(i!=m){
                    k=p[i]-'A';
                    dp[i+1][j]=v;
                    if((i>=sp[0][k]||j-1>=sp[1][k])&&(i<ep[0][k]||j-1<ep[1][k]))dp[i+1][j]=min(dp[i+1][j],v+1);
                }
                if(j!=n){
                    k=q[j]-'A';
                    dp[i][j+1]=min(dp[i][j+1],v);
                    if((i-1>=sp[0][k]||j>=sp[1][k])&&(i-1<ep[0][k]||j<ep[1][k]))dp[i][j+1]=min(dp[i][j+1],v+1);
                }
                //cout<<dp[i][j]<<"\t";
            }
            //print();puts("");
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
