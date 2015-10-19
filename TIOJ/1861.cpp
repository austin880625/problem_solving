#include<iostream>
#include<queue>
#include<stdio.h>
#include<vector>

using namespace std;
int main()
{
    int n;
    long long ans;
    while(scanf("%d",&n)==1)
    {
        priority_queue<long long int,vector<long long int>,greater<long long int> > Q;
        ans=0;
        for(int i=0; i<n; i++)
        {
            static long long int t;
            scanf("%lld",&t);
            Q.push(t);
        }
        while(Q.size()>=2)
        {
            long long int t=Q.top();
            Q.pop();
            long long int mt=Q.top();
            Q.pop();
            //cout<<t<<" "<<mt<<endl;
            ans+=(t+mt);
            Q.push(t+mt);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
