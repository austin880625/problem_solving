#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int dp[50000];
int T;

int abs(int x)
{
    return x>0 ? x : -x;
}

int main()
{
    cin>>T;
    while(T--)
    {
        int m,ans,S=0;
        cin>>m;
        memset(dp,0,sizeof(dp));
        int w[105];
        for(int i=0;i<m;i++)
        {
            cin>>w[i];
        }
        dp[0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=S;j>=0;j--)
            {
                if(dp[j]){dp[j+w[i]]=1;}
            }
            S+=w[i];
        }
        for(int i=0;i<1000;i++)
        {
            if(dp[S/2-i]){ans=S-2*(S/2-i);break;}
        }
        cout<<ans<<endl;
    }
    return 0;
}
