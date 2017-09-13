#include <stdio.h>
#include <iostream>
#define MAXN 50005

using namespace std;

int C[MAXN];
int T,N;

void add(int pos,int v)
{
    while(pos<=N)
    {
        C[pos]+=v;
        pos+=pos&(-pos);
    }
}
int sum(int i)
{
    int res=0;
    while(i)
    {
        res+=C[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    while(scanf("%d",&T)==1)
    {
        for(int kase=1;kase<=T;kase++)
        {
            for(int i=0;i<MAXN;i++)C[i]=0;
            scanf("%d",&N);
            for(int i=1,a;i<=N;i++)
            {
                scanf("%d",&a);
                add(i,a);
            }
            char s[10];
            scanf("%s",s);
            int i,j;
            printf("Case %d:\n",kase);
            while(s[0]!='E')
            {
                if(s[0]=='A')scanf("%d%d",&i,&j),add(i,j);
                else if(s[0]=='S')scanf("%d%d",&i,&j),add(i,-j);
                else if(s[0]=='Q')scanf("%d%d",&i,&j),printf("%d\n",sum(j)-sum(i-1));
                scanf("%s",s);
            }
        }
    }
    return 0;
}
