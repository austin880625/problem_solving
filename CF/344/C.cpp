#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#define MAXN 200005

using namespace std;

struct operation{
    int t,r;
    bool operator <=(const operation &x)const{
        return r<=x.r;
    }
};
operation STK[MAXN];
int top;

int N,M;
int A[MAXN];
int ANS[MAXN];

bool cmp1(int a,int b){return a>b;}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        top=-1;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0;i<M;i++)
        {
            int t,r;
            scanf("%d%d",&t,&r);
            operation op=(operation){t,r};
            while(top>=0&&STK[top]<=op)
            {
                top--;
            }
            STK[++top]=op;
        }
        sort(A,A+STK[0].r);
        int l=0,r=STK[0].r-1;
        int t=0,i;
        for(i=N-1;i>=STK[0].r;i--)
        {
            ANS[i]=A[i];
        }
        //printf("%d\n",i);
        assert(i==STK[0].r-1);
        while(t<=top)
        {
            assert(l<=r);
            //printf("%d %d %d %d\n",i,t,l,r);
            if(STK[t].t==1)ANS[i--]=A[r--];
            else ANS[i--]=A[l++];
            if(l>r||(t+1<=top&&i==STK[t+1].r-1))t++;
        }
        //assert(i==-1);
        for(i=0;i<N;i++)
        {
            if(i)printf(" ");
            printf("%d",ANS[i]);
        }
        puts("");
    }
}
