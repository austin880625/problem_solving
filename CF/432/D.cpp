#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 500005
#define LL long long int

using namespace std;

vector<LL> primes;
int cnt[MAXN*2];
int A[MAXN];
LL N,x,y;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    primes.push_back(2);
    for(LL i=3;i<=1000000;i+=2){
        int t=1;
        for(int j=0;j<primes.size()&&primes[j]*primes[j]<=i;j++){
            if(i%primes[j]==0){t=0;break;}
        }
        if(t)primes.push_back(i);
    }
    cout<<primes.size()<<endl;
    while(cin>>N>>x>>y){
        for(int i=0;i<MAXN*2;i++)cnt[i]=0;
        for(int i=0;i<N;i++)cin>>A[i],cnt[A[i]]++;

    }
    return 0;
}
