#include<iostream>
#include<stdio.h>

using namespace std;
const long long int INF=(1LL<<60);
int T;
int A,B,C;
long long int g[22][22][22];
long long int sum[22][22][22];

long long int getMax(int b,int t,int l,int r)
{
    long long int res=0LL,s=0LL;
    for(int i=1;i<=C;i++)
    {
        s+=(sum[t][r][i]-sum[t][r][i-1])
            -(sum[t][l][i]-sum[t][l][i-1])
            -(sum[b][r][i]-sum[b][r][i-1])
            +(sum[b][l][i]-sum[b][l][i-1]);
        if(s<0)s=0LL;
        res=max(res,s);
    }
    return res;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&A,&B,&C);
        for(int i=0;i<=A;i++)
        {
            for(int j=0;j<=B;j++)
            {
                for(int k=0;k<=C;k++)
                {
                    sum[i][j][k]=0;
                    if(i&&j&&k)
                    {
                        scanf("%lld",&g[i][j][k]);
                    }
                }
            }
        }
        for(int i=0;i<=A;i++)
        {
            for(int j=0;j<=B;j++)
            {
                for(int k=0;k<=C;k++)
                {
                    if(i&&j&&k)
                    {
                        sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]
                                    -sum[i][j-1][k-1]-sum[i-1][j][k-1]-sum[i-1][j-1][k]
                                    +sum[i-1][j-1][k-1]+g[i][j][k];
                                    //cout<<g[i][j][k]<<" ";
                    }
                }
            }
        }
        long long int ans=-INF;
        for(int bot=0;bot<A;bot++)
        {
            for(int top=bot+1;top<=A;top++)
            {
                for(int left=0;left<B;left++)
                {
                    for(int right=left+1;right<=B;right++)
                    {
                        for(int back=0;back<C;back++)
                        {
                            for(int fro=back+1;fro<=C;fro++)
                            {
                                long long int ss=sum[top][right][fro]
                                        -sum[bot][right][fro]-sum[top][left][fro]-sum[top][right][back]
                                        +sum[bot][left][fro]+sum[bot][right][back]+sum[top][left][back]
                                        -sum[bot][left][back];
                                        //cout<<sum[top][right][fro]<<endl;
                                ans=max(ans,ss);
                            }
                        }
                    }
                }
            }
        }

        printf("%lld\n",ans);
        if(T)puts("");

    }
    return 0;
}
