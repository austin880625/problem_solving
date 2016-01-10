#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>

#define MAXR 105
#define MAXC 105
#define INF 2147483646
using namespace std;

int R,C;
int N;
int grid[MAXR][MAXC];
int dis[MAXR][MAXC];
string name;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct poi
{
    int x,y;
};
queue<poi> Q;
int main()
{
    scanf("%d",&N);
    while(N--)
    {
        while(!Q.empty())Q.pop();
        cin>>name;
        scanf("%d%d",&R,&C);
        //if(R==1&&C==1){cout<<name<<": ";printf("1\n");continue;}
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                scanf("%d",&grid[i][j]);
                dis[i][j]=-INF;
            }
        }
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                int dir=0,able=4;
                for(int k=0;k<4;k++)
                {
                    if(i+dx[k]<0||i+dx[k]>=R||j+dy[k]<0||j+dy[k]>=C){able--;continue;}
                    if(grid[i][j]>grid[i+dx[k]][j+dy[k]])dir++;
                }
                if(dir==able){dis[i][j]=1;Q.push((poi){i,j});}
            }
        }
        while(!Q.empty())
        {
            poi P=Q.front();Q.pop();
            int r=P.x,c=P.y;
            for(int i=0;i<4;i++)
            {
                if(r+dx[i]<0||r+dx[i]>=R||c+dy[i]<0||c+dy[i]>=C)continue;
                if(grid[r][c]>grid[r+dx[i]][c+dy[i]])
                {
                    if(dis[r+dx[i]][c+dy[i]]<dis[r][c]+1)
                        dis[r+dx[i]][c+dy[i]]=dis[r][c]+1;
                    Q.push((poi){r+dx[i],c+dy[i]});
                }
            }
        }
        int maxl=0;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(maxl<dis[i][j])maxl=dis[i][j];
            }
        }
        cout<<name<<": ";
        printf("%d\n",maxl);
    }
    return 0;
}
