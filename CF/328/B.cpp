#include<iostream>
#include<queue>
#include<stack>
#include <stdio.h>
#include<string.h>
#define mod 1000000007

using namespace std;

int main()
{
    long long int ans,x1,x2;
    int n;
    while(scanf("%d",&n)==1)
    {
        x1=1;x2=1;
        for(int i=0;i<n;i++)
        {
            x1=(x1*27)%mod;
            x2=(x2*7)%mod;
        }
        cout<<x1-x2+(x1>x2 ? 0 : mod)<<endl;
    }
    return 0;
}