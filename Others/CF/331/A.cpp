#include<iostream>
#include<stdio.h>

using namespace std;
int n,m;
int ans;
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        ans=0;
        int l,r;
        for(int i=0;i<n;i++)
        {
            for(int i=0;i<m;i++)
            {
                scanf("%d %d",&l,&r);
                if(l||r)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
