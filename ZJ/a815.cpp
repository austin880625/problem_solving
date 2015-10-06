#include<iostream>
#include<queue>
#include <stdio.h>
#include<string>

using namespace std;

struct poi
{
    int row,col;
};

int n,m,ans;
int mat[305][305];
int vis[305][305];
int dcol[6]={1,1,0,-1,-1,0};
int drow[6]={-1,0,1,1,0,-1};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans=2;
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&m);
        queue<poi> lQ;
        queue<poi> rQ;
        for(int i=0;i<n;i++)
        {
            char c[m+1];
            scanf("%s",c);
            for(int j=0;j<m;j++)
            {
                mat[i][j]=(c[j]=='O' ? 1 : 0);
            }
            if(mat[i][0])lQ.push((poi){i,0});
            if(mat[i][m-1])rQ.push((poi){i,m-1});
        }
        if(lQ.empty()&&rQ.empty())ans=2;
        else
        {
            while(!lQ.empty())
            {
                
            }
            if(ans!=0)
            {
                while(!rQ.empty())
                {
                    
                }
            }
        }
        printf("%d\n",ans);
    }
}
