#include<iostream>
#include<stdio.h>

using namespace std;
int N;
int a[500005];
int ans[500005];
int len;
int ANS;
int main()
{
    while(scanf("%d",&N)==1)
    {
        ANS=0;
        len=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        ans[0]=a[0];
        ans[N-1]=a[N-1];
        for(int i=1;i<N-1;i++)
        {
            if(a[i]==a[i-1])
            {
                ans[i]=a[i];
                len=0;
            }
            else
            {
                if(a[i]!=a[i+1])
                {
                    len++;
                    ans[i]=a[i]^(len&1);
                }
                else
                {
                    ans[i]=a[i];
                    len=0;
                }
            }
            if(len)ANS=max(ANS,len/2+1);
        }
        printf("%d\n",ANS);
        for(int i=0;i<N;i++)printf("%d ",ans[i]);
        puts("");

    }
}
