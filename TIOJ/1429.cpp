#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define LL long long int
using namespace std;

int N;
int B;
//LL C[MAXN];
LL Le[MAXN];
LL M[MAXN];
int stamp[MAXN];
int post[MAXN];
vector<int> G[MAXN];
int dfs_clock;
LL ANS;
int L,R;

LL BIT[2][MAXN];

struct ninja
{
    int id;LL c;
    bool operator <(const ninja &x)const
    {
        return c<x.c;
    }
};

inline void add(LL v)
{
    int v2=v>0 ? 1 : -1;
    while(L<=N+1)
    {
        BIT[1][L]+=v;
        BIT[0][L]+=v2;
        L+=(L&(-L));
    }
}

ninja C[MAXN];

void dfs(int now,int fa)
{
    stamp[now]=++dfs_clock;
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(v==fa)continue;
        dfs(v,now);
    }
    post[now]=dfs_clock;
}

inline void query(LL &c ,LL &k)
{
    L--;
    while(L>0)
    {
        c-=BIT[1][L],k-=BIT[0][L];
        L-=(L&(-L));
    }
    while(R>0)
    {
        c+=BIT[1][R],k+=BIT[0][R];
        R-=(R&(-R));
    }
    //return res;
}
LL commited[MAXN];

void tot_bs(int s,int e,vector<int> &people)
{
    //cout<<"bisearching "<<s<<" "<<e<<endl;
    if(people.size()==0)return ;
    if(s==e)
    {
        if(s==0)return ;
        for(int i=0;i<people.size();i++)
        {
            int p=people[i];
            //L=stamp[p];R=post[p];
            //cout<<"updating answer: "<<people[i]<<" "<<L<<" "<<R<<" "<<query(T,1,N+1,0)<<endl;
            ANS=max(ANS,Le[p]*commited[p]);
            //cout<<"now answer is "<<ANS<<endl;
        }
        return ;
    }
    int mid=(s+e)/2;
    //set<int> added;
    //cout<<"doing operation :"<<endl;
    for(int i=s;i<=mid;i++)
    {
        L=stamp[C[i].id];
        add(C[i].c);
        //cout<<"added "<<C[i].c<<" on "<<stamp[C[i].id]<<endl;
        //added.insert(C[i].id);
    }
    vector<int> bao,maybao;
    for(int i=0;i<people.size();i++)
    {
        int p=people[i];
        L=stamp[p],R=post[p];
        LL c=0,k=0;
        //cout<<"checking "<<people[i]<<" on interval "<<L<<" "<<R<<" ";
        query(c,k);
        //cout<<q<<endl;
        if(c>M[p])
        {
            //cout<<"Ãz¤F"<<endl;
            bao.push_back(p);
            //added.insert(people[i]);
        }
        else maybao.push_back(p),M[p]-=c,commited[p]+=k;
    }
    for(int i=s;i<=mid;i++)
    {
        L=stamp[C[i].id];
        add(-C[i].c);
    }

    //vector<int>().swap(people);
    tot_bs(s,mid,bao);
    tot_bs(mid+1,e,maybao);
}

int main()
{
    scanf("%d%lld",&N,&M[0]);
    //int root=0;
    vector<int> people;
    people.reserve(N);
    for(int i=1;i<=N;i++)
    {
        M[i]=M[0];
        people.push_back(i);
        scanf("%d%lld%lld",&B,&C[i].c,Le+i);
        G[B].push_back(i);
        C[i].id=i;
    }
    ANS=0;
    dfs_clock=0;
    dfs(0,-1);
    sort(C+1,C+N+1);
    tot_bs(0,N+1,people);
    printf("%lld\n",ANS);
    return 0;
}
