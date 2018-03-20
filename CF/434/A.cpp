#include <stdio.h>
#include <iostream>
#include <math.h>
#define LL long long int

using namespace std;

int K;
LL N;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>N>>K)
    {
        int five=0,two=0;
        LL N0=N;
        while(N0%2==0)
            N0/=2,two++;
        while(N0%5==0)
            N0/=5,five++;
        int m=max(two,five),n=min(two,five);
        K-=n;
        int p=min(K,(m-n));
        K-=(m-n);
        LL b=(m==two ? 5 : 2);
        LL pp=1;
        for(int i=0;i<p;i++)pp*=b;
        cout<<N*pp;
        if(K>0)for(int i=0;i<K;i++)cout<<"0";cout<<endl;
    }
    return 0;
}
