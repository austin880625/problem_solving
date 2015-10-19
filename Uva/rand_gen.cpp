#include <stdio.h>
#include<iostream>

using namespace std;

int TestCase;

int maxt=1000;
int maxn=200;

int rand()
{
    static int x=20151019;
    return x=x*0xdefaced+1;
}
int mabs(int x)
{
    return x>0 ? x : -x;
}

int main()
{
    //cin>>TestCase;
    //for(int tc=0;tc<TestCase;tc++)
    //{
        int N=maxn;
        int Q=40000;
        //int T=mabs(rand())%maxt;
        //int w=mabs(rand())%10;
        //printf("%d %d\n",T,w);
        printf("%d\n",N);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                printf("%d ",mabs(rand()%N));
            }
            puts("");
        }
        int com;
        cout<<Q<<endl;
        while(Q--)
        {
            com=(rand()^(rand()>>16));
            if(com&1)
            {
                printf("c ");
                printf("%d %d %d\n",mabs(rand()%N)+1,mabs(rand()%N)+1,mabs(rand()%100000));
            }
            else
            {
                printf("q ");
                int x1=mabs(rand()%N)+1,y1=mabs(rand()%N)+1,x2=mabs(rand()%N)+1,y2=mabs(rand()%N)+1;
                if(x1>x2)swap(x1,x2);
                if(y1>y2)swap(y1,y2);
                printf("%d %d %d %d\n",x1,y1,x2,y2);
            }
        }
        cout<<endl;
    //}
}
