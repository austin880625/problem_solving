#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAXN 100005
#define LL long long int
using namespace std;

int n,m;
struct edge{
    int u,v,w;
};
struct st{
    int x,r;
};
vector<edge> E;
vector<int> G[MAXN];
vector<edge> NG[10];
vector<int> same[10];
int group[MAXN];
queue<st> Q;
queue<edge> X;
int vis[MAXN][10];
LL dp[10][10][10];
LL ans[10];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){group[i]=-1;for(int j=0;j<10;j++)vis[i][j]=0;}
    for(int i=0,u,v,r;i<m;i++){
        scanf("%d%d%d",&u,&v,&r);
        G[u].push_back(E.size());
        E.push_back((edge){u,v,r%10});
        G[v].push_back(E.size());
        E.push_back((edge){v,u,10-r%10});
    }
    Q.push((st){1,0});
    same[0].push_back(1);
    vis[1][0]=1;
    while(!Q.empty()){
        st s=Q.front();Q.pop();
        //cout<<s.x<<endl;
        int x=s.x,r=s.r;
        vis[x][r]=1;
        for(int i=0;i<G[x].size();i++){
            edge e=E[G[x][i]];
            int v=e.v;
            int nr=(s.r+e.w)%10;
            if(!vis[v][nr]){
                Q.push((st){v,nr});
                same[nr].push_back(v);
                vis[v][nr]=1;
            }
        }

    }
    //int nn=10;
    // cout<<"-----"<<endl;
    for(int i=0;i<10;i++){
        // cout<<i<<" "<<endl;
        for(int j=0;j<same[i].size();j++){
            group[same[i][j]]=i;
            // cout<<same[i][j]<<" ";
        }
    //    puts("");
    }
    //cout<<"----"<<endl;

    for(edge e:E){
        int u=e.u,v=e.v;
        //if(group[u]!=group[v]){
            NG[group[u]].push_back((edge){group[u],group[v],e.w});
        //}
    }
    // for(int i=0;i<10;i++){
    //     cout<<i<<": ";
    //     for(int j=0;j<NG[i].size();j++){
    //         cout<<NG[i][j].v<<"("<<NG[i][j].w<<")"<<" ";
    //     }
    //     puts("");
    // }
    for(int i=0;i<10;i++)
    {
        dp[0][i][i]=1;
        X.push((edge){0,i,i});
        //cout<<i<<endl;
        while(!X.empty()){
            edge t=X.front();X.pop();
            // cout<<t.w<<endl;
            for(edge e:NG[t.w]){
                int v=e.v,w=e.w;
                if(i==v)continue;
                if(dp[(t.u+w)%10][i][v]==0){
                    X.push((edge){(t.u+w)%10,i,v});
                }
                dp[(t.u+w)%10][i][v]+=dp[t.u][i][t.w];
            }

        }
        dp[0][i][i]--;
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(dp[j][i][k])ans[j]++;
                // if(i==5||i==6||i==7)cout<<dp[j][i][k]<<" ";
            }
            // if(i==5||i==6||i==7)puts("");
        }
        // if(i==5||i==6||i==7)puts("");
    }
    for(int i=0;i<10;i++)printf("%lld\n",ans[i]);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
