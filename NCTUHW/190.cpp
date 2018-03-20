#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define LL long long int
#define pii pair<LL,int>

using namespace std;

vector<pii> I;
int N;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        I.clear();
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            LL a,b;
            scanf("%lld%lld",&a,&b);
            I.push_back(pii(a,1));
            I.push_back(pii(b+1,-1));
        }
        sort(I.begin(), I.end());
        int ans=0;
        for(int i=0,t=0;i<I.size();i++)
        {
            t+=I[i].second;
            ans=max(t,ans);
        }
        printf("%d\n",ans);
    }
}
