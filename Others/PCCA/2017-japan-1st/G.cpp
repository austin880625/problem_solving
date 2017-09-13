#include <stdio.h>
#include <iostream>
#include <stack>
#define MAXN 55

using namespace std;

struct edge
{
    int r,c,t;
};

char G[MAXN][MAXN];
int N,M;
int low[MAXN][MAXN];
int vis[MAXN][MAXN];
int dr[4]={0,-1,0,1};
int dc[4]={1,0,-1,0};
int dfs_clock;
int bccno[MAXN][MAXN];
stack<edge> S;
int bcc_cnt;

void dfs1(int r,int c,int fr,int fc)
{
    vis[r][c]=low[r][c]=++dfs_clock;
    //cout<<r<<" "<<c<<" "<<dfs_clock<<endl;
    int ch=0;
    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i],nc=c+dc[i];
        if(nr<0||nr>=N||nc<0||nc>=M||G[nr][nc]=='#'||(nr==fr&&nc==fc))continue;
        if(!vis[nr][nc])
        {
            ch++;
            S.push((edge){r,c,i});
            dfs1(nr,nc,r,c);
            low[r][c]=min(low[nr][nc],low[r][c]);
            if(low[nr][nc]>=vis[r][c])
            {
                //cout<<r<<" "<<c<<" "<<nr<<" "<<nc<<" "<<low[nr][nc]<<" "<<vis[r][c]<<endl;
                bcc_cnt++;
                while(1)
                {
                    edge x=S.top();S.pop();
                    int vr=x.r+dr[x.t],vc=x.c+dc[x.t];
                    if(bccno[r][c]!=bcc_cnt)bccno[r][c]=bcc_cnt;
                    if(bccno[vr][vc]!=bcc_cnt)bccno[vr][vc]=bcc_cnt;
                    if((r==x.r&&c==x.c)&&(nr==vr&&nc==vc))break;
                }
                //b[r][c]=1;
            }
        }
        else if(vis[nr][nc]<vis[r][c]&&(nr!=fr||nc!=fc)){
            S.push((edge){r,c,i});
            low[r][c]=min(low[r][c],vis[nr][nc]);
        }
    }
    //if(ch>1)cout<<r<<" "<<c<<endl,G[r][c]='#';
}
/*
6 6
......
......
###.#.
......
......
......
*/
void dfs2(int r,int c)
{
    vis[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i],nc=c+dc[i];
        if(nr<0||nr>=N||nc<0||nc>=M||G[nr][nc]=='#'||vis[nr][nc])continue;
        dfs2(nr,nc);
    }
}

int main()
{
    while(scanf("%d%d",&N,&M)==2&&(N||M))
    {
        dfs_clock=bcc_cnt=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++){
                    vis[i][j]=low[i][j]=bccno[i][j]=0;
            }
        }
        for(int i=0;i<N;i++)
        {
            scanf("%s",G[i]);
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(!vis[i][j])dfs1(i,j,-1,-1);
            }
        }
        for(int i=0;i<N;i++){for(int j=0;j<M;j++){vis[i][j]=0;}}
        //dfs2(0,0);
        int x=bccno[0][0];
        //cout<<bccno[0][0]<<" "<<bccno[0][M-1]<<" "<<bccno[N-1][0]<<" "<<bccno[N-1][M-1]<<endl;
        //for(int i=0;i<N;i++){for(int j=0;j<M;j++)cout<<bccno[i][j]<<" ";puts("");}
        int ans=bccno[0][M-1]==x&&bccno[N-1][0]==x&&bccno[N-1][M-1]==x;

        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}
