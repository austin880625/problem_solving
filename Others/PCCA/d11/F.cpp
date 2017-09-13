#include <stdio.h>
#include <iostream>

using namespace std;

int N;
long long int X,Y;
long long int dp[10000005];
int vis[10000005];

long long int DP(int x){
    //cout<<x<<endl;
    if(x==0)return 0;
    if(dp[x])return dp[x];
    vis[x]=1;
    long long int res=DP(x-1)+X;
    if(x%2==0&&!vis[x/2])res=min(res,DP(x/2)+Y);
    else if(x%2)res=min(res,min(DP(x/2)+Y+X,DP(x/2+1)+Y+X));
    vis[x]=0;
    return dp[x]=res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>N>>X>>Y){
        for(int i=0;i<=N;i++)dp[i]=vis[i]=0;
        dp[0]=0,dp[1]=X;
        for(int i=2;i<=N;i++){
            dp[i]=dp[i-1]+X;
            if(i%2)dp[i]=min(dp[i],min(dp[i/2]+Y+X,dp[i/2+1]+Y+X));
            else dp[i]=min(dp[i],dp[i/2]+Y);
        }
        cout<<dp[N]<<endl;
    }
    return 0;
}
