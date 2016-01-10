#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 1005
#define INF 0x3f3f3f3f

using namespace std;
int T,N,K;
char S[MAXN];
int dp[MAXN][27];
int chunck[MAXN];
int used[MAXN][27];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&K);
        scanf("%s",S);
        N=strlen(S);
        int B=N/K;
        for(int i=0;i<B;i++)
        {
            chunck[i]=0;
        }
        for(int i=0;i<B;i++)
        {
            for(int j=0;j<27;j++)used[i][j]=0;
            for(int j=0;j<K;j++)
            {
                if(!used[i][S[i*K+j]-'a']){chunck[i]++;}
                used[i][S[i*K+j]-'a']++;
            }
        }
        //for(int i=0;i<B;i++)cout<<chunck[i]<<" ";
        //puts("");
        for(int i=0;i<K;i++)
        {
            if(used[0][S[i]-'a'])
                dp[0][S[i]-'a']=chunck[0];
            else
                dp[0][S[i]-'a']=INF;
        }
        for(int i=1;i<B;i++)
        {
            for(int j=0;j<26;j++)
            {
                dp[i][j]=INF;
                if(used[i][j])
                    for(int k=0;k<26;k++)
                    {
                        if(!used[i-1][k])continue;
                        if((k!=j&&used[i][k])||((K==1||chunck[i]==1)&&used[i][k]&&j==k))
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+chunck[i]-1);
                            //if(k==14)cout<<dp[i-1][k]<<endl;
                        else
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+chunck[i]);
                    }
                //if(used[i][j])printf("%d ",dp[i][j]);
            }
            //puts("");
        }
        int ans=INF;
        for(int i=0;i<26;i++){if(used[B-1][i])ans=min(ans,dp[B-1][i]);}
        printf("%d\n",ans);
    }
}
/*
2
5 helloworld
7 thefewestflops
*/
