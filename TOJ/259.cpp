#include <iostream>
#include <stdio.h>
#include <assert.h>
#define INF 2147483647

using namespace std;

struct Node
{
    int setv[2];
    Node *ch[2];
    Node(){setv[0]=0;setv[1]=0;ch[0]=ch[1]=NULL;}
};
int N,M;
//Node *P;
int op,A,B,h;
void pushdown(Node *&o,int l,int r)
{
    if(l==r)return ;
    if(o->setv[0])
    {
        if(o->setv[0]>o->ch[0]->setv[0])
        {
            o->ch[0]->setv[0]=o->setv[0];
            o->ch[0]->setv[1]=max(o->ch[0]->setv[1],o->ch[0]->setv[0]);
        }
        if(o->setv[0]>o->ch[1]->setv[0])
        {
            o->ch[1]->setv[0]=o->setv[0];
            o->ch[1]->setv[1]=max(o->ch[1]->setv[1],o->ch[1]->setv[0]);
        }
        //o->setv[0]=0;
    }
    if(o->setv[1])
    {
        //if(o->ch[0]->setv[1]==INF)o->ch[0]->setv[1]=o->setv[1];
        //if(o->ch[1]->setv[1]==INF)o->ch[1]->setv[1]=o->setv[1];
        if(o->setv[1]<o->ch[0]->setv[0])
        {
            o->ch[0]->setv[0]=o->setv[1];
            o->ch[0]->setv[1]=min(o->ch[0]->setv[1],o->setv[1]);
        }
        //else if(o->ch[0]->setv[0]==0)o->ch[0]->setv[1]=min(o->ch[0]->setv[1],o->setv[1]);
        //if(A==4&&B==7&&l==6&&r==10)printf("%d\n",o->ch[1]->setv[0]);
        if(o->setv[1]<o->ch[1]->setv[0])
        {
            o->ch[1]->setv[0]=o->setv[1];
            o->ch[1]->setv[1]=min(o->ch[1]->setv[1],o->setv[1]);
        }
        //else if(o->ch[1]->setv[0]==0)o->ch[1]->setv[1]=min(o->ch[1]->setv[1],o->setv[1]);
        //if(A==4&&B==7&&l==6&&r==10)printf("%d\n",o->ch[1]->setv[1]);
        //o->setv[1]=INF;
    }
    o->setv[0]=0;
    o->setv[1]=0;
}

void build(Node *&o,int l,int r)
{
    if(!o)o=new Node();
    //if(l==9&&r==10)P=o;
    if(l==r)return ;
    int mid=(l+r)/2;
    build(o->ch[0],l,mid);
    build(o->ch[1],mid+1,r);
}

void modify(Node *&o,int l,int r)
{
    printf("BEFORE. L:%d ,R:%d ,high:%d ,low:%d\n",l,r,o->setv[0],o->setv[1]);
    if(A<=l&&r<=B)
    {
        if(op==0&&o->setv[0]<h)o->setv[0]=h,o->setv[1]=max(o->setv[1],h);
        if(op==1&&o->setv[0]>h)
        {
            o->setv[0]=h;
            //if(o->setv[1]==0)o->setv[1]=h;
            o->setv[1]=min(o->setv[1],h);
        }
        printf("AFTER. L:%d ,R:%d ,high:%d ,low:%d\n",l,r,o->setv[0],o->setv[1]);
        return ;
    }
    pushdown(o,l,r);
    int mid=(l+r)/2;
    if(A<=mid)modify(o->ch[0],l,mid);
    if(mid<B)modify(o->ch[1],mid+1,r);
    //o->setv[1]=max(o->ch[0]->setv[1],o->ch[1]->setv[1]);
    printf("AFTER. L:%d ,R:%d ,high:%d ,low:%d\n",l,r,o->setv[0],o->setv[1]);
}
void print(Node *&o,int l,int r)
{
    pushdown(o,l,r);
    //if(l==9)printf("PRINTING. L:%d ,R:%d ,high:%d ,low:%d\n",l,r,o->setv[0],o->setv[1]);
    assert(o->setv[0]<=o->setv[1]);
    if(l==r){printf("%d\n",o->setv[0]);return ;}
    int mid=(l+r)/2;
    if(o->ch[0])print(o->ch[0],l,mid);
    if(o->ch[1])print(o->ch[1],mid+1,r);
}

Node *ST;
int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        ST=NULL;
        build(ST,1,N);
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d%d",&op,&A,&B,&h);
            op--;A++,B++;
            modify(ST,1,N);
            //printf("%d",P->setv[1]);
        }
        print(ST,1,N);
    }
    return 0;
}
