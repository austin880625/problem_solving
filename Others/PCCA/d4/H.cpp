#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 1005

using namespace std;

vector<int> L[MAXN]; //row
vector<int> R[MAXN]; //col
int Left[MAXN];
bool vis[2][MAXN];
bool mark[2][MAXN];
int Row,Col,N;

bool match(int i)
{
    vis[0][i]=true;
    for(int j:L[i])
    {
        if(!vis[1][j])
        {
            vis[1][j]=true;
            if(!Left[j]||match(Left[j]))
            {
                Left[j]=i;
                return true;
            }
        }
    }
    return false;
}

void make_mark(int i)
{
    vis[0][i]=true;
    mark[0][i]=true;
    for(int j:L[i])
    {
        if(!vis[1][j])
        {
            vis[1][j]=true;
            mark[1][j]=true;
            make_mark(Left[j]);
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&Row,&Col,&N)==3&&(Row||Col||N))
    {
        for(int i=0;i<=MAXN;i++)Left[i]=mark[0][i]=mark[1][i]=0,L[i].clear();
        for(int i=0,r,c;i<N;i++)
        {
            scanf("%d%d",&r,&c);
            L[r].push_back(c);
        }
        for(int i=1;i<=Row;i++)
        {
            for(int j=0;j<=max(Row,Col);j++)vis[0][j]=vis[1][j]=false;
            if(!match(i))
            {
                for(int j=0;j<=max(Row,Col);j++)vis[0][j]=vis[1][j]=false;
                make_mark(i);
            }
        }
        int ans=0;
        for(int i=1;i<=Col;i++)if(Left[i])ans++;
        printf("%d",ans);
        for(int i=1;i<=Row;i++)
        {
            if(!mark[0][i])printf(" r%d",i);
        }
        for(int j=1;j<=Col;j++)
        {
            if(mark[1][j])printf(" c%d",j);
        }
        puts("");
    }
    return 0;
}
