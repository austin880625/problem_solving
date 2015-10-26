#include<iostream>
#include<stdio.h>
#define MAXN 505
using namespace std;

int grid[MAXN][MAXN];
int MX[MAXN*4][MAXN*4],MN[MAXN*4][MAXN*4];
int N,Q;

int Row,O1D;
void build2D(int O,int L,int R)
{
    if(L==R)
    {
        if(Row!=-1)
        {
            MX[O1D][O]=MN[O1D][O]=grid[Row][L];
            return ;
        }
        MX[O1D][O]=max(MX[O1D*2][O],MX[O1D*2+1][O]);
        MN[O1D][O]=min(MN[O1D*2][O],MN[O1D*2+1][O]);
        return ;
    }
    int mid=(L+R)/2;
    build2D(O*2,L,mid);
    build2D(O*2,mid+1,R);

    MX[O1D][O]=max(MX[O1D][O*2],MX[O1D][O*2+1]);
    MN[O1D][O]=min(MN[O1D][O*2],MN[O1D][O*2+1]);
}

void build1D(int O,int L,int R)
{
    Row=-1;
    O1D=O;
    if(L==R)
    {
        Row=L;
        build2D(1,1,N);
        return ;
    }
    int mid=(L+R)/2;
    build1D(O*2,L,mid);
    build1D(O*2+1,mid+1,R);

    build2D(1,1,N);
}

int L1D,R1D,L2D,R2D;
void query2D(int O,int L,int R,int &mx,int &mn)
{
    if(L<=L2D&&R2D<=R)
    {
        mx=max(MX[O1D][O],mx);
        mn=min(MN[O1D][O],mn);
        return ;
    }
    int mid=(L+R)/2;
    if(L2D<=mid)query2D(O*2,L,mid,mx,mn);
    if(R2D>mid)query2D(O*2+1,mid+1,R,mx,mn);
}
void query1D(int O,int L,int R,int &mx,&mn)
{

}

int main()
{

    return 0;
}
