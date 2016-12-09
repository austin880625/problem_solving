#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 100005

using namespace std;

int N;
bool vis[MAXN];
vector<int> G[MAXN];
vector<int> Gr[MAXN];
vector<int> SCCG[MAXN];
vector<int> SCC[MAXN];
int sccno[MAXN];
int scc_cnt;
int stamp_owner[MAXN];
int iswinner[MAXN];
int indeg[MAXN];
int dfs_stamp;

queue<int> Q;
void dfs_for_stamp(int now)
{
    vis[now]=true;
    //cout<<"now is "<<now<<endl;
    for(int i=0;i<Gr[now].size();i++)
    {
        int v=Gr[now][i];
        if(!vis[v])
        {
            dfs_for_stamp(v);
        }
    }
    //cout<<now<<" is getting stamp "<<dfs_stamp+1<<endl;
    stamp_owner[++dfs_stamp]=now;
}

void dfs_for_scc(int now)
{
    vis[now]=true;
    sccno[now]=scc_cnt;
    //cout<<"now add on SCC "<<scc_cnt<<" "<<now<<endl;
    SCC[scc_cnt].push_back(now);
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(!vis[v])dfs_for_scc(v);
    }
}

vector<int> WINNER;
set<int> uncertain;
void build_list()
{
    for(int i=0;i<scc_cnt;i++)
    {
        sort(SCCG[i].begin(),SCCG[i].end());
        iswinner[i]=0;
        if(indeg[i]==0)
        {
            //cout<<i<<" "<<SCC[i][0]<<endl;
            Q.push(i);
        }
        else
        {
            uncertain.insert(i);
        }
    }
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        iswinner[u]=1;
        for(set<int>::iterator it=uncertain.begin();it!=uncertain.end();)
        {
            int l=0,r=SCCG[u].size();
            //cout<<"lr"<<l<<" "<<r<<" "<<(*it)<<endl;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(SCCG[u][mid]>=(*it))r=mid;
                else l=mid+1;
            }
            int e=l;
            l=0,r=SCCG[u].size();
            while(l<r)
            {
                int mid=(l+r)/2;
                //cout<<SCCG[u][mid]<<endl;
                if(SCCG[u][mid]>(*it))r=mid;
                else l=mid+1;
            }
            //cout<<"l "<<e<<" "<<l<<endl;
            e=l-e;
            //cout<<e<<endl;
            if(e<(long long)SCC[u].size()*(long long)SCC[(*it)].size())
            {
                Q.push(*it);
                uncertain.erase(it++);
            }
            else it++;
        }
    }
    for(int i=0;i<scc_cnt;i++)
    {
        if(iswinner[i]==1)
        {
            for(int j=0;j<SCC[i].size();j++)WINNER.push_back(SCC[i][j]);
        }
    }
    sort(WINNER.begin(),WINNER.end());
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        dfs_stamp=0;
        for(int i=1;i<=N;i++)
        {
            stamp_owner[i]=0;
            indeg[i]=0;
            int k,v;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                scanf("%d",&v);
                G[i].push_back(v);
                //if(v==2)cout<<"YEE "<<i<<endl;
                Gr[v].push_back(i);
            }
        }
        for(int i=1;i<=N;i++)if(!vis[i])dfs_for_stamp(i);
        for(int i=1;i<=N;i++)vis[i]=false;
        scc_cnt=0;
        for(int i=dfs_stamp;i>=1;i--)
        {
            if(!vis[stamp_owner[i]]){//cout<<i<<" "<<stamp_owner[i]<<endl;
                dfs_for_scc(stamp_owner[i]),scc_cnt++;
            }
        }
        /*
        for(int i=0;i<scc_cnt;i++)
        {
            cout<<"SCC "<<i<<": ";
            for(int j=0;j<SCC[i].size();j++)
            {
                cout<<SCC[i][j]<<" ";
            }
            puts("");
        }
        */
        for(int u=1;u<=N;u++)
        {
            for(int i=0;i<G[u].size();i++)
            {
                int v=G[u][i];
                if(sccno[u]!=sccno[v])SCCG[sccno[u]].push_back(sccno[v]),indeg[sccno[v]]++;
            }
        }
        build_list();
        printf("%d",WINNER.size());
        for(int i=0;i<WINNER.size();i++)
        {
            printf(" %d",WINNER[i]);
        }
        puts("");
    }
    return 0;
}
