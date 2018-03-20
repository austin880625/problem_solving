#include <stdio.h>
#include<iostream>

using namespace std;

int TestCase;

int maxt=1000000;
int maxn=1000000000;;

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
        //int N=mabs(rand())%maxn;
        int T=mabs(rand())%maxt;
        printf("%d ",T);
        for(int i=0;i<T;i++)
        {
            printf("%d ",rand()%maxn);
        }
        cout<<endl;
    }
}
