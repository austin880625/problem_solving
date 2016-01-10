#include <stdio.h>
#include <iostream>
#include <assert.h>

using namespace std;

int TestCase;

int rand()
{
    static int x=201511017;
    return x=x*0xdefaced+1;
}
int mabs(int x)
{
    return x>0 ? x : -x;
}
int ran(int l,int r)
{
    return l+mabs(rand()%(r-l+1));
}
int main()
{
    cin>>TestCase;
    //printf("%d\n",TestCase);
    for(int tc=0;tc<TestCase;tc++)
    {
        int N=ran(1,100);
        printf("%d\n",N);
        for(int i=0;i<N;i++)printf("%d ",ran(0,1000000));
        puts("");
    }
}
