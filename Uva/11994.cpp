#include <stdio.h>
#include <iostream>
#include <assert.h>
#define MAXN 50005

using namespace std;

struct Node
{
    int tag,sum,color,sz,rev,id;
    Node *p;
    //p is the parent of the tree edge (of the highest node in the aux-tree) when it's the root of the aux-tree
    // and the parant of the aux-tree edge when it's not the root
    Node *ch[2];
    Node(){tag=sum=color=rev=0;id=0;sz=1;p=ch[0]=ch[1]=NULL;}
    void init(){tag=sum=color=rev=0;id=0;sz=1;p=ch[0]=ch[1]=NULL;}
};
int NODE_ID;
Node NODES[MAXN];
Node* newNode(){NODES[NODE_ID].init();return &NODES[NODE_ID++];}

inline int SZ(Node *o){return o ? o->sz : 0;}
inline int SUM(Node *o){return o ? o->sum : 0;}

void putTag(Node *o, int c){if(!o)return ;o->sum=o->color=o->tag=(1<<c);}

void pull(Node *o){
    if(!o)return ;
    assert(!o->tag);
    o->sz=1+SZ(o->ch[1])+SZ(o->ch[0]); o->sum=o->color|SUM(o->ch[0])|SUM(o->ch[1]);
}

void push(Node *o){
    if(!o)return ;
    if(o->rev){
        o->rev^=1;
        if(o->ch[0])o->ch[0]->rev^=1;
        if(o->ch[1])o->ch[1]->rev^=1;
        swap(o->ch[0],o->ch[1]);
    }
    if(o->tag){
        o->sum=o->color=o->tag;
        if(o->ch[0])o->ch[0]->color=o->ch[0]->sum=o->ch[0]->tag=o->tag;
        if(o->ch[1])o->ch[1]->color=o->ch[1]->sum=o->ch[1]->tag=o->tag;
        o->tag=0;
    }
}
//isroot : determine whether the node is the root of the aux-tree
inline bool isroot(Node *o){return o?(o->p ? (o->p->ch[0]!=o&&o->p->ch[1]!=o) : 1):0;}

//deal : when splaying a node, the tag of its ancestors must be pushed
void deal(Node *o){
    if(!isroot(o))deal(o->p);
    push(o);
}

int N,M;
Node *A[MAXN];
int ID(Node *o){return o ? o->id : 0;}

void debug(){
    for(int i=1;i<=N;i++){
        printf("Node %d: %d %d %d %d\n",i,ID(A[i]->ch[0]),ID(A[i]->ch[1]),ID(A[i]->p),A[i]->color);
    }
}
void debug(int i){
    if(!i){puts("null");return ;}
        printf("Node %d: %d %d %d %d\n",i,ID(A[i]->ch[0]),ID(A[i]->ch[1]),ID(A[i]->p),A[i]->color);
}
/*
6 6
0 1 1 3 3 0
1 2 1 1 1 1
3 2 3
1 3 2 3
1 6 1 1
3 4 6
3 4 5
*/
void rotate(Node *o, int d){
    //cout<<"rotating "<<o->id<<" with direction "<<d<<" "<<ID(o->p)<<" "<<ID(o->ch[0])<<" "<<ID(o->ch[1])<<endl;
    Node *t=o->ch[d^1];
    //cout<<"u"<<ID(t)<<"o"<<endl;
    assert(t);
    o->ch[d^1]=t->ch[d]; if(t->ch[d])t->ch[d]->p=o;
    bool notroot=(!isroot(o));
    if(notroot)o->p->ch[o->p->ch[1]==o]=t;
    t->p=o->p;
    t->ch[d]=o; o->p=t;
    pull(o);pull(t);if(notroot)pull(t->p);
    //cout<<"rotation completed "<<ID(t)<<" "<<ID(t->p)<<endl;
}

