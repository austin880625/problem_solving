#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
int Z,T,N,M,ans;
int p[1000005];
int qr[100005];
int grid;
int vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct land
{
    int pos,h;
    bool operator < (const land &rhs)const{
        return h<rhs.h;
    }
};
priority_queue<land> Q;
int find(int x){
    return x==p[x] ? x : (p[x]=find(p[x]));
}

void down(int t)
{
    land L;
    while(!Q.empty()&&Q.top().h>qr[t])
    {
        L=Q.top();Q.pop();
        int x=L.pos/M,y=L.pos%M;
        ans++;
        vis[x][y]=1;
        //cout<<x<<" "<<y<<endl;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]<0||x+dx[i]>=N)continue;
            if(y+dy[i]<0||y+dy[i]>=M)continue;
            int newpos=(x+dx[i])*M+y+dy[i];
            //cout<<vis[x+dx[i]][y+dy[i]]<<endl;
            if(vis[x+dx[i]][y+dy[i]]&&find(newpos)!=find(L.pos))
            {
                p[find(L.pos)]=find(newpos);
                ans--;
            }
        }
    }
}

void print()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<p[i*M+j]<<"\t";
        }
        cout<<endl;
    }
    puts("");
}

int main()
{
    while(scanf("%d",&Z)==1){
        while(Z--)
        {
            ans=0;
            scanf("%d %d",&N,&M);
            while(!Q.empty())Q.pop();
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    scanf("%d",&grid);
                    p[i*M+j]=i*M+j;
                    vis[i][j]=0;
                    Q.push((land){i*M+j,grid});
                }
            }
            scanf("%d",&T);
            for(int i=0;i<T;i++)
            {
                scanf("%d",&qr[i]);
            }
            for(int i=T-1;i>=0;i--)
            {
                down(i);
                //print();
                qr[i]=ans;
            }
            for(int i=0;i<T;i++)printf("%d ",qr[i]);
            puts("");
        }
    }
}
