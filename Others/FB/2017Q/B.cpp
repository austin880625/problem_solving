#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T,N;
int w[200];

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",w+i);
        }
        sort(w,w+N);
        int ans=0,tmp=0;
        for(int i=N-1;i>=0;i--)
        {
            int q=50/w[i];
            if(50%w[i]==0)q--;
            tmp+=q;ans++;
            if(tmp-1>=i){ans--;break;}
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
