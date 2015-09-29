#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<vector>
using namespace std;

int color[1000005];
int state[1000005];
int cupper[5005];
int clower[5005];

int L,P;

int next(int x){return (x+1)%L;}
int prev(int x){return (x+L-1)%L;}

void coloring(int start)
{
    int s=start,c=1;
    while(s!=prev(s))
    {
        color[s]=c;
        s=next(s);
        if(state[s]<0)c++;
    }
    color[s]=c;
}

int isSelfLoop(int pos)
{
    int dir;
    if(color[clower[pos]]==color[next(clower[pos])])dir=1;
    else dir=-1;
    int s=(dir==1 ? next(clower[pos]) : prev(clower[pos]));
    while(s!=cupper[pos])
    {
        if(state[s]<0)return 0;
        if(dir==1)s=next(s);
        else s=prev(s);
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int kase=0;
    while(++kase<=T)
    {
        scanf("%d %d",&L,&P);
        memset(state,0,sizeof(state));
        memset(color,0,sizeof(color));

        for(int i=1;i<=P;i++)
        {
            scanf("%d %d",&cupper[i],&clower[i]);
            state[cupper[i]]=i;
            state[clower[i]]=-i;
        }

        coloring(clower[0]);
    }
    
    return 0;
}
