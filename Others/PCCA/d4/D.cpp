#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#define MAXN 50005

using namespace std;

struct query
{
    int id,block,l,r;
    bool operator <(const query &x)const{
        return block==x.block ? r<x.r : block<x.block;
    }
};

int N,Q;
vector<query> q;
set<int> S;
int A[MAXN];
int ans[MAXN];

void add(int d,int pos)
{
    S.insert(A[pos+d]);
}
void sub(int pos)
{
    set<int>::iterator it=S.find(A[pos]);
    if(it!=S.end())
        S.erase(it);
}

int main()
{
    while(scanf("%d%d",&N,&Q)==2)
    {
        int lim=sqrt(N);
        q.clear();
        S.clear();
        for(int i=1;i<=N;i++)
        {
            scanf("%d",A+i);
        }
        for(int i=0,l,r;i<Q;i++)
        {
            scanf("%d%d",&l,&r);
            q.push_back((query){i,l/lim,l,r});
        }
        sort(q.begin(),q.end());
        for(int i=0,l=1,r=0;i<Q;i++)
        {
            while(l<q[i].l)sub(l++);
            while(l>q[i].l)add(-1,l),l--;
            while(r<q[i].r)add(1,r),r++;
            while(r>q[i].r)sub(r--);
            ans[q[i].id]=(*S.rbegin())-(*S.begin());
        }
        for(int i=0;i<Q;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
