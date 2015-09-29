#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

unsigned long long int myabs(long long int a){return (a>0 ? a : -a) ; }

int main()
{
    int n;
    long long int A;
    long long int S[1000005];
    long long int M;
    while(cin>>n)
    {
        S[0]=0;
        for(int i=1;i<=n;i++)
        {
           cin>>A;
           S[i]=S[i-1]+A;
        }
        M=S[n]/n;
        long long int xn=0;
        unsigned long long ans=0;
        for(int i=1;i<=n;i++)
        {
            S[i]=i*M-S[i];
        }
        sort(S+1,S+1+n);
        xn=S[n/2+1];
        for(int i=1;i<=n;i++){unsigned long long int t=myabs(xn-S[i]);ans+=t;}
        cout<<ans<<endl;
    }
    return 0;
}
