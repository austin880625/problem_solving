#include<iostream>
#include<stdio.h>
#include<stack>
#define INF 2147483648
using namespace std;

struct Node{
    long long G;
    int pos;
};

int main()
{
    int n;
    unsigned long long ans;
    stack<Node> S;
    S.push((Node){INF,-1});
    scanf("%d",&n);
    //{
        ans=0;
        for(int i=0;i<n-1;i++)
        {
            unsigned long long int g;
            scanf("%lld",&g);
            ans+=g*(n-1-i);
            while(!S.empty()&&g>S.top().G)
            {
                unsigned long long int In=S.top().pos,G=S.top().G;
                S.pop();
                ans+=(g-G)*(In-S.top().pos)*(n-i-1);//In-S.top().pos : 我只是要更新後面的，所以中間算過得都需要更新
            }
            S.push((Node){g,i});
        }
        printf("%lld\n",ans);
    //}
    return 0;
}