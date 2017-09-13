#include<iostream>
#include<stdio.h>
#define MAXN 100000
#define MOD 1000000007
using namespace std;
int n,k;
int A[MAXN],B[MAXN];
int sz;
int checkseg(int x)
{
    int res=sz/A[x];
    if(!(sz%A[x]))res--;
    res++;
    int p=(B[x]*((sz)/10))/A[x];
    if((B[x]*((sz)/10))%A[x])p++;
    int q=((B[x]+1)*((sz)/10))/A[x];
    if(!(((B[x]+1)*((sz)/10))%A[x]))q--;
    //printf("%d ",res);
    return res-(q-p+1);
}

int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        int q=n/k;
        for(int i=0;i<q;i++)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d",&B[i]);
        }
        sz=1;
        for(int i=0;i<k;i++)sz*=10;
        unsigned long long int ans=1;
        for(int i=0;i<q;i++){ans*=checkseg(i);ans%=MOD;}
        cout<<ans<<endl;
    }
    return 0;
}
