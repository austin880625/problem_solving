#include<iostream>
#include<stdio.h>

using namespace std;

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
            minv+=add,v+=add;
            if(ch[0])ch[0]->add+=add;
            if(ch[1])ch[1]->add+=add;
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
        rotate(O,dir^1);
    }
}
void split(Node *&O,int k,Node *&L,Node *&R)
{
    if(k==0){L=NULL,R=O;return ;}
    splay(O,k);
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

}

int main()
{

}
