#include <iostream>
#include <stdio.h>
#define MAXN 100005
#define LL long long int
using namespace std;
LL S[MAXN];
LL A[MAXN];
int Left[MAXN];
int Right[MAXN];
int N;

struct Node
{
    LL h;
    int pos;
};
struct DQ
{
    Node x[MAXN];
    int fr,rr;
    void clear(){rr=-1,fr=0;}
    void push_back(int _p,int _v){x[++rr]=(Node){_v,_p};}
    void pop_back(){rr--;}
    void pop_fr(){fr++;}
    Node back(){return x[rr];}
    Node front(){return x[fr];}
    bool empty(){return rr<fr;}
};
DQ Q;
int main()
{
    int t=0;
    while(scanf("%d",&N)==1)
    {
        if(t++)puts("");
        Q.clear();
        S[0]=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%lld",&A[i]);
            S[i]=S[i-1]+A[i];
        }
        Q.push_back(0,-1);
        for(int i=1;i<=N;i++)
        {
            while(A[i]<=Q.back().h)Q.pop_back();
            Left[i]=Q.back().pos;
            Q.push_back(i,A[i]);
        }
        Q.clear();
        Q.push_back(N+1,-1);
        for(int i=N;i>=1;i--)
        {
            while(A[i]<=Q.back().h)Q.pop_back();
            Right[i]=Q.back().pos;
            Q.push_back(i,A[i]);
        }
        Q.clear();
        for(int i=1;i<=N;i++)Right[i]--;
        LL ans=0;
        int ansl=1,ansr=1;
        for(int i=1;i<=N;i++)
        {
            if((S[Right[i]]-S[Left[i]])*A[i]>ans)
            {
                ans=(S[Right[i]]-S[Left[i]])*A[i];
                ansr=Right[i],ansl=Left[i]+1;
            }
        }
        printf("%lld\n%d %d\n",ans,ansl,ansr);
    }
    return 0;
}
