#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
#define MAXN 1000005
#define LL long long int
#define INF 100000000000000005
using namespace std;

int N;
pair<int,int> P[MAXN];
set<pair<int,int> > S;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d%d",&P[i].first,&P[i].second);
    sort(P,P+N);
    LL ans=INF;
    int l=0;
    S.insert(pair<int,int>(P[0].second,P[0].first));
    for(int i=1;i<N;i++)
    {
        set<pair<int,int> >::iterator it1=S.lower_bound(pair<int,int>(P[i].second,P[i].first));
        set<pair<int,int> >::iterator it2=it1;
        for(int j=0;j<1;j++)
        {
            if(S.size()&&it1!=S.begin())it1--;
            if(it2!=S.end())it2++;
        }
        for(it1;it1!=it2;it1++)
        {
            if(it1==S.end())break;
            LL t=(LL)((*it1).second-P[i].first)*(LL)((*it1).second-P[i].first)+((LL)(*it1).first-(LL)P[i].second)*(LL)((*it1).first-P[i].second);
            ans=min(t,ans);
        }
        S.insert(pair<LL,LL>(P[i].second,P[i].first));
        while((LL)(P[i].first-P[l].first)*(LL)(P[i].second-P[l].second)>ans)S.erase(pair<int,int>(P[l].second,P[l].first)),l++;
    }
    printf("%lld\n",ans);

    return 0;
}
/*
10
4 5
6 8
12 547
45 80
512 65
78 324
49 15
67 124
752 32
159 67
*/
