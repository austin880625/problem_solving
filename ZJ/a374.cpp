#include<iostream>
#include<stdio.h>
#include<string.h>
#define INF 2147483640
using namespace std;

string s,t;
int ls,lt;
int gap[27];
int DP[810][810];

struct Node2D
{
    int maxv;
    Node2D *lc,*rc;
    Node2D(){lc=rc=NULL;maxv=0;}
};
int getMx(Node2D *&O)
{
    if(!O)return -INF;
    return O->maxv;
}
struct Node1D
{
    Node1D *lc,*rc;
    Node2D *ST;
    Node1D(){lc=rc=NULL;ST=NULL;}
};
int X1D;
void build2D(Node2D *&O,const int &L,const int &R,Node2D *&lch,Node2D *&rch)
{
    if(!O)O=new Node2D();
    if(L==R)
    {
        O->maxv=max(getMx(lch),getMx(rch));
        return ;
    }
    int mid=(L+R)/2;

    build2D(O->lc,L,mid,lch->lc,rch->lc);
    build2D(O->rc,mid+1,R,lch->rc,rch->rc);
    O->maxv=max(getMx(O->lc),getMx(O->rc));
}
void build2DL(Node2D *&O,const int &L,const int &R)
{
    if(!O)O=new Node2D();
    if(L==R)
    {
        //cout<<X1D<<" "<<L<<endl;
        O->maxv=DP[X1D][L];
        return ;
    }
    int mid=(L+R)/2;

    build2DL(O->lc,L,mid);
    build2DL(O->rc,mid+1,R);
    O->maxv=max(getMx(O->lc),getMx(O->rc));
}
void build1D(Node1D *&O,const int &L,const int &R)
{
    if(!O)O=new Node1D();
    if(L==R)
    {
        X1D=L;
        build2DL(O->ST,0,lt);
        return ;
    }
    int mid=(L+R)/2;
    build1D(O->lc,L,mid);
    build1D(O->rc,mid+1,R);

    build2D(O->ST,0,lt,O->lc->ST,O->rc->ST);
}

int L1D,R1D,L2D,R2D;
void query2D(Node2D *&O,const int &L,const int &R,int &mx)
{
    if(L2D<=L&&R<=R2D)
    {
        mx=max(mx,O->maxv);
        return ;
    }
    if(L==R){mx=max(0,mx);return ;}
    int mid=(L+R)/2;

    if(L2D<=mid)query2D(O->lc,L,mid,mx);
    if(R2D>mid)query2D(O->rc,mid+1,R,mx);
}
void query1D(Node1D *&O,const int &L,const int R,int &mx)
{
    if(L1D<=L&&R<=R1D)
    {
        query2D(O->ST,0,lt,mx);
        return ;
    }
    if(L==R){mx=max(0,mx);return ;}
    int mid=(L+R)/2;

    if(L1D<=mid)query1D(O->lc,L,mid,mx);
    if(R1D>mid)query1D(O->rc,mid+1,R,mx);
}
int CX,CY,CV;
void modify2DL(Node2D *&O,const int &L,const int &R)
{
    if(L==R)
    {
        O->maxv=DP[X1D][L]=CV;
        return ;
    }
    int mid=(L+R)/2;
    if(CY<=mid)modify2DL(O->lc,L,mid);
    else modify2DL(O->rc,mid+1,R);
    O->maxv=max(getMx(O->lc),getMx(O->rc));
}
void modify2D(Node2D *&O,const int &L,const int &R,Node2D *&lch,Node2D *&rch)
{
    if(L==R)
    {
        O->maxv=max(getMx(lch),getMx(rch));
        return ;
    }
    int mid=(L+R)/2;
    if(CY<=mid)modify2D(O->lc,L,mid,lch->lc,rch->lc);
    else modify2D(O->rc,mid+1,R,lch->rc,rch->rc);
    O->maxv=max(getMx(O->lc),getMx(O->rc));
}
void modify1D(Node1D *&O,const int &L,const int &R)
{
    if(L==R)
    {
        X1D=L;
        modify2DL(O->ST,0,lt);
        return ;
    }
    int mid=(L+R)/2;
    if(CX<=mid)modify1D(O->lc,L,mid);
    else modify1D(O->rc,mid+1,R);
    modify2D(O->ST,0,lt,O->lc->ST,O->rc->ST);
}
/*
void printdp()
{
    for(int i=0;i<=ls;i++)
    {
        for(int j=0;j<=lt;j++)
            printf("%d\t", DP[i][j]);
        puts("");
    }
    puts("");
}
*/
void delete2D(Node2D *&O)
{
    if(O->lc)delete2D(O->lc);
    if(O->rc)delete2D(O->rc);
    Node2D *P=O;
    O=NULL;delete P;
}
void delete1D(Node1D *&O)
{
    if(!O)return ;
    if(O->ST)delete2D(O->ST);
    if(O->lc)delete1D(O->lc);
    if(O->rc)delete1D(O->rc);
    Node1D *P=O;
    O=NULL;delete P;
}
Node1D *ST;
void solve()
{
    for(int i=0;i<=ls;i++)
        for(int j=0;j<=lt;j++)
            DP[i][j]=0;
    delete1D(ST);
    build1D(ST,0,ls);

    for(int i=1;i<=ls;i++)
    {
        for(int j=1;j<=lt;j++)
        {
            if(s[i-1]==t[j-1])
            {
                int mx=0;
                L1D=max(0,i-gap[s[i-1]-'A']);
                R1D=max(0,i-1);
                L2D=max(0,j-gap[s[i-1]-'A']);
                R2D=max(0,j-1);
                query1D(ST,0,ls,mx);
                CX=i,CY=j,CV=mx+1;
                modify1D(ST,0,ls);
                //printdp();
            }
        }
    }
    int ans=0;
    L1D=0,R1D=ls,L2D=0,R2D=lt;
    query1D(ST,0,ls,ans);
    printf("%d ",ans);
}
int main()
{
    int k;
    char q[2];
    while(cin>>s>>t)
    {
        scanf("%d",&k);
        ls=s.length();
        lt=t.length();
        for(int i=0;i<k;i++)
        {
            for(int i=0;i<27;i++)gap[i]=INF;
            while(scanf("%s",q)&&q[0]!='$')
            {
                scanf("%d",&gap[q[0]-'A']);
                gap[q[0]-'A']++;
            }
            solve();

        }
        puts("");
    }
    return 0;
}

/*
ACBDCAA ADDBCDBAC
2
$
*/
