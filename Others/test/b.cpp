#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#define LL long long int
#define MAXN 100005

using namespace std;

struct query
{
    int l,r;
    LL v;
};

int T,N,M,Q;
int F[MAXN];
int ANS[MAXN];
query QQ[MAXN];
vector<int> PEOPLE;
vector<int> FARM[MAXN];
LL G[MAXN];
LL BIT[MAXN];

int lowbit(int x){return x&(-x);}
void bit_add(int pos,LL v)
{
    while(pos<=M)
    {
        BIT[pos]+=v;
        pos+=lowbit(pos);
    }
}
LL bit_sum(int pos)
{
    LL res=0;
    while(pos)
    {
        res+=BIT[pos];
        pos-=lowbit(pos);
    }
    return res;
}

void totBS(int l,int r,vector<int>& people)
{
    if(people.size()==0)return;
    if(l==r)
    {
        for(int i=0;i<people.size();i++)ANS[people[i]]=l;
        return ;
    }
    int mid=(l+r)/2;

    //do things on BIT
    for(int i=l;i<=mid;i++)
    {
        bit_add(QQ[i].l,QQ[i].v);
        bit_add(QQ[i].r+1,-QQ[i].v);
    }

    //splitting
    vector<int> ok,notok;
    for(int i=0;i<people.size();i++)
    {
        LL c=0;
        int p=people[i];
        for(int j=0;j<FARM[p].size();j++)
        {
            c=max(c,bit_sum(FARM[p][j]));
        }
        if(G[p]<=c)
        {
            ok.push_back(p);
        }
        else
        {
            notok.push_back(p);
            G[p]-=c;
        }
    }

    //undo the things on BIT
    for(int i=l;i<=mid;i++)
    {
        bit_add(QQ[i].l,-QQ[i].v);
        bit_add(QQ[i].r+1,QQ[i].v);
    }
    vector<int>().swap(people);
    totBS(l,mid,ok);
    totBS(mid+1,r,notok);
}

int main()
{
    QQ[0]=(query){1,1,0};
    scanf("%d",&T);
    while(T--)
    {
        PEOPLE.clear();
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)scanf("%lld",G+i),PEOPLE.push_back(i),FARM[i].clear();
        for(int i=1;i<=M;i++)scanf("%d",F+i),FARM[F[i]].push_back(i),BIT[i]=0;
        BIT[M+1]=0;
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++)
        {
            scanf("%d%d%lld",&QQ[i].l,&QQ[i].r,&QQ[i].v);
        }
        totBS(0,Q+1,PEOPLE);
        for(int i=1;i<=N;i++)
        {
            if(i!=1)printf(" ");
            printf("%d",ANS[i]==Q+1 ? -1 : ANS[i]);
        }
        puts("");
    }
    return 0;
}
