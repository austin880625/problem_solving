#include <iostream>
#include <stdio.h>

#define MAXN 1005

using namespace std;

int T,N;
char S[2][MAXN];

int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<2;i++)scanf("%s",S[i]);
        int ans1=0,ans2=0,ans=0;
        int now=0,len=0;
        for(int i=0;i<2;i++)
        {
            now=0,len=0;
            while(now<N)
            {
                while(S[i][now]=='.'&&now<N)len++,now++;
                if(len==1&&S[i^1][now-1]!='X')
                {
                    ans++;
                    S[i][now-1]='*';
                    for(int j=0;now-1+j<N&&S[i^1][now-1+j]!='X';j++)S[i^1][now-1+j]='*';
                    for(int j=0;now-1-j>=0&&S[i^1][now-1-j]!='X';j++)S[i^1][now-1-j]='*';
                }
                len=0,now++;
            }
        }
        for(int i=0;i<2;i++)
        {
            now=0,len=0;
            while(now<N)
            {
                while(S[i][now]!='X'&&now<N)
                {
                    if(S[i][now]=='.')len++;
                    now++;
                }
                if(len)ans++;
                len=0,now++;
            }
        }
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
