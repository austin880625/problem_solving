#include <stdio.h>
#include <iostream>
#include <assert.h>

#define MAXN 100005

using namespace std;

struct Node
{
    int setv,v;
    Node *ch[2];
    Node(){setv=0;v=1;ch[0]=ch[1]=NULL;}
};

int L,T,O;
int ml,mr,mc;
Node *S;

void push(Node *&o)
{
    if(!o->ch[0])o->ch[0]=new Node();o->ch[0]->setv=o->ch[0]->v=o->setv;
    if(!o->ch[1])o->ch[1]=new Node();o->ch[1]->setv=o->ch[1]->v=o->setv;
    o->setv=0;
}

void modify(Node *&o,int l,int r)
{
    //cout<<l<<" "<<r<<endl;
    if(!o)o=new Node();
    if(ml<=l&&r<=mr){o->setv=o->v=(1<<(mc-1));return ;}
    //cout<<"YEE"<<endl;
    if(o->setv){assert(l!=r);push(o);}
    int mid=(l+r)>>1;
    if(ml<=mid)modify(o->ch[0],l,mid);
    if(mid<mr)modify(o->ch[1],mid+1,r);
    o->v=0;
    if(o->ch[0])o->v|=o->ch[0]->v;
    else o->v|=1;
    if(o->ch[1])o->v|=o->ch[1]->v;
    else o->v|=1;
    //cout<<o->v<<endl;
}

int query(Node *&o,int l,int r)
{
    if(!o)return 1;
    if(ml<=l&&r<=mr)return o->v;
    if(o->setv)push(o);
    int mid=(l+r)>>1;
    int res=0;
    if(ml<=mid)res|=query(o->ch[0],l,mid);
    if(mid<mr)res|=query(o->ch[1],mid+1,r);
    return res;
}

int main()
{
    while(scanf("%d%d%d",&L,&T,&O)==3)
    {
        S=NULL;
        for(int i=0;i<O;i++)
        {
            char t[2];
            scanf("%s",t);
            if(t[0]=='C')
            {
                scanf("%d%d%d",&ml,&mr,&mc);
                //assert(ml<=mr);
                if(ml>mr)swap(ml,mr);
                modify(S,1,L);
            }
            else
            {
                scanf("%d%d",&ml,&mr);
                if(ml>mr)swap(ml,mr);
                int ans=0,q=query(S,1,L);
                while(q){ans+=(q&1),q>>=1;}
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
