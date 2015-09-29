#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Item
{
    int s,b;
    Item(int s,int b):s(s),b(b){}
    bool operator < (const Item &rhs)const
    {
        return s>rhs.s;
    }
};
int k;
int A[755][755];
int C[755];

void merge(int *S,int *T)
{
    priority_queue<Item> q;
    for(int i=0;i<k;i++)
    {
        int s=S[i]+T[0];
        q.push(Item(s,0));
    }
    
    for(int i=0;i<k;i++)
    {
        Item M=q.top();
        S[i]=M.s;
        q.pop();
        if(M.b+1<k)q.push(Item(M.s-T[M.b]+T[M.b+1],M.b+1));
    }
}

int main()
{
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&A[i][j]);
            }
            sort(A[i],A[i]+k);
        }
        for(int i=1;i<k;i++)
        {
            merge(A[0],A[i]);
        }
        printf("%d",A[0][0]);
        for(int i=1;i<k;i++)printf(" %d",A[0][i]);
        printf("\n");
    }
    return 0;
}
