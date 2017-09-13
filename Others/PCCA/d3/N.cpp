#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int m,n;
int a[105];

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int c=0,ans=0;
        for(int i=0;i<n;i++)
        {

            if(c>=m)break;
            if(a[i]<0&&c<m)ans-=a[i],c++;
            if(a[i]>0)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
