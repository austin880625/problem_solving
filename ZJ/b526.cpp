#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d",&n)==1)
    {
        priority_queue<int> q;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            q.push(l-1);
            q.push(r);
        }
        int s=-1;
        while(!q.empty())
        {
            int p=q.top();q.pop();
            n+=p*s;
            s=-s;
        }
        cout<<n<<endl;
    }
    
    return 0;
}