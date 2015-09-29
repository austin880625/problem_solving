#include <stdio.h>
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int dp[100][1005];
int N,t,w[1005];
int ans;
vector<int> ansset;

int main()
{
    while(cin>>N>>t)
    {
        ansset.clear();
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        ans=0;
        for(int i=0;i<t;i++)
            cin>>w[t-1-i];
        
        dp[0][0]=1;
        if(w[0]<=N){dp[0][w[0]]=1;ans=w[0];}
        
        for(int i=1;i<t;i++)
        {
            for(int j=0;j<=N;j++)
            {
                if(dp[i-1][j])
                {
                    dp[i][j]=1;
                    if(j+w[i]<=N)dp[i][j+w[i]]=1;
                }
                if(dp[i][j]&&ans<j)ans=j;
            }
        }
        
        for(int i=t-1,j=ans;i>=1;i--)
        {
            if(j-w[i]>=0&&dp[i-1][j-w[i]])
            {
                ansset.push_back(w[i]);
                //cout<<"now i is "<<i<<", and j is "<<j<<endl;
                j=j-w[i];
            }
            if(j==w[0]&&i==1)ansset.push_back(w[0]);
        }
        for(int i=0;i<ansset.size();i++)
            cout<<ansset[i]<<" ";
        if(t==1)cout<<w[0]<<" ";
        cout<<"sum:";
        cout<<ans<<endl;
    }
}