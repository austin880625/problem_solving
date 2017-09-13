#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 100005

using namespace std;

struct KMP_AUTO
{
    int f[MAXN];
    char s[MAXN];
    int state,len;
    void build_fail()
    {
        f[0]=-1;
        for(int i=1;i<len;i++)
        {
            int cur=f[i-1];
            while(cur!=-1&&s[cur+1]!=s[i])
            {
                cur=f[cur];
            }
            if(s[cur+1]==s[i])f[i]=cur+1;
            else f[i]=-1;
        }
        for(int i=0;i<len;i++)printf("%d ",f[i]);
        puts("");
    }
    KMP_AUTO(char *_s){len=strlen(_s);for(int i=0;i<=len;i++)s[i]=_s[i];build_fail();}
    void start_match(){state=0;}
    int enter(int pos,char c)
    {
        if(c==s[state])
        {
            state++;
            if(len==state)return pos-state+1;
            return -2;
        }
        else
        {
            state=f[state];
            if(state==-1)return -1;
            return 0;
        }
    }
};

char S[MAXN];
char T[MAXN];

void KMP(char *s,char *t)
{
    int n=strlen(s);
    KMP_AUTO A(t);
    A.start_match();
    for(int i=0;i<n;i++)
    {
        int match=A.enter(i,s[i]);
        //printf("%d\n",match);
        while(!match)match=A.enter(i,s[i]);
        if(match<=-1)continue;
        else printf("%d ",i);
    }
    puts("");
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",S);
        KMP_AUTO X(S);
        int r=X.len%(X.len-X.f[X.len-1]-1);
        printf("%d\n",r ? 1 : X.len/(X.len-X.f[X.len-1]-1));
    }
    return 0;
}
