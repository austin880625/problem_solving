#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

int dp[15][25];
int num[205];
int N,Q,D,M;

int getmod(int x)
{
    return x%D ? x%D : D;
}

int DP(int i,int j)
{
    if(dp[i][j]||i==1)return dp[i][j];
    int res=0;
    for(int r=1;r<=j;r++)
    {
        res+=DP(1,r)*DP(i-1,j-r);
    }
    return dp[i][j]=res;
}

int main()
{
    int t=1;
    while(cin>>N>>Q)
    {
        if(!(N||Q))continue;
        for(int i=0;i<N;i++)
        {
            cin>>num[i];
        }
        cout<<"SET "<<t++<<":"<<endl;
        for(int q=1;q<=Q;q++)
        {
            cin>>D>>M;
            memset(dp,0,sizeof(dp));
            for(int i=0;i<N;i++)dp[1][getmod(num[i])]++;
            cout<<"QUERY "<<q<<": "<<DP(M,D)<<endl;
        }
    }
    return 0;
}
