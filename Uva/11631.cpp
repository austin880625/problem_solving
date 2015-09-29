#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N=200005;
int m,n;

struct edge
{
    int from,to,w;
    bool operator < (const edge& rhs)const
    {
        return w<rhs.w;
    }
};
vector<edge> edges;
vector<int> G[MAX_N];
int P[MAX_N];
int MST;

int find(int x){return x==P[x] ? x : P[x]=find(P[x]);}

void Kruskal()
{
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++)
    {
        edge &e=edges[i];
        int u=e.from,v=e.to,w=e.w;
        int x=find(u),y=find(v);
        if(x-y)
        {
            P[x]=y;
            MST+=w;
        }
    }
}

int main()
{
    while(cin>>m>>n)
    {
        int S=0;
        if(m==n&&m==0)break;
        MST=0;
        edges.clear();
        for(int i=0;i<m;i++){G[i].clear();P[i]=i;}
        for(int i=0;i<n;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            S+=w;
            edges.push_back((edge){u,v,w});
            G[u].push_back(edges.size()-1);
        }
        Kruskal();
        cout<<S-MST<<endl;
    }
}
