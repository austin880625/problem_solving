#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define MAXN 1000000
#define pii pair<long long int,long long int>
#define LL long long int

using namespace std;

LL N,K;
set<LL> S;
pii C[MAXN];
LL T[MAXN];
#define si set<LL>::iterator

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>N>>K)
    {
        LL ans=0;
        for(int i=1;i<=N;i++)cin>>C[i].first,C[i].second=i,S.insert(K+i);
        sort(C+1,C+1+N);
        for(int i=N;i>=1;i--)
        {
            //cout<<C[i].second<<endl;
            si it=S.lower_bound(C[i].second);
            ans+=C[i].first*((*it)-C[i].second);
            T[C[i].second]=(*it);
            S.erase(it);
        }
        cout<<ans<<endl;
        for(int i=1;i<=N;i++)
        {
            if(i-1)cout<<" ";
            cout<<T[i];
        }
        cout<<endl;
    }
    return 0;
}
