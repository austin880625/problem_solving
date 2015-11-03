#include<iostream>
#include<stdio.h>
#include<vector>
#define MAXN 1000005
#define ll long long int
#define INF 2147483646
using namespace std;
int BIT[MAXN];
int X[MAXN];
int C[MAXN];
int F[MAXN];
int N,M,A,B;
int T;
int lowbit(int x){return x&(-x);}
void add(int x,int v)
{
    while(x<=N)
    {
        BIT[x]+=v;
        x+=lowbit(x);
    }
}
int sufsum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=BIT[x];
        x-=lowbit(x);
    }
    return res;
}
int query(int k)
{
    int l=0,r=N;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(sufsum(mid)<k)l=mid+1;
        else r=mid;
    }
    return l;
}
struct Node{
    vector<int> list;
    Node(){list.clear();}
    void push(int v)
    {
        list.push_back(v);
    }
    int last(){return list[list.size()-1];}
};
vector<Node> LS;
int Nxt[MAXN];
int Prev[MAXN];

void print()
{
    for(int i=0;i<LS.size();i++){
        printf("%d : ",i);
        for(int j=0;j<LS[i].list.size();j++)printf("%d ",LS[i].list[j]);
        puts("");
    }
    puts("");
} 
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&N,&M,&X[0],&A,&B);
        for(int i=0;i<=N;i++)BIT[i]=0;
        for(int i=1;i<=N;i++)
        {
            add(i,1);
            X[i]=((ll)A*(ll)X[i-1]+(ll)B)%(ll)M;
            C[i]=(((ll)X[i]+(ll)N-(ll)i)%((ll)N-i+1))+1;
        }
        F[0]=INF;
        LS.clear();
        LS.push_back(Node());
        int now=0;
        //cout<<LS.size();
        for(int i=1;i<=N;i++)
        {
            int x=query(C[i]);
            //int x=i;
            //cout<<x<<" ";
            if(x<F[i-1])LS[now].push(i);
            else {Prev[now]=now-1;Nxt[now]=now+1;LS.push_back(Node());LS[++now].push(i);}
            F[i]=x;
            add(x,-1);
        }

        int sz=LS.size();
        Nxt[now]=0;
        if(sz>1)Nxt[0]=1;
        Prev[0]=now;
        if(sz>1)Prev[now]=now-1;
        ll ans=0;
        int first=0;
        int cur=0;
        for(int i=1;i<=N;i++)
        {
            while(sz!=1&&F[LS[cur].last()]>F[LS[Nxt[cur]].list[0]]){
                cur=Nxt[cur];
            }
            ans+=(ll)i*(ll)LS[cur].last();
            LS[cur].list.pop_back();
            if(!LS[cur].list.size())
            {
                int nt=Nxt[cur],pt=Prev[cur];
                sz--;
                Nxt[pt]=nt;
                Prev[nt]=pt;
            }
            //cout<<sz<<endl;
            cur=Nxt[cur];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
