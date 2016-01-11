#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define MAXN 2000
#define LL long long int

using namespace std;

int T,N;
LL X[MAXN],Y[MAXN];
multiset<LL> S[MAXN];
inline LL dis(int a,int b)
{
    return (X[b]-X[a])*(X[b]-X[a])+(Y[b]-Y[a])*(Y[b]-Y[a]);
}

int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)S[i].clear();
        int ans=0;
        for(int i=0;i<N;i++)
        {
            scanf("%lld%lld",&X[i],&Y[i]);
            for(int j=0;j<i;j++)
            {
                LL len=dis(j,i);
                //printf("%d %d dis is %lld\n",i,j,len);
                ans+=S[i].count(len);
                S[i].insert(len);
                ans+=S[j].count(len);
                S[j].insert(len);
            }
        }
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
