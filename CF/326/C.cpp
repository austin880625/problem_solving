#include<iostream>
#include <stdio.h>
#include<math.h>
#include<queue>
using namespace std;

int w[1000005];
int cnt[1000005];
priority_queue<int,vector<int>,greater<int> > Q;
int main()
{
    int n,ans,maxw;
    while(scanf("%d",&n))
    {
        ans=maxw=0;
        for(int i=0;i<1000005;i++)
        {
            cnt[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            cnt[w[i]]++;
            maxw=max(maxw,w[i]);
            if(cnt[w[i]]==1)Q.push(w[i]);
        }
        while(!Q.empty())
        {
            int i=Q.top();Q.pop();
            if(cnt[i])
            {
                int t=1,p=0;
                while(cnt[i]>1){
                    t=1;
                    while(t<=cnt[i]){p++;t<<=1;}
                    p--;t>>=1;
                    cnt[i]-=t;
                    cnt[i+p]++;
                    if(cnt[i+p]==1)Q.push(i+p);
                    n=n-t+1;
                }
                if(cnt[i]){ans++;}
                if(n<=0)break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
