#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define LL long long

using namespace std;

int N;
int L,R;
int A[2][100005];
LL S[100005];

struct inter
{
    int l,r;
    inter(int _l,int _r){l=_l,r=_r;}
    bool operator <(const inter &rhs)const{
        if(S[r]-S[l-1]>S[rhs.r]-S[rhs.l-1])return true;
        if(S[r]-S[l-1]<S[rhs.r]-S[rhs.l-1])return false;
        if(r>rhs.r)return true;
        if(r<rhs.r)return false;
        return l>rhs.l;
    }
    bool operator ==(const inter &rhs)const{
        return r==rhs.r&&l==rhs.l;
    }
};
set<int> D;
set<inter> I;

int main()
{
    while(scanf("%d",&N)==1)
    {
        I.clear();
        D.clear();
        S[0]=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&A[0][i]);
            S[i]=S[i-1]+A[0][i];
        }
        for(int i=1;i<=N;i++)scanf("%d",&A[1][i]);

        I.insert(inter(1,N));
        D.insert(0);D.insert(N+1);
        for(int i=1;i<=N;i++)
        {
            set<int>::iterator R=D.upper_bound(A[1][i]);
            set<int>::iterator L=prev(R);
            //printf("interval to be splitted: %d %d\n",(*L),(*R));
            I.erase(inter((*L)+1,(*R)-1));
            I.insert(inter((*L)+1,A[1][i]-1));
            I.insert(inter(A[1][i]+1,(*R)-1));
            D.insert(A[1][i]);
            //printf("Size: %lu,List of intervals:\n",I.size());
            //for(set<inter>::iterator it=I.begin();it!=I.end();it++)printf("%d %d\n",(*it).l,(*it).r);
            printf("%I64d\n",S[(*I.begin()).r]-S[(*I.begin()).l-1]);
        }
    }
    return 0;
}
