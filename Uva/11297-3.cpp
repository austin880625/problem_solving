#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAXN 505
#define INF 2147483646
using namespace std;

int grid[MAXN][MAXN];
int MX[MAXN*3][MAXN*3],MN[MAXN*3][MAXN*3];
int N,Q;

int X,O1D;
void build2D(int O,int L,int R)
{
    if(L==R)
    {
        if(X!=-1)
        {
            MX[O1D][O]=MN[O1D][O]=grid[X][L];
            //cout<<grid[Row][L]<<" "<<O1D<<" "<<O<<endl;
            return ;
        }
        MX[O1D][O]=max(MX[O1D*2][O],MX[O1D*2+1][O]);
        MN[O1D][O]=min(MN[O1D*2][O],MN[O1D*2+1][O]);
        return ;
    }
    int mid=(L+R)/2;
    build2D(O*2,L,mid);
    build2D(O*2+1,mid+1,R);

    MX[O1D][O]=max(MX[O1D][O*2],MX[O1D][O*2+1]);
    MN[O1D][O]=min(MN[O1D][O*2],MN[O1D][O*2+1]);
    //cout<<"\t"<<L<<" "<<R<<" "<<MX[O1D][O]<<" "<<MN[O1D][O]<<endl;
}

void build1D(int O,int L,int R)
{
    //cout<<L<<" "<<R<<endl;
    X=-1;
    O1D=O;
    if(L==R)
    {
        X=L;
        build2D(1,1,N);
        X=-1;
        return ;
    }
    int mid=(L+R)/2;
    build1D(O*2,L,mid);
    build1D(O*2+1,mid+1,R);
    O1D=O;
    build2D(1,1,N);
}

int L1D,R1D,L2D,R2D;
void query2D(int O,int L,int R,int &mx,int &mn)
{
    //cout<<"\t"<<L<<" "<<R<<" "<<L2D<<" "<<R2D<<endl;
        //cout<<MX[O1D][O]<<endl;
    if(L2D<=L&&R<=R2D)
    {
        mx=max(MX[O1D][O],mx);
        mn=min(MN[O1D][O],mn);
        return ;
    }
    int mid=(L+R)/2;
    if(L2D<=mid)query2D(O*2,L,mid,mx,mn);
    if(R2D>mid)query2D(O*2+1,mid+1,R,mx,mn);
}
void query1D(int O,int L,int R,int &mx,int &mn)
{
    //cout<<"1D "<<L<<" "<<R<<endl;
    if(L1D<=L&&R<=R1D)
    {
        O1D=O;
        query2D(1,1,N,mx,mn);
        //cout<<"QS"<<endl;
        return ;
    }
    int mid=(L+R)/2;
    if(L1D<=mid)query1D(O*2,L,mid,mx,mn);
    if(R1D>mid)query1D(O*2+1,mid+1,R,mx,mn);
}
int CX,CY,CV;
void modify2D(int O,int L,int R)
{
    if(L==R)
    {
        if(X!=-1)
        {
            //cout<<X<<L<<endl;
            grid[X][L]=CV;
            MX[O1D][O]=MN[O1D][O]=CV;
            return ;
        }
        MX[O1D][O]=max(MX[O1D*2][O],MX[O1D*2+1][O]);
        MN[O1D][O]=min(MN[O1D*2][O],MN[O1D*2+1][O]);
        return ;
    }
    int mid=(L+R)/2;
    if(CY<=mid)modify2D(O*2,L,mid);
    else modify2D(O*2+1,mid+1,R);
    MX[O1D][O]=max(MX[O1D][O*2],MX[O1D][O*2+1]);
    MN[O1D][O]=min(MN[O1D][O*2],MN[O1D][O*2+1]);
}
void modify1D(int O,int L,int R)
{
    O1D=O;
    X=-1;
    if(L==R)
    {
        X=L;
        modify2D(1,1,N);
        X=-1;
        return ;
    }
    int mid=(L+R)/2;
    if(CX<=mid)modify1D(O*2,L,mid);
    else modify1D(O*2+1,mid+1,R);
    O1D=O;
    modify2D(1,1,N);
}
void print()
{
    for(int y=1;y<=N;y++)
    {
        for(int x=1;x<=N;x++)
        {
            cout<<grid[x][y]<<"\t";
        }
        puts("");
    }
    puts("");
}
int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int y=1;y<=N;y++)
        {
            for(int x=1;x<=N;x++)
            {
                scanf("%d",&grid[x][y]);
            }
        }
        build1D(1,1,N);
        scanf("%d",&Q);
        char q[2];
        for(int i=0;i<Q;i++)
        {
            scanf("%s",q);
            if(q[0]=='c')
            {
                scanf("%d%d%d",&CY,&CX,&CV);
                modify1D(1,1,N);
                //print();
            }
            else
            {
                scanf("%d%d%d%d",&L2D,&L1D,&R2D,&R1D);
                int mx=-INF,mn=INF;
                query1D(1,1,N,mx,mn);
                printf("%d %d\n",mx,mn);
            }
        }
        break;
    }
    return 0;
}
