#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct edge
{
    int from,to;
};

vector<int> G[30];
vector<edge> edges;
string graph;
int ch[30];
int used[30];
int S[10];
int sizeG;
int ans;
int ansW[10];

void dfs(int cur)
{
    if(cur==sizeG)
    {
        //for(int i=0;i<sizeG;i++)cout<<S[i];cout<<endl;
        int band=0;
        for(int i=0;i<sizeG;i++)
        {
            int f=S[i];
            for(int j=0;j<G[f].size();j++)
            {
                int t=edges[G[f][j]].to;int k=0;
                while(S[k]!=t)k++;
                band=max(band,(k-i>0 ? k-i : i-k));
            }
        }
        //cout<<band<<endl;
        if(ans>band)
        {
            ans=band;
            for(int i=0;i<sizeG;i++)ansW[i]=S[i];
        }
    }
    else
    {
    for(int i=0;i<30;i++)
    {
        if(ch[i])
        {
            if(!used[i])
            {
                used[i]=1;
                S[cur]=i;
 //               cout<<cur<<endl;
                dfs(cur+1);
                used[i]=0;
            }
        }
    }
    }
}

int main()
{
    while(cin>>graph)
    {
        if(graph[0]=='#')break;
        ans=10000;
        edges.clear();
        for(int i=0;i<30;i++){ch[i]=0;used[i]=0;G[i].clear();}
        for(int i=0;i<graph.length();i++)
        {
            int from,to;
            if(graph[i+1]==':'&&i!=graph.length()-1)
            {
                from=graph[i]-'A';
                ch[graph[i]-'A']=1;
            }
            else if(graph[i]!=';'&&graph[i]!=':')
            {
                to=graph[i]-'A';
                ch[graph[i]-'A']=1;
                edges.push_back((edge){from,to});
                G[from].push_back(edges.size()-1);
                edges.push_back((edge){to,from});
                G[to].push_back(edges.size()-1);
            }
        }
        sizeG=0;
        for(int i=0;i<30;i++)if(ch[i])sizeG++;
        //cout<<sizeG<<endl;
        dfs(0);
        for(int i=0;i<sizeG;i++)cout<<(char)('A'+ansW[i])<<" ";
        cout<<"-> "<<ans<<endl;
    }
    return 0;
}

