#include <stdio.h>
#include <iostream>

using namespace std;

int ans[500][500];

int dfs(int a,int b)
{
    //cout<<a<<" "<<b<<endl;
    if(a==0&&b==0)return ans[a][b]=0;
    if(a==0||b==0)return ans[a][b]=ans[b][a]=1;
    if(ans[a][b]!=-1)return ans[a][b];
    int res=0;
    for(int i=1;i<=a;i++)res|=(!dfs(a-i,b));
    for(int i=1;i<=b;i++)res|=(!dfs(a,b-i));
    for(int i=1;i<=min(a,b);i++)res|=(!dfs(a-i,b-i));
    return ans[a][b]=ans[b][a]=res;
}

int main()
{
    for(int i=0;i<500;i++)for(int j=0;j<500;j++)ans[i][j]=-1;
    dfs(300,300);
    int last=0;
    for(int i=0;i<=300;i++)
    {
        for(int j=i;j<=300;j++)if(ans[i][j]==0)
        {
            printf("%d ",j);last=j;
        }
    }
    return 0;
}
