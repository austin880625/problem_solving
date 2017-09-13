#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100005

using namespace std;

int T,N;
int S[MAXN];
vector<int> p;
int cnt[MAXN];

void genprime()
{
    p.push_back(2);p.push_back(3);
    int x;
    for(int i=5;i<=100000;i+=2)
    {
        x=1;
        for(int j=0;j<p.size()&&p[j]*p[j]<=i;i++)
        {
            if(i%p[j]==0){x=0;break;}
        }
        if(x)p.push_back(i);
    }
}

int main()
{
    genprime();
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<MAXN;i++)cnt[i]=0;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",S+i);
            int tmp=S[i];
            for(int j=0;j<p.size()&&p[j]*p[j]<=S[i];j++)
            {
                if(tmp%p[j]==0){while(tmp%p[j]==0)tmp/=p[j];cnt[p[j]]++;}
                ans=max(ans,cnt[p[j]]);
            }
            //cout<<ans<<" ";
            int x=(tmp==1 ? 0 : 1);
            // cout<<tmp<<" ";
            for(int j=0;j<p.size()&&p[j]*p[j]<=tmp;j++)
            {
                if(tmp%p[j]==0){x=0;break;}
            }
            if(x){cnt[tmp]++;ans=max(ans,cnt[tmp]);}
            // cout<<ans<<endl;
        }
        printf("%d\n",ans==0 ? 1 : ans);
    }
    return 0;
}
