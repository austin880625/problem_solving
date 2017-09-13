#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN
#define LL long long int

using namespace std;

LL N,K;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>N>>K)
    {
        if(K==0||K==N)
        {
            cout<<"0 0"<<endl;continue;
        }
        cout<<"1 ";
        if(3*K<=N){cout<<2*K;}
        else cout<<2*K-(3*K-N);
        cout<<endl;
    }
    return 0;
}
