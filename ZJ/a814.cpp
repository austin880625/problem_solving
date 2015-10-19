#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

int n,m,Q;
int T[1000005];
int used[1000005];
vector<int> V;

int test(int x)
{
    int upper;
    if(used[T[x]]==x)used[T[x]]=-1;
    for(upper=T[x]+1;used[upper]<x&&used[upper]!=-1;upper++){}
    //cout<<x<<" "<<upper<<endl;
    if(upper>m)return 0;
    used[upper]=x;
    T[x]=upper;
    
    int mini=1;
    for(int i=x+1;i<n;i++)
    {
        int t;
        for(t=mini;used[t]<i&&used[t]!=-1;t++){}
        //cout<<t<<endl;
        if(used[T[i]]==i)used[T[i]]=-1;
        T[i]=t;
        used[t]=i;
        mini=t;
    }
    return 1;
}

int main()
{
    scanf("%d",&Q);
    while(Q--)
    {
        memset(used,-1,sizeof(used));
        scanf("%d %d",&n,&m);
        int sp=n-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&T[i]);
            if(used[T[i]]==-1)used[T[i]]=i;
            else if(sp==n-1)sp=i;
        }
        //cout<<used[3]<<endl;
        for(int i=sp;i>=0;i--)
        {
            if(test(i))break;
        }
        for(int i=0;i<n;i++)printf("%d ",T[i]);
        printf("\n");
    }
}
