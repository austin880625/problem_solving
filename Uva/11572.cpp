#include<iostream>
#include<stdio.h>
#include<set>
#define INF 1000000000
using namespace std;
int T,N;
int ans;
int SF[1000005];
set<int> S;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        S.clear();
        ans=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&SF[i]);
        }
        int l=0;
        for(int i=0;i<N;i++)
        {
            while(S.find(SF[i])!=S.end())
            {
                S.erase(SF[l++]);
            }
            S.insert(SF[i]);
            ans=max(i-l+1,ans);
            //cout<<i<<" "<<ans<<endl;
        }
        printf("%d\n",ans);
    }
}
