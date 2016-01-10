#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <assert.h>
#define MAXN 65536
#define LL long long int

using namespace std;

struct edge
{
    int u,v;
};

vector<int> G[MAXN];
vector<int> BCC[MAXN];
int BCCNO[MAXN];
int BCC_CNT;
stack<edge> S;
bool iscut[MAXN];
int pre[MAXN],low[MAXN];
int dfs_clock;
int N;

int dfs(int now,int fa)
{
    pre[now]=low[now]=++dfs_clock;
    int ch=0;
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(!pre[v])
        {
            ch++;
            S.push((edge){now,v});
            low[now]=min(low[now],dfs(v,now));
            if(low[v]>=pre[now])
            {
                iscut[now]=true;
                BCC_CNT++;
                while(1)
                {
                    edge e=S.top();S.pop();
                    if(BCCNO[e.u]!=BCC_CNT)BCC[BCC_CNT].push_back(e.u),BCCNO[e.u]=BCC_CNT;
                    if(BCCNO[e.v]!=BCC_CNT)BCC[BCC_CNT].push_back(e.v),BCCNO[e.v]=BCC_CNT;
                    if(now==e.u&&v==e.v)break;
                }
            }
        }
        else if(pre[v]<pre[now]&&v!=fa)
        {
            S.push((edge){now,v});
            low[now]=min(low[now],pre[v]);
        }
    }
    if(ch==1&&fa==-1)iscut[now]=false;
    return low[now];
}

int main()
{
    int kase=0;
    while(scanf("%d",&N)==1&&N)
    {
        for(int i=0;i<MAXN;i++)G[i].clear(),BCC[i].clear(),iscut[i]=low[i]=pre[i]=BCCNO[i]=0;
        for(int i=0;i<N;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            assert(u!=v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs_clock=BCC_CNT=0;
        assert(G[1].size());
        for(int i=1;i<MAXN;i++)if(G[i].size()&&!pre[i])dfs(i,-1);
        /*
        for(int i=1;i<=6;i++)printf("%d ",iscut[i]);
        puts("");
        for(int i=1;i<=BCC_CNT;i++)
        {
            for(int j=0;j<BCC[i].size();j++)
            {
                printf("%d ",BCC[i][j]);
            }
            puts("");
        }
        */
        LL ans1=0,ans2=1LL;
        for(int i=1;i<=BCC_CNT;i++)
        {
            int cutcnt=0;
            for(int j=0;j<BCC[i].size();j++)
            {
                if(iscut[BCC[i][j]])cutcnt++;
            }
            if(cutcnt==1)ans1++,ans2*=(LL)(BCC[i].size()-1LL);
        }
        if(BCC_CNT==1)
            ans2=(BCC[1].size()*(BCC[1].size()-1LL))/2LL,ans1=2LL;
        printf("Case %d: %lld %lld\n",++kase,ans1,ans2);
    }
    return 0;
}

/*
8
1 2
1 3
3 6
3 7
2 4
2 5
2 8
4 8
17
1 2
1 3
2 3
3 4
2 4
3 5
4 6
6 5
6 7
7 8
8 9
7 9
1 10
1 13
10 11
11 12
12 13

29
8 4
17 7
6 1
12 6
3 17
5 9
20 8
20 4
7 15
4 18
7 17
14 1
14 3
5 3
5 18
13 18
5 15
1 13
18 3
2 4
20 4
20 16
5 20
2 3
10 4
13 16
2 7
6 17
1 15
*/
