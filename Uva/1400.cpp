#include <iostream>
#include <stdio.h>
#include <assert.h>
#define MAXN 500000
#define LL long long int
using namespace std;

LL A[MAXN];
LL sum[MAXN];
struct inter
{
    int l,r;
    inter(int _l,int _r){l=_l,r=_r;}
    inter(){l=1;r=0;}
    bool operator >(const inter &rhs)const
    {
        LL x=sum[r]-sum[l-1],y=sum[rhs.r]-sum[rhs.l-1];
        if(rhs.l>rhs.r)return l>r ? 0 : 1;
        if(l>r)return 0;
        if(x==y)
        {
            if(l<rhs.l)return 1;
            if(l==rhs.l&&r<rhs.r)return 1;
            return 0;
        }
        return x>y;
    }
    bool operator ==(const inter &rhs)const{return sum[r]-sum[l-1]==sum[rhs.r]-sum[rhs.l-1];}
    inter operator =(const inter &rhs)
    {
        l=rhs.l;r=rhs.r;
        return inter(l,r);
    }
    inter operator |(const inter &rhs)const{
        assert(r==rhs.l-1);
        if(rhs.l>rhs.r)return inter(l,r);
        return inter(l,rhs.r);
    }
};
inter mmax(const inter &a,const inter &b){return a > b ? a : b;}
LL val(inter a){return sum[a.r]-sum[a.l-1];}
struct Node
{
    inter max_sub,max_pre,max_suf;
    Node* ch[2];
    Node(){
        ch[0]=ch[1]=NULL;
    }
};
int N,M;
int L,R;
Node *ST;
void build(Node *&o,int l,int r)
{
    if(!o)o=new Node();
    if(l==r)
    {
        inter x=inter(l,r);
        o->max_sub=x;
        o->max_pre=o->max_suf=x;
        return ;
    }
    int mid=(l+r)/2;
    build(o->ch[0],l,mid);
    build(o->ch[1],mid+1,r);
    o->max_pre=mmax(o->ch[0]->max_pre,inter(l,mid)|o->ch[1]->max_pre);
    o->max_suf=mmax(o->ch[1]->max_suf,o->ch[0]->max_suf|inter(mid+1,r));
    o->max_sub=mmax(o->ch[0]->max_sub,o->ch[1]->max_sub);
    o->max_sub=mmax(o->max_sub,o->ch[0]->max_suf|o->ch[1]->max_pre);
}
inter qsuf(Node *&o,int l,int r,int ql)
{
    //cout<<"suf "<<l<<" "<<r<<endl;
    if(o->max_suf.l>=ql)return o->max_suf;
    int mid=(l+r)/2;
    if(ql<=mid)return mmax(qsuf(o->ch[0],l,mid,ql)|inter(mid+1,r),o->ch[1]->max_suf);
    return qsuf(o->ch[1],mid+1,r,ql);
}
inter qpre(Node *&o,int l,int r,int qr)
{
    //cout<<"pre "<<l<<" "<<r<<endl;
    if(o->max_pre.r<=qr)return o->max_pre;
    int mid=(l+r)/2;
    if(qr>mid)return mmax(inter(l,mid)|qpre(o->ch[1],mid+1,r,qr),o->ch[0]->max_pre);
    return qpre(o->ch[0],l,mid,qr);
}
inter query(Node *&o,int l,int r,int ql,int qr)
{
    //cout<<"q "<<l<<" "<<r<<endl;
    if(ql<=o->max_sub.l&&o->max_sub.r<=qr)return o->max_sub;
    int mid=(l+r)/2;
    inter res=inter(ql,qr),tmp=inter(1,0);
    if(ql<=mid){res=mmax(res,query(o->ch[0],l,mid,ql,min(qr,mid)));}
    if(qr>mid){res=mmax(res,query(o->ch[1],mid+1,r,max(mid+1,ql),qr));}
    if(ql<=mid&&mid<qr)tmp=qsuf(o->ch[0],l,mid,ql)|qpre(o->ch[1],mid+1,r,qr);
    //cout<<"q "<<l<<" "<<r<<endl;
    //cout<<val(tmp)<<" "<<val(res)<<endl;
    assert(tmp.l!=tmp.r);
    res=mmax(res,tmp);
    return res;
}

int main()
{
    int kase=0;
    while(scanf("%d%d",&N,&M)==2)
    {
        ST=NULL;
        for(int i=1;i<=N;i++)scanf("%lld",&A[i]);
        sum[0]=0;
        for(int i=1;i<=N;i++)sum[i]=sum[i-1]+A[i];
        build(ST,1,N);
        printf("Case %d:\n",++kase);
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&L,&R);
            inter ans=query(ST,1,N,L,R);
            printf("%d %d\n",ans.l,ans.r);
        }
    }
    return 0;
}
