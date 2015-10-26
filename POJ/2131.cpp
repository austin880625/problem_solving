#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int rand()
{
    static int x=20151023;
    return x=x*0xdefaced+1;
}
int M,N;
vector<int> ANS;
struct Node
{
    int v,sz;
    Node* ch[2];
    Node(int _v){v=_v;sz=1;ch[0]=ch[1]=NULL;}
    void maintain()
    {
        sz=1;
        if(ch[0])sz+=ch[0]->sz;
        if(ch[1])sz+=ch[1]->sz;
    }
};
int getsz(Node *&O){return O ? O->sz : 0;}

void rotate(Node *&O,int dir)
{
    Node *T=O->ch[dir^1];
    O->ch[dir^1]=T->ch[dir];
    T->ch[dir]=O;
    O->maintain();T->maintain();
    O=T;
}
void splay(Node*& O,int k)
{
    O->maintain();
    int now1=getsz(O->ch[0])+1;
    if(k==now1){return ;}
    int dir1=k<now1 ? 0 : 1;
    k-=now1*dir1;
    Node *P=O->ch[dir1];
    P->maintain();
    int now2=getsz(P->ch[0])+1;
    if(now2!=k)
    {
        int dir2=k<now2 ? 0 : 1;
        k-=now2*dir2;
        splay(P->ch[dir2],k);
        if(dir1==dir2)rotate(O,dir1^1);
        else rotate(O->ch[dir1],dir2^1);
    }
    O->maintain();
    rotate(O,dir1^1);
}
void split(Node *&O,int k,Node *&L,Node *&R)
{
    splay(O,k);
       // cout<<" "<<k<<endl;
    R=O->ch[1];
    O->ch[1]=NULL;
    L=O;
    L->maintain();
}
Node *merge(Node *L,Node *R)
{
    Node *res;
    if(!L){res=R;return res;}
    splay(L,getsz(L));
    L->ch[1]=R;L->maintain();
    res=L;
    res->maintain();
    return res;
}
void insert(Node *&O,int v,int k)
{
    if(!O){O=new Node(v);return;}
    if(k==0)
    {
        Node *A=new Node(v);
        O=merge(A,O);
        O->maintain();
        return ;
    }
    Node *T1,*T2;
    split(O,k,O,T1);
    T2=new Node(v);
    O=merge(O,merge(T2,T1));
    
    O->maintain();
    //if(getsz(O->ch[0])>getsz(O->ch[1])+1)rotate(O,1);
    //else if(getsz(O->ch[1])>getsz(O->ch[0])+1)rotate(O,0);
}
void change(Node *&O,int v,int k)
{
    if(!O){O=new Node(v);return ;}
    //cout<<O->v<<endl;
    int now=getsz(O->ch[0])+1;
    if(k==now)
    {
        if(O->v==0)O->v=v;
        else {insert(O->ch[0],v,now-1);}
    }
    else if(k<now)
    {
        change(O->ch[0],v,k);
    }
    else
    {
        change(O->ch[1],v,k-now);
    }
    O->maintain();
}
Node *ST;
void build(Node *&O)
{
    if(!O){return ;}
    //cout<<"(";
    if(O->ch[0])build(O->ch[0]);
    printf("%d ",O->v);
    //ANS.push_back(O->v);
    if(O->ch[1])build(O->ch[1]);
    //cout<<")";
}
int pop(Node *&O)
{
    if(!O)return 0;
    if(!O->ch[1])
    {
        if(O->v==0)
        {
        Node *P=O;
        O=O->ch[0];
        delete P;
        return 1;
        }
        return 0;
    }
    int res = pop(O->ch[1]);
    O->maintain();
    return res;
}
void debug()
{
    int u,v;
    while(scanf("%d %d",&u,&v)==2)
    {
        //build(ST);
        change(ST,v,u);
        build(ST);puts("");
    }
}
int main()
{
    //debug();
    while(scanf("%d %d",&N,&M)){
        ST=NULL;ANS.clear();
        for(int i=1;i<=M;i++)insert(ST,0,1);
        
        //build(ST);
        for(int i=1;i<=N;i++)
        {
            int x;
            scanf("%d",&x);
            change(ST,i,x);
            //cout<<i<<endl;
            //build(ST);puts("");
        }
        while(pop(ST)){}
        printf("%d\n",getsz(ST));
        build(ST);puts("");
    }
    return 0;
}
