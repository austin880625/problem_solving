#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN
#define LL long long int

using namespace std;

LL N,K,T;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>N>>K>>T)
    {
        if(T>=K){
            if(T<=N)cout<<K;
            else cout<<K-(T-N);
        }
        else cout<<T<<endl;
        cout<<endl;
    }
    return 0;
}
