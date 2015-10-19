#include<iostream>
#include<stdio.h>
#define ll long long
#define INF 2147483646
using namespace std;

int N;
int grid[505][505];

struct Node2D
{
    int minv,maxv;
    Node2D *lc,*rc;
    Node2D()
    {
        lc=rc=NULL;
    }
};
int L2D,R2D;
void query2D(Node2D *&O,int L,int R,int &mx,int &mn)
{
    if(!O)return ;
    if(L2D<=L&&R<=R2D)
    {
        mx=max(mx,O->maxv);
        mn=min(mn,O->minv);
        return ;
    }
    int mid=(L+R)/2;
    if(L2D<=mid)query2D(O->lc,L,mid,mx,mn);
    if(R2D>mid)query2D(O->rc,mid+1,R,mx,mn);
}
struct Node1D
{
    Node2D *T;
    Node1D *lc,*rc;
    Node1D()
    {
        T=NULL;
        lc=rc=NULL;
    }
};
int isLeaf=0,X;
int getMin(Node2D *A){return A ? A->minv : INF;}
int getMax(Node2D *A){return A ? A->maxv : -INF;}
void build2D(Node2D *&o,int L,int R,Node2D *&lch,Node2D *&rch)
{
    if(!o)o=new Node2D();
    if(L==R)
    {
        o->minv=min(getMin(lch),getMin(rch));
        o->maxv=max(getMax(lch),getMax(rch));
        return;
    }
    int mid=(L+R)/2;
    build2D(o->lc,L,mid,lch->lc,rch->lc);
    build2D(o->rc,mid+1,R,lch->rc,rch->rc);
    o->minv=min(getMin(o->lc),getMin(o->rc));
    o->maxv=max(getMax(o->lc),getMax(o->rc));
}
void build2DL(Node2D *&O,int L,int R)
{
    if(!O)O=new Node2D();
    if(L==R){O->minv=O->maxv=grid[X][L];return ;}
    int mid=(L+R)/2;
    build2DL(O->lc,L,mid);
    build2DL(O->rc,mid+1,R);
    O->minv=min(getMin(O->lc),getMin(O->rc));
    O->maxv=max(getMax(O->lc),getMax(O->rc));
}

void build1D(Node1D *&O,int L,int R)
{
    if(!O)O=new Node1D();
    X=-1;
    if(L==R){X=L;build2DL(O->T,0,N-1);return ;}
    if(L<R)
    {
        int mid=(L+R)/2;
        build1D(O->lc,L,mid);
        build1D(O->rc,mid+1,R);
    }
    build2D(O->T,0,N-1,O->lc->T,O->rc->T);
}

int L1D,R1D;
void query1D(Node1D *&O,int L,int R,int &mx,int &mn)
{
    if(!O)return ;
    if(L1D<=L&&R<=R1D)
    {
        query2D(O->T,0,N-1,mx,mn);
    }
    int mid=(L+R)/2;

    if(L1D<=mid)query1D(O->lc,L,mid,mx,mn);
    if(R1D>mid)query1D(O->rc,mid+1,R,mx,mn);
}
int CX,CY,CV;
void change2D(Node2D *&O,int L,int R,Node2D *&lch,Node2D *&rch)
{
    if(L==R)
    {
        O->minv=min(getMin(lch),getMin(rch));
        O->maxv=max(getMax(lch),getMax(rch));
        return ;
    }
    int mid=(L+R)/2;
    if(CY<=mid)change2D(O->lc,L,mid,lch->lc,rch->lc);
    else change2D(O->rc,mid+1,R,lch->rc,rch->rc);
    O->minv=min(getMin(O->lc),getMin(O->rc));
    O->maxv=max(getMax(O->lc),getMax(O->rc));
}
void change2DL(Node2D *&O,int L,int R)
{
    if(L==R){grid[X][L]=CV;O->minv=O->maxv=CV;return ;}
    int mid=(L+R)/2;
    if(CY<=mid)change2DL(O->lc,L,mid);
    else change2DL(O->rc,mid+1,R);
    O->minv=min(O->lc->minv,O->rc->minv);
    O->maxv=max(O->lc->maxv,O->rc->maxv);   //stop copying!!!
}

void change1D(Node1D *&O,int L,int R)
{
    X=-1;
    if(L==R){X=L;change2DL(O->T,0,N-1);return ;}
    int mid=(L+R)/2;
    if(CX<=mid)change1D(O->lc,L,mid);
    else change1D(O->rc,mid+1,R);
    change2D(O->T,0,N-1,O->lc->T,O->rc->T);
}
int Q;
int main()
{
    scanf("%d",&N);
    //{
        Node1D* ST=NULL;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }
        build1D(ST,0,N-1);
        scanf("%d",&Q);
        while(Q--)
        {
            char com[2];
            scanf("%s",com);
            if(com[0]=='c')
            {
                scanf("%d %d %d",&CX,&CY,&CV);
                CX--,CY--;
                change1D(ST,0,N-1);
            }
            else if(com[0]=='q')
            {
                scanf("%d %d %d %d",&L1D,&L2D,&R1D,&R2D);
                L1D--,L2D--,R1D--,R2D--;
                int resMx=-INF,resMn=INF;
                query1D(ST,0,N-1,resMx,resMn);
                printf("%d %d\n",resMx,resMn);
            }
        }
   // }
    return 0;
}
/*
5
1 2 3 4 5
0 9 2 1 3
0 2 3 4 1
0 1 2 4 5
8 5 3 1 4
4

*/
