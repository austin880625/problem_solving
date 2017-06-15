#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int T;
char s[1005];
int K;

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%s %d",s,&K);
        int ans=0,len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='-')
            {
                if(i+K>len){ans=-1;break;}
                ans++;
                for(int j=i;j<i+K;j++)s[j]=(s[j]=='+' ? '-' : '+');
            }
        }
        printf("Case #%d: ",kase);
        if(ans==-1)printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
