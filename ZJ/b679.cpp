#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
unsigned long long int N;
int main()
{
    while(scanf("%llu",&N)==1)
    {
        unsigned long long int l=0LLU,r=1LLU<<31;
        while(l<r)
        {
            unsigned long long int mid=(l+r)/2LLU;
            unsigned long long int m=mid+1LLU;
            if(!(mid&1LLU))swap(m,mid);
            if(mid*(m/2LLU)<N)
            {
                l=min(m,mid)+1LLU;
            }
            else r=min(m,mid);
        }
        printf("%llu\n",l);
    }
}
