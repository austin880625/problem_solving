#include<iostream>

using namespace std;
const int MAX_N=10005;
int ar[MAX_N];
int dp[MAX_N];

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int Max=0;
        cin>>ar[0];
        dp[0]=ar[0];
        for(int i=1;i<n;i++)
        {
            cin>>ar[i];
            dp[i]=max(dp[i-1]+ar[i],ar[i]);
            if(Max<dp[i])Max=dp[i];
        }
        cout<<(Max>0 ? "The maximum winning streak is " : "Losing streak");
        if(Max>0)cout<<Max;
        cout<<"."<<endl;
    }
    return 0;
}
