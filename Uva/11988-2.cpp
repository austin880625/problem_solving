#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 100005
using namespace std;
int nxt[MAXN];
char s[MAXN];
int main()
{
    while(scanf("%s",s+1)!=EOF)
    {
        s[0]='0';
        int len=strlen(s);
        nxt[0]=0;
        int cur=0,End=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='[')
            {
                cur=0;
            }
            else if(s[i]==']')
            {
                cur=End;
            }
            else
            {
                int t=nxt[cur];
                nxt[cur]=i;
                cur=nxt[cur];
                nxt[cur]=t;
                while(nxt[End]!=0)End=nxt[End];
            }
        }
        cur=nxt[0];
        while(cur!=0)
        {
            printf("%c",s[cur]);
            cur=nxt[cur];
        }
        puts("");
    }
    return 0;
}
