#include<iostream>
#include<stdio.h>
#include<vector>
#define MAXN 32768
using namespace std;

int N,Q;

int lowbit(int x){return x&(-x);}
struct BIT{
    vector<int> C;
    int sz;
    void clear(){C.clear();sz=0;C.push_back(0);}
    void push()
    {
        C.push_back(0);
        sz++;
    }
    void add(int x,int v)
    {
        while(x<=sz)
        {
            C[x]+=v;
            x+=lowbit(x);
        }
    }
    int sufsum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=C[x];
            x-=lowbit(x);
        }
        return res;
    }
};

vector<int> G[MAXN];
struct Node
{
    BIT T;
    int id,head,anc,dep,sz;
    void link(int v)
    {
        G[id].push_back(v);
        G[v].push_back(id);
    }
    void set1(int _anc,int _dep){anc=_anc;dep=_dep;sz=0;}
    void set2(int _head){head=_head;}
}NODES[MAXN];

void dfs1(int now,int fa,int depth)
{
    NODES[now].set1(fa,depth);
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(v==fa)continue;
        dfs1(v,now,depth+1);
        NODES[now].sz+=NODES[v].sz;
    }
    NODES[now].sz++;
}

void dfs2(int now,int fa,int head)
{
    NODES[now].set2(head);
    NODES[head].T.push();
    int maxpos=-1,v;
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(v==fa)continue;
        if(maxpos==-1||NODES[G[now][maxpos]].sz<NODES[v].sz)maxpos=i;
    }
    if(maxpos==-1)return ;
    v=G[now][maxpos];
    dfs2(v,now,head);
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(i==maxpos||v==fa)continue;
        dfs2(v,now,v);
    }
}

int query(int x)
{
    int res=0;
    while(1)
    {
        Node &O=NODES[NODES[x].head];
        res+=O.T.sufsum(NODES[x].dep-O.dep+1);
        x=O.anc;
        if(x==-1)break;
    }
    return res;
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        int from,to;
        for(int i=0;i<N;i++){NODES[i].id=i;NODES[i].T.clear();G[i].clear();}
        for(int i=0;i<N-1;i++)
        {
            scanf("%d%d",&from,&to);
            NODES[from].link(to);
        }
        dfs1(0,-1,0);
        dfs2(0,-1,0);
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            int k,x;
            scanf("%d%d",&x,&k);
            int head=NODES[x].head;
            //cout<<head<<endl;
            NODES[head].T.add(NODES[x].dep-NODES[head].dep+1,k);
            printf("%d\n",query(x));
        }
    }
    return 0;
}
