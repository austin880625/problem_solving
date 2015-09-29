#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

struct treasure
{
    int d,v;
}treasures[35];

int dp[35][1005];
int d[35];
int t,w,n;
vector<int> Ans;

int main()
{
    int f=1;
    while(scanf("%d %d",&t,&w)!=EOF)
    {
        Ans.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&treasures[i].d,&treasures[i].v);
            d[i]=treasures[i].d;
            treasures[i].d=treasures[i].d*3*w;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=t;j++)
            {
                if(j>=treasures[i].d)
                {
                    dp[i][j]=max(dp[i-1][j-treasures[i].d]+treasures[i].v, dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        for(int i=n,j=t;i>=1;i--)
        {
            if(j<treasures[i].d)continue;
            if(dp[i-1][j-treasures[i].d]==dp[i][j]-treasures[i].v)
            {
                Ans.push_back(i);
                j-=treasures[i].d;
            }
        }
        if(!f){ cout<<endl;}
        f=0;
        printf("%d\n",dp[n][t]);
        printf("%d\n",Ans.size());
        for(int i=Ans.size()-1;i>=0;i--)
        {
            cout<<d[Ans[i]]<<" "<<treasures[Ans[i]].v<<endl;
        }
    }
    return 0;
}

