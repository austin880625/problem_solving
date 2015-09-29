#include<iostream>
#define INF 2147483646
using namespace std;

int s,d;
int profit;
int p[12];
int ans;

void dfs(int dep)
{
    if(dep==12)
    {
        profit=0;
        int con=0;
        for(int i=0;i<12;i++)
        {
            profit+=p[i]*(p[i]==1 ? s : d);
            con+=p[i]*(p[i]==1 ? s : d)-(i>=5 ? p[i-5]*(p[i-5]==1 ? s : d) : 0);
            if(i>=4&&con>0)return ;
        }
        ans=max(ans,profit);
        return ;
    }
    p[dep]=1;
    dfs(dep+1);
    p[dep]=-1;
    dfs(dep+1);
}

int main()
{
    while(cin>>s)
    {
        cin>>d;
        ans=0;
        dfs(0);
        if(ans==0)
            cout<<"Deficit"<<endl;
        else
            cout<<ans<<endl;
    }
}
