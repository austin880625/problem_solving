#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define MAXN 105
#define INF 2147483646
using namespace std;

int T;
int dp[MAXN][MAXN];
//char S[MAXN];
string S;
char match(char x)
{
    if(x=='(')return ')';
    if(x=='[')return ']';
    else return '#';
}

void print(int l,int r)
{
    if(l==r){
        cout<<((S[l]=='['||S[l]==']') ? "[]" : "()");
        return ;
    }
    for(int mid=l;mid<r;mid++)
    {
        if(dp[l][r]==dp[l][mid]+dp[mid+1][r]){print(l,mid);print(mid+1,r);return ;}
    }
    if(dp[l][r]==dp[l+1][r-1]){
        printf("%c",S[l]);
        if(l+1!=r)print(l+1,r-1);
        printf("%c",match(S[l]));
        return ;
    }
}

int main()
{
    scanf("%d",&T);
    getline(cin,S);
    while(T--)
    {
        getline(cin,S);
        getline(cin,S);
        //int n=strlen(S);
        int n=S.length();
        if(n){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=INF;
                if(j==i)dp[i][j]=1;
                if(j<i)dp[i][j]=0;
            }
        }
        for(int len=1;len<n;len++)
        {
            for(int i=0;i<n;i++)
            {
                if(i+len>=n)continue;
                int j=i+len;
                //cout<<S[i]<<match('[')<<endl;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if(S[j]==match(S[i]))dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
        }
        print(0,n-1);
        }
        puts("");
        if(T)puts("");
        //printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
