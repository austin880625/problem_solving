#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#define MAXN 1005
using namespace std;

struct Node
{
    int len;
    vector<char> s;
    bool operator <(const Node &rhs)const{
        if(len!=rhs.len)return len<rhs.len;
        int t=0;
        while(t<s.size()&&t<rhs.s.size()){
            if(s[t]!=rhs.s[t])return s[t]>rhs.s[t];
            t++;
        }
        return 0;
    }
    bool operator ==(const Node &rhs)const{return len<rhs.len;}
    Node(Node &A){len=A.len;s=A.s;}
    Node(){len=0;s.clear();}
};
Node max(Node &a,Node &b){return a<b ? b : a;}
Node dp[MAXN][MAXN];
string S;
char revS[MAXN];
//char ans[MAXN];
//int ispal[MAXN];
int N;

int main()
{
    while(getline(cin,S))
    {
        N=S.length();
        if(!N){puts("");continue;}
        for(int i=0;i<N;i++)revS[i]=S[N-1-i];

        for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j].len=0,dp[i][j].s.clear();
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(S[i-1]==revS[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                    dp[i][j].len++,dp[i][j].s.push_back(S[i-1]);
                    if(dp[i][j]==dp[i-1][j])dp[i][j]=max(dp[i-1][j],dp[i][j]);
                    if(dp[i][j]==dp[i][j-1])dp[i][j]=max(dp[i][j-1],dp[i][j]);
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int L=dp[N][N].len;
        //cout<<L<<endl;
        int l=(L+1)/2;
        int i=N,j=N;
        int pos=0;
        /*while(i&&j)
        {
            if(dp[i][j]==dp[i][j-1])j--;
            else if(dp[i][j]==dp[i-1][j])i--;
            else if(dp[i][j]==dp[i-1][j-1]+1&&S[i-1]==revS[j-1])
            {
                ans[pos++]=S[i-1];
                assert(S[i-1]==revS[j-1]);
                i--,j--;
            }
        }*/
        for(int i=0;i<l;i++)printf("%c",dp[N][N].s[i]);
        for(int i=l-1;i>=0;i--)
        {
            if(i==l-1&&L&1)continue;
            printf("%c",dp[N][N].s[i]);
        }

        puts("");
    }
}
