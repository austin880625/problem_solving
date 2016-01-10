//
//  p1.cpp
//  
//
//  Created by Mac on 4/3/15.
//
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<string>
#define MAX_N 1005
#define INF 20000

using namespace std;

struct edge
{
    int from,to;
    bool operator < (const edge &rhs)const
    {
        return from<to;
    }
};

vector<edge> edges;

vector<int> G[MAX_N];
int N;
int vis[MAX_N][MAX_N];
int c,ans;

int maxSubTree(int now)
{
    vis[c][now]=1;
    priority_queue<int> Q;
    int ch=0;
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        if(!vis[c][e.to])
        {
            ch++;
            Q.push(maxSubTree(e.to));
        }
    }
    if(ch<2)return 1;
    else
    {
        int tmp=1;
        tmp+=Q.top();
        Q.pop();
        tmp+=Q.top();
        Q.pop();
        return tmp;
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("p2.out","w",stdout);
    int T;
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        cin>>N;
        ans=0;
        edges.clear();
        for(int i=0;i<=N;i++)G[i].clear();
        for(int i=0;i<N-1;i++)
        {
            int x,y;
            cin>>x>>y;
            edges.push_back((edge){x,y});
            G[x].push_back(edges.size()-1);
            edges.push_back((edge){y,x});
            G[y].push_back(edges.size()-1);
        }
        memset(vis,0,sizeof(vis));
        for(c=1;c<=N;c++)
        {
            int tmp=maxSubTree(c);
            ans=max(ans,tmp);
            //cout<<tmp<<endl;
        }
        cout<<"Case #"<<kase<<": "<<N-ans<<endl;
    }
}