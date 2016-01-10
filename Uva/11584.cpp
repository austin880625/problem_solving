#include<iostream>
#include<stdio.h>
#include<string.h>
#define INF 2147483646
using namespace std;
string s;
int T;
int dp[1005];
int ispalindrome[1005][1005];
void pre_process()
{
    int offset;
    for(int i=0;i<s.length();i++)
    {
        offset=0;
        while(i-offset>=0&&i+offset<s.length()&&s[i-offset]==s[i+offset]){ispalindrome[i-offset][i+offset]=1;offset++;}
    }
    for(int i=0;i<s.length();i++)
    {
        offset=1;
        while(i-offset+1>=0&&i+offset<s.length()&&s[i-offset+1]==s[i+offset]){ispalindrome[i-offset+1][i+offset]=1;offset++;}
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        for(int i=0;i<s.length();i++)for(int j=0;j<s.length();j++)ispalindrome[i][j]=0;
        pre_process();
        for(int i=0;i<s.length();i++)
        {
            dp[i]=INF;
            for(int j=0;j<i;j++)
            {
                if(ispalindrome[j+1][i])dp[i]=min(dp[i],dp[j]+1);
            }
            if(ispalindrome[0][i])dp[i]=1;
        }
        //for(int i=0;i<s.length();i++)printf("%d ",dp[i]);
        //puts("");
        printf("%d\n",dp[s.length()-1]);
    }
    return 0;
}
