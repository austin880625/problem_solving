#include <stdio.h>
#include<iostream>

using namespace std;

int TestCase;

int maxt=20;
int maxn=1001;

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
        printf("%d %d ",N,T);
        for(int i=0;i<T;i++)
        {
            printf("%d ",mabs(rand()%N));
        }
        cout<<endl;
    }
}
