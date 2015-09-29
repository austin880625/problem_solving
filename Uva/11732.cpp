#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>

using namespace std;

struct edge
{
    int from,to;
    char c;
};

vector<edge> edges;
vector<int> G[4000010];
int val[4000010];
int sz;
unsigned long long int ans;
vector<int> w;

int isinTrie(char c,int n)
{
    for(int i=0;i<G[n].size();i++)
    {
        if(edges[G[n][i]].c==c)return i;
    }
    return -1;
}

void insert(char *s)
{
    int cur=0;
    val[0]++;
    int len=strlen(s);
    for(int i=0;i<=len;i++)
    {
        int e=isinTrie(s[i],cur);
        if(e==-1)
        {
            edges.push_back((edge){cur,sz,s[i]});
            G[cur].push_back(edges.size()-1);
            e=G[cur].size()-1;
            sz++;
        }
        int past=val[cur];
        cur=edges[G[cur][e]].to;
        val[cur]++;
        int now=val[cur];
        ans+=(2*i+1)*(past-now);
    }
    if(val[cur]>1)ans+=2*(val[cur]-1)*(len+1);
}

int main()
{
    int N,kase=0;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)break;
        ans=0;
        sz=1;
        edges.clear();
        for(int i=0;i<N;i++)
        {
            char word[1005];
            scanf("%s",word);
            insert(word);
        }
        printf("Case %d: %lld\n",++kase,ans);

        for(int i=0;i<sz;i++){G[i].clear();val[i]=0;}
    }
    return 0;
}
