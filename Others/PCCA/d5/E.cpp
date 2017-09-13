#include <stdio.h>
#include <iostream>

using namespace std;

int n;
 f[5005];
int main()
{
    f[0]=0,f[1]=1;
    for(int i=2;i<5005;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while(scanf("%d",&n)==1)cout<<"The Fibonacci number for "<<n<<" is "<<f[n]<<endl;
    return 0;
}
