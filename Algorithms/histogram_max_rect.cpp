#include <stdio.h>
#include<stack>
#include<iostream>
#include<math.h>

using namespace std;

struct Node
{
    long long int height;
    int startpos,pos;
    Node(long long int H,int sp,int p):height(H),startpos(sp),pos(p){}
    
};

long long int histogram[100005];
int N;

int main()
{
    while(scanf("%d",&N)==1&&N!=0)
    {
        for(int i=0;i<N;i++)scanf("%lld",&histogram[i]);
        
        long long int ans=0;
        stack<Node> S;
        S.push(Node(-1,-1,-1));
        for(int i=0;i<=N;i++)
        {
            long long int A=0;
            if(i!=N)A=histogram[i];
            
            //cout<<"it's "<<S.top().height<<" and "<<x.height<<" now."<<endl;
            while(S.top().height>A)
            {
                Node t=S.top();
                //cout<<t.height<<" ";
                //cout<<"("<<t.startpos<<","<<t.height<<","<<(i-t.startpos)*t.height<<") ";
                ans=max(ans,(i-t.startpos)*t.height);
                S.pop();
            }
            //cout<<endl;
            if(i!=N)S.push(Node(A,S.top().pos+1,i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}