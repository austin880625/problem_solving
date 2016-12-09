#include <stdio.h>
#include <iostream>
#define MAXN 75

using namespace std;

struct BOOK
{
    int w,h;
    bool operator <(const BOOK &rhs)const{
        return h>rhs.h;
    }
};

int T,N;
BOOK B[MAXN];
int dp[MAXN][2500][2500];

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&BOOK[i].h,&BOOK[i].w);
            
        }
    }
    return 0;
}