void splay(Node *o){
    if(!o||isroot(o)){push(o);return ;}
    //cout<<"splaying "<<o->id<<" "<<ID(o->p)<<endl;
    deal(o);
    int d1,d2;
    while(o->p&&!isroot(o->p)){
        assert(o->p->p);
        d1=(o==o->p->ch[0]);
        d2=(o->p==o->p->p->ch[0]);
        //debug(ID(o));debug(ID(o->p));debug(ID(o->p->p));
        //cxout<<"TTTT "<<o->p->id<<endl;
        if(d1^d2)rotate(o->p,d1),rotate(o->p,d2);
        else rotate(o->p->p,d2),rotate(o->p,d1);
        if(isroot(o))return ; //bug : o might be root of aux-tree after rotation
        //cxout<<ID(o->p)<<endl;
    }
    pull(o);
    //cxout<<o->p->id<<endl;
    d1=(o==o->p->ch[0]); //bug : forgot to change the direction
    rotate(o->p,d1);
    //cxout<<ID(o->p)<<endl;
    assert(isroot(o));
    //cout<<"splay comleted"<<endl;
}

void access(Node *o){
    //cout<<"accessing "<<o->id<<endl;
    if(!o)return ;
    //o->ch[1]->p become the pathparent, so it is cut but not need to be changed

    Node *currentPreferredChain=NULL;
    for(Node *t=o;t;t=t->p){
        splay(t);assert(!t->tag);
        assert(!currentPreferredChain||isroot(currentPreferredChain));
        t->ch[1]=currentPreferredChain;
        pull(t);
        currentPreferredChain=t;
    }
    splay(o);
    //cout<<"accessed"<<endl;
}

Node* find(Node *o){
    access(o);
    //debug();
    for(;o->ch[0];o=o->ch[0]){push(o);}
    return o;
}

Node* cut(Node *o){
    access(o);
    Node *res=o->p ? o->p :NULL;
    if(o->ch[0]){
        for(res=o->ch[0];res->ch[1];res=res->ch[1]);
        o->ch[0]->p=o->p;
        o->ch[0]=o->p=NULL;
    }
    return res;
}

void link(Node *x, Node *y){
    x->p=y;
}

void link_to(Node *x, Node *y, int c){
    if(x==y)return ;
    Node *v=cut(x);
    //cxout<<"got cut"<<endl;
    if(x==find(y)){
        //cxout<<"link back"<<endl;
        link(x,v); //link back if y is in the subtree of x
    }
    else{
        //cxout<<"link to"<<endl;
        link(x,y);
        x->color=(1<<c);
    }
}

void query(Node *x, Node *y, int c, int &ans1, int &ans2){
    if(x==y||find(x)!=find(y)){ans1=ans2=0;return ;}
    access(x);
    //debug();
    Node *currentPreferredChain=NULL;

    for(Node *t=y;t;t=t->p){
        splay(t);
        assert(!currentPreferredChain||isroot(currentPreferredChain));
        if(!t->p){
            if(c!=-1)putTag(t->ch[1], c),putTag(currentPreferredChain, c);
            else ans1=SZ(t->ch[1])+SZ(currentPreferredChain),ans2=SUM(t->ch[1])|SUM(currentPreferredChain);
        }
        t->ch[1]=currentPreferredChain;
        currentPreferredChain=t;
        pull(t);
    }
    splay(y);
}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        NODE_ID=0;
        for(int i=1;i<=N;i++){A[i]=newNode();A[i]->id=i;}
        for(int i=1,f;i<=N;i++){
            scanf("%d",&f);
            if(f)A[i]->p=A[f];
        }
        for(int i=1,c;i<=N;i++){
            scanf("%d",&c);
            if(A[i]->p)
                A[i]->color=(1<<c);
        }
        for(int i=1,op,x,y,c,ans1,ans2;i<=M;i++){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d%d",&x,&y,&c);
                link_to(A[x],A[y],c);
            }
            else if(op==2){
                scanf("%d%d%d",&x,&y,&c);
                query(A[x],A[y],c,ans1,ans2);
            }
            else{
                scanf("%d%d",&x,&y);
                query(A[x],A[y],-1,ans1,ans2);
                printf("%d %d\n",ans1,__builtin_popcount(ans2));
            }
            //debug();
        }
    }
    return 0;
}
