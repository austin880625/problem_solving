#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 500005

using namespace std;

int N;
int dp[53][53];
string s;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<53;i++)for(int j=0;j<53;j++)dp[i][j]=0;
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>s;
            int l=s.length();
            for(char c='a';c<='z';c++)
            {
                if(dp[c-'a'][s[0]-'a'])dp[c-'a'][s[l-1]-'a']=max(dp[c-'a'][s[l-1]-'a'],dp[c-'a'][s[0]-'a']+l);
            }
            dp[s[0]-'a'][s[l-1]-'a']=max(dp[s[0]-'a'][s[l-1]-'a'],l);
        }
        int ans=0;
        for(char c='a';c<='z';c++)
        {
            ans=max(dp[c-'a'][c-'a'],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
