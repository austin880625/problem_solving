#include<iostream>
#include<math.h>

using namespace std;

int prime[50000];
int len=0;

int isprime(int N)
{
    
}

int main()
{
    int N;
    prime[0]=2;
    while(cin>>N)
    {
        cout<<(isprime(N) ? "質數" : "非質數")<<endl;
    }
}
