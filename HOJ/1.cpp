#include <iostream>
#include <stdio.h>

using namespace std;

int N;

int main()
{
    while(scanf("%d",&N)==1)
    {
        int a=N/3;
        int ans=2147483647;
        if(N%5==0)ans=min(ans,N/5);
        for(int i=0;i<=a;i++)
        {
            if(N==3*i)ans=min(ans,i);
            if((N-3*i)%5==0)ans=min(ans,i+(N-3*i)/5);
        }
        if(ans==2147483647)printf("This is Kongming's Trap!!!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
