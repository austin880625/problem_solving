#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

#define LL long long int
#define MAXN 400005
#define MAXQ 400005
#define MOD 1000000007

using namespace std;

struct query
{
    int l,r,id,block;
    bool operator <(const query &rh)const
    {
        return block==rh.block ? r<rh.r : block<rh.block;
    }
};
void assert(bool con)
{
    int a=0;
    if(!con)
    {
        while(1)
        {
            a++;
        }
    }
}
LL cur_ans;
int N,Q;
vector<query> QUERIES;
LL A[MAXN];
int B[MAXN];
LL CNT[MAXN];
//int pos[MAXN]; //real pos of i
LL ANS[MAXN];
map<LL,int> M;

inline void add(int x)
{
    LL k=A[x];
    cur_ans=(cur_ans+(k*(2*CNT[B[x]]+1LL)))%MOD;
    CNT[B[x]]++;
}

inline void sub(int x)
{
    LL k=A[x];
    cur_ans=(cur_ans-(k*(2*CNT[B[x]]-1LL)))%MOD;
    while(cur_ans<0)cur_ans+=MOD;
    CNT[B[x]]--;
}

int main()
{
    scanf("%d%d",&N,&Q);
    int idx=0;
    for(int i=0;i<N;i++)
    {
        scanf("%lld",A+i);
        //cout<<A[i]<<endl;
        map<LL,int>::iterator it=M.find(A[i]);
        if(it==M.end())M[A[i]]=idx,B[i]=idx++;
        else B[i]=it->second;
        assert(idx<MAXN);
    }
    for(int i=0;i<idx;i++)CNT[i]=0;
    //for(int i=0;i<N;i++)cout<<B[i]<<" ";
    //puts("");
    int chunk=(int)sqrt(N)+1;
    QUERIES.reserve(Q);
    for(int i=0;i<Q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        QUERIES.push_back((query){l,r-1,i,l/chunk});
    }
    sort(QUERIES.begin(),QUERIES.end());
    int L=0,R=L-1;cur_ans=0;
    for(query q:QUERIES)
    {
        while(R<q.r)add(++R);
        //cout<<"r+"<<endl;
        while(R>q.r)sub(R--);
        //cout<<"r-"<<endl;
        while(L<q.l)sub(L++);
        while(L>q.l)add(--L);
        ANS[q.id]=cur_ans;
    }
    for(int i=0;i<Q;i++)
    {
        printf("%lld\n",ANS[i]);
    }
    return 0;
}
