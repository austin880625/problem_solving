#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 1005
using namespace std;
char S[MAXN];
vector<char> ans;
int dp[MAXN][MAXN];
int N;
int main()
{
    while(scanf("%s",S)!=EOF)
    {
        ans.clear();
        N=strlen(S);
        for(int i=0;i<=N;i++)dp[i][i]=1,dp[i+1][i]=0;
        for(int gap=1;gap<N;gap++)
        {
            for(int i=0;i<N-1;i++)
            {
                int j=i+gap;
                if(j>=N)continue;
                dp[i][j]=0;
                if(S[i]==S[j])dp[i][j]=max(dp[i][j],dp[i+1][j-1]+2);
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        printf("%d ",N-dp[0][N-1]);
        int l=0,r=N-1;
        while(l<r)
        {
            if(S[l]==S[r])ans.push_back(S[l]),l++,r--;
            else if(dp[l][r]==dp[l+1][r])ans.push_back(S[l]),l++;
            else if(dp[l][r]==dp[l][r-1])ans.push_back(S[r]),r--;
        }
        for(int i=0;i<ans.size();i++)printf("%c",ans[i]);
        if(l==r)printf("%c",S[l]);
        for(int i=ans.size()-1;i>=0;i--)
        {
            printf("%c",ans[i]);
        }
        puts("");
    }
    return 0;
}
