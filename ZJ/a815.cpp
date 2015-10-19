#include<iostream>
#include<queue>
#include<stack>
#include <stdio.h>
#include<string.h>

using namespace std;

struct poi
{
    int row,col;
    bool operator ==(const poi &rhs)const
    {
        return row==rhs.row&&col==rhs.col;
    }
    bool operator !=(const poi &rhs)const
    {
        return row!=rhs.row||col!=rhs.col;
    }
};

int n,m,ans;
bool mat[305][305];
int vis[305][305];
int low[305][305];
int vis2[305][305];
int dcol[6]={0,1,1,0,-1,-1};
int drow[6]={-1,-1,0,1,1,0};
int dfs_clock=0;

void dfs(poi X,poi fa)
{
    vis[X.row][X.col]=low[X.row][X.col]=++dfs_clock;
    int ch=0;
    
    for(int i=0;i<6;i++)
    {
        int nr=X.row+drow[i],nc=X.col+dcol[i];
        if(nr<0||nr>=n||nc<0||nc>=m||!mat[nr][nc])continue;
        
        if(!vis[nr][nc])    //它是樹邊
        {
            ch++;
            dfs((poi){nr,nc},X);
            
            low[X.row][X.col]=min(low[X.row][X.col],low[nr][nc]);   //遞回完了，"子樹"low值已經完成
            
            if(fa!=(poi){-1,-1}&&low[nr][nc]>=vis[X.row][X.col])
            {
                mat[X.row][X.col]=0;    //把割點擋起來
            }
        }
        else if(nr!=fa.row||nc!=fa.col) //走過的子節點不是父親時才是回邊
        {
            low[X.row][X.col]=min(low[X.row][X.col],vis[nr][nc]);  //直接更新，反正還有子節點的時候還會再更新
        }
    }
}

void dfs2(poi X)
{
    vis2[X.row][X.col]=1;
    
    for(int i=0;i<6;i++)
    {
        int nr=X.row+drow[i],nc=X.col+dcol[i];
        if(nr<0||nr>=n||nc<0||nc>=m||!mat[nr][nc])continue;
        if(nr==n-1&&nc==m-1){vis2[nr][nc]=1;return;}
        if(!vis2[nr][nc])
        {
            dfs2((poi){nr,nc});
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans=2;
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            char c[m+1];
            scanf("%s",c);
            for(int j=0;j<m;j++)
            {
                mat[i][j]=(c[j]=='O' ? false : true);
            }
        }
        dfs_clock=0;
        
        poi root=(poi){0,0};
        dfs(root,(poi){-1,-1});
        if(!vis[n-1][m-1])ans=0;
        else
        {
            dfs2(root);
            //for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<vis2[i][j];cout<<endl;}
            if(!vis2[n-1][m-1]){ans=1;}
        }
        
        printf("%d\n",ans);
    }
    return 0;
}
