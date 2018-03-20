#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define LL long long int
#define MAXN 100005

using namespace std;

struct coin{
    char c;LL n;
};

int T,N;
coin C[MAXN];
char s[4];
stack<coin> head;
queue<coin> tail;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%s %lld",s,&C[i].n);
            C[i].c=s[0];
            tail.push(C[i]);
        }
        coin x;
        coin y=(coin){x.c,0};
        while(!tail.empty())
        {
            x=tail.front();tail.pop();
            if(!head.empty()&&head.top().c==x.c){y=head.top();head.pop();}
            else y.c=x.c,y.n=0;
            //cout<<x.c<<" "<<x.n<<" "<<y.c<<" "<<y.n;
            //if(!head.empty())cout<<" "<<head.top().c<<" "<<head.top().n;
            //cout<<endl;
            if(x.n+y.n>2LL)
            {
                tail.push((coin){x.c,(x.n+y.n)/3LL});
                if((x.n+y.n)%3LL)head.push((coin){x.c,(x.n+y.n)%3LL});
            }
            else
            {
                head.push((coin){x.c,(x.n+y.n)});
            }
        }
        LL ans=0;
        while(!head.empty())
        {
            ans+=head.top().n;
            head.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
