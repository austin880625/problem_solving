//monotone queue,

#include <stdio.h>
#include<stack>
#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

struct Node
{
    int height,startpos,pos;
    Node(int H,int sp,int p):height(H),startpos(sp),pos(p){}


};

int XDD[205][205];
int N,M;

int main()
{

    while(scanf("%d %d",&M,&N)==2)
    {
        int ans=0,tempans;
        stack<Node> S;
        memset(XDD,0,sizeof(XDD));
        for(int i=0;i<M;i++)
        {
            S.push(Node(-1,-1,-1));
            tempans=0;
            for(int j=0;j<=N;j++)
            {
                if(j!=N)scanf("%d",&XDD[i][j]);
                if(j!=N&&i>0&&XDD[i][j])XDD[i][j]+=XDD[i-1][j];

                long long int A=0;
                if(j!=N)A=XDD[i][j];
                //cout<<i<<":";
                //cout<<"it's "<<S.top().height<<" and "<<x.height<<" now."<<endl;

                while(S.top().height>A)
                {
                    Node t=S.top();
                    //cout<<t.height<<" ";
                    //cout<<"("<<t.startpos<<","<<t.height<<")";
                    tempans=max(tempans,(j-t.startpos)*t.height);
                    S.pop();
                }
                if(j!=N)S.push(Node(A,S.top().pos+1,j));
                //cout<<endl;
            }
            ans=max(ans,tempans);
        }

        printf("%d\n",ans);
    }

    return 0;
}
