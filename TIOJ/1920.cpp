#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define MAXN 10005

using namespace std;

int N,Q;
int ch[MAXN*32][2];
int pos[MAXN*32];
int sz[MAXN*32];
int nodeid=1;
int A[MAXN];
int S[MAXN];

struct node
{
    int v,id;
    bool operator <(const node &r)const{
        return v<r.v;
    }
};

vector<int> POS[MAXN*32];

int L,R,V;

void getint(int &x)
{
    char c=0;x=0;
    while(c>'9'||c<'0')c=getchar();
    while(c<='9'&&c>='0')
    {
        x*=10;x+=(c-'0');
        c=getchar();
    }
}

void insert(int x)
{
    int now=0;
    //cout<<x<<" "<<S[x]<<endl;
    for(int i=30;i>=0;i--)
    {
        //cout<<now<<" "<<((S[x]>>i)&1)<<endl;
        if(!ch[now][(S[x]>>i)&1])ch[now][(S[x]>>i)&1]=nodeid,now=nodeid++,sz[now]++,POS[now].push_back(x);
        else now=ch[now][(S[x]>>i)&1],sz[now]++,POS[now].push_back(x);
    }
    //puts("");
    pos[now]=x;
}

int query(int v)
{
    int now=0,res=0;
    for(int i=30;i>=0;i--)
    {
        //cout<<now<<" "<<((v>>i)&1)<<" "<<ch[now][((v>>i)&1)]<<" "<<ch[now][1-((v>>i)&1)]<<endl;
        int better=ch[now][1-((v>>i)&1)];
/*
        if(i==0)
        {
            cout<<"the size "<<POS[better].size()<<" "<<sz[better]<<endl;
            for(set<int>::iterator it=POS[better].begin();it!=POS[better].end();it++)cout<<(*it)<<" ";
            puts("");
        }
*/
        //if(i&&better!=0)assert(POS[better].size());
        vector<int>::iterator itl=lower_bound(POS[better].begin(),POS[better].end(),L);
        if(better!=0&&itl!=POS[better].end()&&(*itl)<R)
        {
            now=better;
            res^=(1<<i);
        }
        else
        {
            //assert(sz[ch[now][(v>>i)&1]]>0);
            now=ch[now][(v>>i)&1];
        }
    }
  //  cout<<"finallty at node "<<now<<endl;
  //  cout<<pos[now]<<endl;
    return S[pos[now]]^S[R]^v^S[R];
    //return res;
}

int main()
{
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++)getint(A[i]);
    S[N]=0;
    for(int i=N-1;i>=0;i--)S[i]=S[i+1]^A[i];
    for(int i=0;i<N;i++)insert(i);
    //assert(0);
    for(int i=0;i<Q;i++)
    {
        //getchar();
        getint(L);getint(R);getint(V);
        V^=S[R];
        printf("%d\n",query(V));
    }
    return 0;
}
