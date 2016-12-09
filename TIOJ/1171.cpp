#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define MAXN 100005
#define LL long long int
using namespace std;

bool isset[MAXN];
bool vis[MAXN];
int N,Q;
int sz[MAXN];
int maxch[MAXN],dep[MAXN];
int head[MAXN],chain_of[MAXN];
int Q1;
int chain_sz;
LL dis[MAXN];
LL L[MAXN];
int p[MAXN];

struct edge
{
    int v;LL l;
    edge(LL _l,int _v){v=_v;l=_l;}
};
vector<edge> G[MAXN];
vector<LL> LS[MAXN];
inline int ran(){static int x=time(NULL);return x=x*0xdefaced+1;}
//void* BUF=malloc(24*2*MAXN+sizeof(int));
struct Node
{
    LL sum;
    LL add;
    Node *ch[2];
    Node(){add=0,sum=0;ch[0]=ch[1]=NULL;}
};
Node nodes[4*MAXN];
int nodesize=0;

LL getsum(Node *&o){return o ? o->sum : 0;}

inline void push(int chain_id,Node *&o,int l,int r)
{
    if(!o)return ;
    o->sum+=o->add*(LS[chain_id][r]-LS[chain_id][l-1]);
    if(o->ch[0])o->ch[0]->add+=o->add;
    if(o->ch[1])o->ch[1]->add+=o->add;
    o->add=0;
}
void pull(int chain_id,Node *&o,int l,int r)
{
    int mid=(l+r)/2;
    push(chain_id,o->ch[0],l,mid),push(chain_id,o->ch[1],mid+1,r);
    o->sum=getsum(o->ch[0])+getsum(o->ch[1]);
}

Node *chain[MAXN];

void build_tree(Node *&o,int l,int r)
{
    if(!o)o=&(nodes[nodesize++]);
    //cout<<BUF<<" "<<o<<endl;
    if(l==r){return ;}
    int mid=(l+r)/2;
    build_tree(o->ch[0],l,mid);
    build_tree(o->ch[1],mid+1,r);
}

int tL,tR;
void add_tree(int chain_id,Node *&o,int l,int r,int v)
{
    push(chain_id,o,l,r);
    if(tL<=l&&r<=tR)
    {
        o->add+=v;
        return ;
    }
    int mid=(l+r)/2;
    if(tL<=mid)add_tree(chain_id,o->ch[0],l,mid,v);
    if(tR>mid)add_tree(chain_id,o->ch[1],mid+1,r,v);
    pull(chain_id,o,l,r);
}
LL query_tree(int chain_id,Node *&o,int l,int r)
{
    push(chain_id,o,l,r);
    if(tL<=l&&r<=tR)
    {
        return o->sum;
    }
    LL res=0;
    int mid=(l+r)/2;
    if(tL<=mid)res+=query_tree(chain_id,o->ch[0],l,mid);
    if(tR>mid)res+=query_tree(chain_id,o->ch[1],mid+1,r);
    return res;
}

void add_path(int from,int v)
{
    while(from!=-1)
    {
        //cout<<"querying "<<from<<" on chain "<<chain_of[from]<<endl;

        int c=chain_of[from];
        tL=1,tR=dep[from]-dep[head[from]]+1;
        add_tree(c,chain[c],1,LS[c].size(),v);
        from=head[from],from=p[from];
    }
}

LL query(int k)
{
    LL res=0;
    while(k!=-1)
    {
        //cout<<"querying "<<k<<" on chain "<<chain_of[k]<<endl;
        int c=chain_of[k];
        tL=1,tR=dep[k]-dep[head[k]]+1;
        res+=query_tree(c,chain[c],1,LS[c].size());
        k=head[k],k=p[k];
    }
    return res;
}

void dfs_for_size(int fa,int now,LL d,int depth)
{
    dis[now]=d;
    p[now]=fa;
    sz[now]=1;
    dep[now]=depth;
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i].v;
        if(v==fa){L[now]=G[now][i].l;continue;}
        dfs_for_size(now,v,d+G[now][i].l,depth+1);
        sz[now]+=sz[v];
        if(maxch[now]==-1)maxch[now]=v;
        else if(sz[maxch[now]]<sz[v])maxch[now]=v;
    }
}

void build_chain(int chain_id,int now)
{
    //cout<<"building chain "<<chain_id<<": "<<endl;
    int v=now;
    LS[chain_id].push_back(0);
    while(v!=-1)
    {
        LS[chain_id].push_back(LS[chain_id].back()+L[v]);
        //cout<<LS[chain_id].back()<<" ";
        vis[v]=true;
        head[v]=now;
        chain_of[v]=chain_id;
        v=maxch[v];
    }
    //puts("");
    build_tree(chain[chain_id],1,LS[chain_id].size());
    //cout<<chain[chain_id]<<endl;
}

int main()
{
    while(scanf("%d%d",&N,&Q)==2)
    {
        Q1=0;
        chain_sz=0;
        for(int i=0;i<N;i++)
        {
            sz[i]=0;maxch[i]=p[i]=-1;dis[i]=0;isset[i]=false;vis[i]=false;
            chain[i]=NULL;
            if(i==N-1)break;
            int u,v;
            LL l;
            scanf("%d%d%lld",&u,&v,&l);
            G[u].push_back(edge(l,v));
            G[v].push_back(edge(l,u));

        }
        int x=ran()%N;x=abs(x);
        dfs_for_size(-1,x,0LL,0);
        build_chain(chain_sz++,x);
        for(int i=0;i<N;i++)if(!vis[i]&&(p[i]==-1||vis[p[i]]))build_chain(chain_sz++,i);
        LL S=0;
        for(int i=0;i<Q;i++)
        {
            int t,k;
            scanf("%d%d",&t,&k);
            if(t==1)
            {
                if(isset[k])continue;
                S+=dis[k];
                add_path(k,-2);
                isset[k]=true;
                Q1++;
            }
            else
            {
                LL ans=S+(LL)Q1*dis[k]+query(k);

                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
