#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

#define maxn 400001

int d[maxn];
int child[maxn][26];
int val[maxn];
char word[maxn];
    int sz;
    void init(){sz=1;memset(child[0],0,sizeof(child[0]));}
    int idx(char c){return c-'a';}

    void insert(char *s)
    {
        int cur=0;
        for(int i=0;s[i]!='\0';i++)
        {
            int t=idx(s[i]);
            if(!child[cur][t])
            {
                child[cur][t]=sz;
                val[sz]=0;
                memset(child[sz],0,sizeof(child[sz]));
                sz++;
            }
            cur=child[cur][t];
        }
        val[cur]=1;
    }
    void find(int start)
    {
        int cur=0,i;
        d[start]=0;
        for(i=start;word[i]!='\0';i++)
        {
            int t=idx(word[i]);
                //cout<<"crashed?"<<start<<" "<<i<<endl;
            if(!child[cur][t])return;
            cur=child[cur][t];
            if(val[cur])
            {
                d[start]+=d[i+1];
                d[start]%=20071027;
                //cout<<"found of "<<d[start]<<endl;
            }
        }
    }

int main()
{
    int S,kase=0;
    while(scanf("%s",word)!=EOF)
    {
        init();
        scanf("%d",&S);
        char s[101];
        for(int i=0;i<S;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        int len=strlen(word);
        d[len]=1;
        for(int i=len-1;i>=0;i--)
        {
            find(i);
        }
        printf("Case %d: %d\n",++kase,d[0]);
    }
    return 0;
}
