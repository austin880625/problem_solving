#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
#define MAXN 505
#define INF 0x3f3f3f3f

using namespace std;

int N,M,R,Gk,S,T;

int A[MAXN];
int w[MAXN][MAXN][MAXN];
int vis[MAXN];

int main()
{
    while(scanf("%d%d%d",&N,&M,&R)==3)
    {
        //memset(w,INF,sizeof(w));
        for(int i=0;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                for(int k=1;k<=N;k++)w[i][j][k]=INF;
            }
        }
        for(int i=1;i<=N;i++)scanf("%d",A+i),vis[i]=0,w[0][i][i]=0;
        for(int i=0;i<M;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);

            w[0][u][v]=min(w[0][u][v],c);
            w[0][v][u]=min(w[0][v][u],c);
        }

        for(int tt=R;tt;tt--)
        {
            //memset(d,INF,sizeof(d));
            scanf("%d%d%d",&Gk,&S,&T);
            if(Gk>A[S]||Gk>A[T]){puts("-1");continue;}
            if(vis[Gk]){printf("%d\n",w[Gk][S][T]==INF ? -1 : w[Gk][S][T]);continue;}
            //puts("YEE");
            /*
            Q.push(node(S,0));
            d[S]=0;
            while(!Q.empty())
            {
                node x=Q.top();Q.pop();
                int u=x.id;
                for(int v:G[u])
                {
                    if(A[v]<Gk)continue;
                    if(d[v]>d[u]+w[u][v])
                    {
                        d[v]=d[u]+w[u][v];
                        Q.push(node(v,d[v]));
                    }
                }
            }

            printf("%d\n",d[T]==INF ? -1 : d[T]);
            */
            for(int u=1;u<=N;u++)
            {
                for(int v=1;v<=N;v++)
                {
                    w[Gk][u][v]=w[0][u][v];
                    //if(w[u][v]!=INF)G[u].push_back(v),G[v].push_back(u);
                }
            }
            for(int k=1;k<=N;k++)
            {
                if(Gk>A[k])continue;
                for(int i=1;i<=N;i++)
                {
                    if(Gk>A[i])continue;
                    for(int j=1;j<=N;j++)
                    {
                        if(Gk>A[j])continue;
                        w[Gk][i][j]=min(w[Gk][i][j],w[Gk][i][k]+w[Gk][k][j]);
                        //cout<<i<<" "<<j<<" "<<k<<" "<<w[Gk][i][j]<<endl;
                    }
                }
            }
            printf("%d\n",w[Gk][S][T]==INF ? -1 : w[Gk][S][T]);
            vis[Gk]=1;
        }
    }
    return 0;
}
