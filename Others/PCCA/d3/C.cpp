#include <stdio.h>
#include <iostream>

using namespace std;

int M,N;
int main()
{
    while(scanf("%d%d",&M,&N)==2){
        if(M%2==0||N%2==0)printf("%d\n",N*M/2);
        else printf("%d\n",(N*M-1)/2);
    }
    return 0;
}
