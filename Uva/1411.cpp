#include <iostream>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#define MAXN 105
#define INF 0x3f3f3f3f
#define eps 10e-9
using namespace std;

int N;
int colony[MAXN][2];
double w[MAXN][MAXN];
double Lx[MAXN],Ly[MAXN];
int Left[MAXN];
bool S[MAXN],T[MAXN];
double dis(double dx,double dy)
{
    return sqrt((dx*dx)+(dy*dy));
}
int dcmp(double a,double b)
{
    if(fabs(a-b)<=eps)return 0;
    return a-b>0 ? 1 : -1;
}

bool match(int i)
{
    S[i]=true;
    for(int j=1;j<=N;j++)if(dcmp(Lx[i]+Ly[j],w[i][j])==0&&!T[j])
    {
        T[j]=true;
        if(!Left[j]||match(Left[j]))
        {
            Left[j]=i;
            return true;
        }
    }
    return false;
}
void update()
{
    double a=INF;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(S[i]&&!T[j])a=min(a,Lx[i]+Ly[j]-w[i][j]);
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(S[i])Lx[i]-=a;
        if(T[i])Ly[i]+=a;
    }
}

int main()
{
    int ks=0;
    while(scanf("%d",&N)==1)
    {
        if(ks++)puts("");
        int x,y;
        for(int i=1;i<=N;i++){Lx[i]=-INF;Ly[i]=0;Left[i]=0;scanf("%d%d",&colony[i][0],&colony[i][1]);}
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&x,&y);
            for(int j=1;j<=N;j++)
            {
                w[i][j]=-dis((double)(colony[j][0]-x),(double)(colony[j][1]-y));
                Lx[i]=max(Lx[i],w[i][j]);
            }
            //cout<<i<<" "<<Lx[i]<<endl;
        }

        for(int i=1;i<=N;i++)
        {
            while(1)
            {
                for(int j=1;j<=N;j++)S[j]=T[j]=0;
                if(match(i))break;
                else update();
                //for(int j=1;j<=N;j++)for(int k=1;k<=N;k++){assert(Lx[j]+Ly[k]>=w[j][k]);}
                //cout<<i<<" "<<Lx[i]<<endl;
            }
        }
        for(int i=1;i<=N;i++)
        {
            //cout<<Left[i]<<" "<<i<<" "<<w[Left[i]][i]<<endl;
            printf("%d\n",Left[i]);
        }
    }
    return 0;
}
