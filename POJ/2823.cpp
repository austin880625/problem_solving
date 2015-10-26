#include<iostream>
#include<stdio.h>
#include<vector>
#define MAXN 1000005
using namespace std;
int n,k;
int a[MAXN];

struct DQ
{
    int fr,rr;
    int s[MAXN];
    void clear(){fr=0;rr=-1;}
    void push(int v){s[++rr]=v;}
    void popfr(){fr++;}
    void popbc(){rr--;}
    int front(){return s[fr];}
    int back(){return s[rr];}
    int empty(){return rr<fr;}
};
DQ M;
int main()
{
    while(scanf("%d %d",&n,&k)!=-1)
    {
        M.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            while(!M.empty()&&a[i]<a[M.back()])M.popbc();
            M.push(i);
            if(i>=k-1)
            {
                while(!M.empty()&&M.front()<i-k+1)M.popfr();
                printf("%d ",a[M.front()]);
            }
        }
        puts("");
        M.clear();
        for(int i=0;i<n;i++)
        {
            while(!M.empty()&&a[i]>a[M.back()])M.popbc();
            M.push(i);
            if(i>=k-1)
            {
                while(!M.empty()&&M.front()<i-k+1)M.popfr();
                printf("%d ",a[M.front()]);
            }
        }
        puts("");
    }
    return 0;
}
/*
1 1 1
10 2
10 -10 10 -10 4 -6 7 -4 9 -7
*/
