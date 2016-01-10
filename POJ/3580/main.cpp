#include<iostream>
#include<stdio.h>

using namespace std;
int deV;
struct Node
{
    int v,sz,minv;
    int add,flip;
    Node *ch[2];
    Node(int xv)
    {
        v=xv;
        sz=1;
        minv=v;
        add=flip=0;
        ch[0]=ch[1]=NULL;
    }
    void up()
    {
        minv=v,sz=1;
        if(ch[0]){minv=min(minv,ch[0]->minv);sz+=ch[0]->sz;}
        if(ch[1]){minv=min(minv,ch[1]->minv);sz+=ch[1]->sz;}
    }
    void down()
    {
        if(flip)
        {
            flip^=1;
            swap(ch[0],ch[1]);
            if(ch[0])ch[0]->flip^=1;
            if(ch[1])ch[1]->flip^=1;
        }
        if(add!=0)
        {
            if(ch[0]){ch[0]->v+=add,ch[0]->minv+=add,ch[0]->add+=add;}
            if(ch[1]){ch[1]->v+=add,ch[1]->minv+=add,ch[1]->add+=add;}
            add=0;
        }
    }
};
void rotate(Node *&O,int dir)
{
    Node *T=O->ch[dir^1];
    O->ch[dir^1]=T->ch[dir];
    T->ch[dir]=O;
    O->up(),T->up();
    O=T;
}
void splay(Node *&O,int k)
{
    O->down();
    int now1=1+(O->ch[0] ? O->ch[0]->sz : 0),dir1=k<now1 ? 0 : 1;
    if(k!=now1)
    {
        k-=now1*dir1;
        Node *p=O->ch[dir1];
        p->down();
        int now2=1+(p->ch[0] ? p->ch[0]->sz :0),dir2=k<now2 ? 0 : 1;
        if(k!=now2)
        {
            k-=now2*dir2;
            splay(p->ch[dir2],k);
            if(dir1==dir2)rotate(O,dir1^1);
            else rotate(O->ch[dir1],dir2^1);
        }
        rotate(O,dir1^1);
    }
}
void split(Node *&O,int k,Node *&L,Node *&R)
{
    if(k==0){R=O;L=NULL;return ;}
    deV=O->v;
    splay(O,k);
    deV=O->v;
    L=O;
    R=O->ch[1];
    O->ch[1]=NULL;
    L->up();
}
Node *merge(Node *L,Node*R)
{
    if(L==NULL)return R;
    splay(L,L->sz);
    L->ch[1]=R;
    L->up();
    return L;
}

void ADD(Node *&O,int x,int y,int P)
{
    Node *T1,*T2;
    split(O,x-1,O,T1);
    split(T1,y-x+1,T1,T2);
    T1->v+=P,T1->minv+=P,T1->add+=P;
    O=merge(O,merge(T1,T2));
}

void DELETE(Node *&O,int x)
{
    Node *T1,*T2;
    split(O,x-1,O,T1);
    split(T1,1,T1,T2);
    delete T1;
    O=merge(O,T2);
}

void INSERT(Node *&O,int x,int P)
{
    Node *A=new Node(P);
    if(x==0){O=merge(A,O);return ;}
    Node *T1;
    split(O,x,O,T1);
    O=merge(O,merge(A,T1));
}

void REVERSE(Node *&O,int x,int y)
{
    Node *T1,*T2;
    split(O,x-1,O,T1);
    split(T1,y-x+1,T1,T2);
    T1->flip^=1;
    O=merge(O,merge(T1,T2));
}

void REVOLVE(Node *&O,int x,int y,int P)
{
    P=(P%(y-x+1)+(y-x+1))%(y-x+1);
    if(P==0)return ;    
    REVERSE(O,y-P+1,y);
    REVERSE(O,x,y-P);
    REVERSE(O,x,y);
}

int MIN(Node *&O,int x,int y)
{
    int res;
    Node *T1,*T2;
    split(O,x-1,O,T1);
    split(T1,y-x+1,T1,T2);
    res=T1->minv;
    O=merge(O,merge(T1,T2));
    return res;
}
void build(Node *&O)
{
    O->down();
    if(O->ch[0])build(O->ch[0]);
    cout<<O->v<<" ";
    if(O->ch[1])build(O->ch[1]);
}
int n,m,x,y,P;
char com[20];
Node *ST=NULL;
int main()
{
    scanf("%d",&n);
    //{
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            INSERT(ST,i,t);
            //build(ST);cout<<endl;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",com);
            if(com[0]=='A')
            {
                scanf("%d %d %d",&x,&y,&P);
                ADD(ST,x,y,P);
            }
            else if(com[0]=='D')
            {
                scanf("%d",&x);
                DELETE(ST,x);
            }
            else if(com[0]=='I')
            {
                scanf("%d %d",&x,&P);
                INSERT(ST,x,P);
            }
            else if(com[0]=='M')
            {
                scanf("%d %d",&x,&y);
                printf("%d\n",MIN(ST,x,y));
            }
            else if(com[3]=='E')
            {
                scanf("%d %d",&x,&y);
                REVERSE(ST,x,y);
            }
            else if(com[3]=='O')
            {
                scanf("%d %d %d",&x,&y,&P);
                REVOLVE(ST,x,y,P);
            }
            //build(ST),cout<<endl;
        }
    //}
    return 0;
}
