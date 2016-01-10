#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#define MAXN 20005
#define MAXM 60005

using namespace std;

int N,M;
int w[MAXN];
int blocked[MAXM];
struct command
{
    int type,target,v;
};
vector<command> query;
struct edge
{
    int u,v;
};
vector<edge> edges;
int ran()
{
    static int x=20151119;
    return x=x*0xdefaced+1;
}
struct Node
{
    int v,pri,sz;
    Node *ch[2];
    Node(int _v){v=_v;pri=ran();sz=1;ch[0]=ch[1]=NULL;}
};
Node *Treap[MAXN];
int DJset[MAXN];
int find(int x){return x==DJset[x] ? x : DJset[x]=find(DJset[x]);}

void maintain(Node *&O)
{
    O->sz=1;
    for(int i=0;i<2;i++)if(O->ch[i])O->sz+=O->ch[i]->sz;
}
int getsz(Node *&O){return O ? O->sz : 0;}
void rotate(Node *&O,int dir)
{
    Node *T=O->ch[dir^1];
    O->ch[dir^1]=T->ch[dir];
    T->ch[dir]=O;
    maintain(O);maintain(T);
    O=T;
}

void Insert(Node *&O,int v)
{
    if(!O){O=new Node(v);return ;}
    if(v<O->v)
    {
        Insert(O->ch[0],v);
        if(O->ch[0]->pri>O->pri)rotate(O,1);
    }
    else
    {
        Insert(O->ch[1],v);
        if(O->ch[1]->pri>O->pri)rotate(O,0);
    }
    maintain(O);
}
void Delete(Node *&O,int v)
{
    if(!O)return ;
    if(v==O->v)
    {
        Node *P=O;
        if(!O->ch[0]||!O->ch[1])
        {
            if(O->ch[0])O=O->ch[0];
            else O=O->ch[1];
            delete P;
        }
        else
        {
            int d=O->ch[0]->pri > O->ch[1]->pri ? 1 : 0;
            rotate(O,d);
            Delete(O->ch[d],v);
            if(O)maintain(O);
        }
        return ;
    }
    if(v<O->v)Delete(O->ch[0],v);
    else Delete(O->ch[1],v);
    if(O)maintain(O);
}

int kth(Node *&O,int k)
{
    if(!O||k<=0||k>O->sz)return 0;
    int now=getsz(O->ch[1])+1;
    if(now==k)return O->v;
    int dir=k<now ? 0 : 1;
    return kth(O->ch[dir^1],k-dir*now);
}

void Merge(Node *&a,Node *&b)
{
    if(!b)return ;
    if(b->ch[0])Merge(a,b->ch[0]);
    if(b->ch[1])Merge(a,b->ch[1]);
    Insert(a,b->v);
    delete b;
    b=NULL;
}

void MergeTree(int u,int v)
{
    int x=find(u),y=find(v);
    if(x!=y)
    {
        if(getsz(Treap[x])>getsz(Treap[y]))
        {
            DJset[y]=x;
            Merge(Treap[x],Treap[y]);
        }
        else
        {
            DJset[x]=y;
            Merge(Treap[y],Treap[x]);
        }
    }
}
void cleartree(Node *&O)
{
    if(!O)return ;
    if(O->ch[0])cleartree(O->ch[0]);
    if(O->ch[1])cleartree(O->ch[1]);
    delete O;
    O=NULL;
}

int main()
{
    int kase=0;
    while(scanf("%d%d",&N,&M)==2&&(N||M))
    {
        edges.clear();
        query.clear();
        for(int i=1;i<=N;i++){DJset[i]=i;scanf("%d",&w[i]);}
        for(int i=0;i<M;i++)
        {
            int u,v;
            blocked[i]=0;
            scanf("%d%d",&u,&v);
            edges.push_back((edge){u,v});
        }
        char com[2];
        while(scanf("%s",com)&&com[0]!='E')
        {
            int x,v;
            if(com[0]=='D')
            {
                scanf("%d",&x);
                blocked[--x]=1;
                query.push_back((command){1,x,0});
            }
            else if(com[0]=='C')
            {
                scanf("%d%d",&x,&v);
                query.push_back((command){2,x,w[x]});
                w[x]=v;
            }
            else if(com[0]=='Q')
            {
                scanf("%d%d",&x,&v);
                query.push_back((command){3,x,v});
            }
        }
        for(int i=1;i<=N;i++){Treap[i]=new Node(w[i]);}
        for(int i=0;i<edges.size();i++)
        {
            if(!blocked[i])
            {
                int u=edges[i].u,v=edges[i].v;
                //cout<<u<<" "<<v<<endl;
                MergeTree(u,v);
            }
        }
        long long int ans=0;
        int q=0;
        for(int i=query.size()-1;i>=0;i--)
        {
            command &c=query[i];
            if(c.type==1)
            {
                blocked[c.target]=0;
                edge &e=edges[c.target];
                MergeTree(e.u,e.v);
            }
            else if(c.type==2)
            {
                int t=find(c.target);
                Delete(Treap[t],w[c.target]);
                Insert(Treap[t],c.v);
                w[c.target]=c.v;
            }
            else if(c.type==3)
            {
                q++;
                int t=find(c.target),x=kth(Treap[t],c.v);
                ans+=x;
                //cout<<x<<endl;
            }
        }
        printf("Case %d: %.6lf\n",++kase,(double)ans/(double)q);
    }
    return 0;
}
