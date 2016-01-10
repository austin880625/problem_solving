#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#define INF 10000000
using namespace std;

int dp[1005][1005],maxpos[1005][1005];
vector<int> C[100001];
int n,m;
int A[1005],B[100005];

void print()
{
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++)
        {
            cout<<maxpos[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<100001;i++)C[i].clear();
        memset(dp,0,sizeof(dp));
        memset(maxpos,0,sizeof(maxpos));
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&B[i]);
            C[B[i]].push_back(i);
        }
        dp[0][0]=1;
        int ans=n;
        maxpos[0][0]=-1;
        for(int i=1;i<=n;i++)
        {
            if(!C[A[i-1]].size())break;
            for(int j=0;j<=n;j++)
            {
                //cout<<i<<" "<<j<<endl;
                //print();
                if(i==j){dp[i][j]=1;maxpos[i][j]=-1;break;}
                if(j&&dp[i-1][j-1]==0){dp[i][j]=0;maxpos[i][j]=INF;continue;}
                if(dp[i-1][j]&&C[A[i-1]][C[A[i-1]].size()-1]>maxpos[i-1][j])
                {
                    //cout<<C[A[i-1]][C[A[i-1]].size()-1]<<">"<<maxpos[i-1][j]<<endl;
                    dp[i][j]=1;
                    int l=0,r=C[A[i-1]].size()-1;
                    while(l<r)
                    {
                        int mid=(l+r)/2;
                        if(C[A[i-1]][mid]<=maxpos[i-1][j])l=mid+1;
                        else r=mid;
                    }
                    //for(int k=r;k>=0;k--)if(C[A[i-1]][k]<=maxpos[i-1][j]){l=k+1;break;}
                    maxpos[i][j]=max(C[A[i-1]][l],maxpos[i-1][j-1]);
                    if(i==n&&dp[i][j]){ans=j;break;}
                }
            }
        }
        //cout<<maxpos[11][10]<<endl;
        printf("%d\n",ans);
    }
    return 0;
}
