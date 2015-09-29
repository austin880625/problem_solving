#include <stdio.h>
#include<iostream>

using namespace std;

long long int N;

int main()
{
    while(scanf("%lld",&N)!=EOF)
    {
        printf("%lld\n",3*(N*N+2*N-5)/2);
    }
}