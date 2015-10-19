#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int TestCase;

int maxm=16;
int maxn=15;

/*int rand()
{
    static int x=20150537;
    return x=x*0xdefaced+1;
}*/
int mabs(int x)
{
    return x>0 ? x : -x;
}

int main()
{
    cin>>TestCase;
    srand(time(NULL));
    cout<<TestCase<<endl;
    for(int tc=0;tc<TestCase;tc++)
    {
        int N=mabs(rand())%maxn+1;
        int M=mabs(rand())%(maxm-N)+N;
        printf("%d %d\n",N,M);
        for(int i=0;i<N;i++)
        {
            printf("%d ",mabs(rand()%N+1));
        }
        printf("\n");
    }
        
}
