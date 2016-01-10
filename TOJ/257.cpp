#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXN 1000005
#define MOD 3
using namespace std;

struct Node
{
    int cnt[3];
    int setv,add;
    Node *ch[2];
    Node(){cnt[0]=0;cnt[1]=cnt[2]=0;setv=0;add=0;ch[0]=ch[1]=NULL;}
};
void pushdown(Node *&O,int l,int r)
{
    if(l==r)return ;
    if(O->setv)
    {
        O->setv=0;
        if(O->ch[0])O->ch[0]->setv=1,O->ch[0]->add=0;
        if(O->ch[1])O->ch[1]->setv=1,O->ch[1]->add=0;
    }
    if(O->add)
    {
        //int tmp=O->cnt[2];
        //O->cnt[2]=O->cnt[1];O->cnt[1]=O->cnt[0];O->cnt[0]=tmp;
        if(O->ch[0])O->ch[0]->add=(O->ch[0]->add+O->add)%MOD;
        if(O->ch[1])O->ch[1]->add=(O->ch[1]->add+O->add)%MOD;
        O->add=0;
    }
}
void pull(Node *&O,int l,int r)
{
    if(O->setv)
    {
        O->cnt[0]=r-l+1;
        O->cnt[1]=O->cnt[2]=0;
        return ;
    }
    if(l==r)return ;
    int mid=(l+r)/2;
    O->cnt[0]=0,O->cnt[1]=0,O->cnt[2]=0;
    for(int i=0;i<MOD;i++)
    {
        if(O->ch[0]->setv&&O->ch[0]->add==i)O->cnt[i]+=mid-l+1;
        if(O->ch[1]->setv&&O->ch[1]->add==i)O->cnt[i]+=r-mid;
    }
    for(int i=0;i<MOD;i++)
    {
        if(!O->ch[0]->setv)O->cnt[(i+O->ch[0]->add)%MOD]+=O->ch[0]->cnt[i];
        if(!O->ch[1]->setv)O->cnt[(i+O->ch[1]->add)%MOD]+=O->ch[1]->cnt[i];
    }
}
char S[20];
int N,M;
int A,B;
void build(Node *&O,int l,int r)
{
    if(!O)O=new Node();
    if(l==r){
        O->cnt[0]=1;
        O->cnt[1]=O->cnt[2]=0;
        return ;
    }
    int mid=(l+r)/2;
    build(O->ch[0],l,mid);
    build(O->ch[1],mid+1,r);
    pull(O,l,r);
}
void add(Node *&O,int l,int r)
{
    pushdown(O,l,r);
    // cout<<l<<" "<<r<<endl;
    if(A<=l&&r<=B)
    {
        O->add=(O->add+1)%MOD;
        pull(O,l,r);
        return ;
    }
    int mid=(l+r)/2;
    if(A<=mid)add(O->ch[0],l,mid); else pull(O->ch[0],l,mid);
    //assert(0);
    if(mid<B)add(O->ch[1],mid+1,r); else pull(O->ch[1],mid+1,r);
    pull(O,l,r);
}
void modify(Node *&O,int l,int r)
{
    pushdown(O,l,r);
    if(A<=l&&r<=B)
    {
        O->setv=1;O->add=0;
        pull(O,l,r);
        return ;
    }
    int mid=(l+r)/2;
    if(A<=mid)modify(O->ch[0],l,mid); else pull(O->ch[0],l,mid);
    if(mid<B)modify(O->ch[1],mid+1,r); else pull(O->ch[1],mid+1,r);
    pull(O,l,r);
}
void query(Node *&O,int l,int r,int &ans)
{
    // printf("l:%d r:%d add:%d setv:%d has %d ones\n",l,r,O->add,O->setv,O->cnt[0]);
    if(A<=l&&r<=B)
    {
        if(O->setv&&O->add==0)ans+=r-l+1;
        else if(!O->setv)ans+=O->cnt[(MOD-O->add)%MOD];
        // printf("added\n");
        return ;
    }
    pushdown(O,l,r);
    int mid=(l+r)/2;
    if(A<=mid)query(O->ch[0],l,mid,ans); else pull(O->ch[0],l,mid);
    if(mid<B)query(O->ch[1],mid+1,r,ans); else pull(O->ch[1],mid+1,r);
    pull(O,l,r);
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
            scanf("%s",S);
            scanf("%d%d",&A,&B);
            if(S[0]=='T')
            {
                add(ST,1,N);
            }
            else if(S[0]=='R')
            {
                modify(ST,1,N);
            }
            else if(S[0]=='C')
            {
                int ans=0;
                query(ST,1,N,ans);
                printf("%d\n",ans);
            }
        }
        break;
    }
    return 0;
}
