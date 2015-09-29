#include <stdio.h>
#include<iostream>

using namespace std;

int TestCase;

int maxt=1000;
int maxn=30;

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
        int T=mabs(rand())%maxt;
        int w=mabs(rand())%10;
        printf("%d %d\n",T,w);
        printf("%d\n",N);
        for(int i=0;i<N;i++)
        {
            printf("%d %d\n",mabs(rand()%T),mabs(rand()%100));
        }
        cout<<endl;
    }
}
