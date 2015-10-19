#include <stdio.h>
#include<iostream>

using namespace std;

int TestCase;

int maxt=20;
int maxn=100000;
int maxm=100000;

int rand()
{
    static int x=20150537;
    return x=x*0xdefaced+1;
}
int mabs(int x)
{
    return x>0 ? x : -x;
}

int main()
{
    cin>>TestCase;
    for(int tc=0;tc<TestCase;tc++)
    {
        int N=mabs(rand())%maxn;
        int M=mabs(rand())%maxm;
        int T=mabs(rand())%maxt;
        printf("%d\n",N);
        for(int i=0;i<N;i++)
        {
            printf("%d ",rand()%maxn);
        }
        cout<<endl;
        for(int i=0;i<M;i++)
        {

        }
    }
}
