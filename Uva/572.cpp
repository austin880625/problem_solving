#include<iostream>
#include<queue>

using namespace std;

int m,n;

struct P
{
    int x;int y;
    int isover()
    {
        if(x<0||y<0||x>=m||y>=n)return 1;
        return 0;
    }
};

char grid[105][105];
int dx[8]={1,0,-1,1,0,-1,1,-1};
int dy[8]={1,1,1,-1,-1,-1,0,0};

int main()
{
    int ans;
    while(cin>>m)
    {
        ans=0;
        queue<P> Q;
        if(m==0)break;
        cin>>n;
        for(int i=0;i<m;i++)
        {
            cin>>grid[i];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    Q.push((P){i,j});
                    ans++;
                    while(!Q.empty())
                    {
                        P now=Q.front();
                        Q.pop();
                        grid[now.x][now.y]='*';
                        for(int k=0;k<8;k++)
                        {
                            P t=(P){now.x+dx[k],now.y+dy[k]};
                            if(!t.isover()&&grid[t.x][t.y]=='@')Q.push(t);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
