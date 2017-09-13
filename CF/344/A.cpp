#include <stdio.h>
#include <iostream>
#define MAXN 1005

using namespace std;

int N;
int A[2][MAXN];
int ORSUM[2][MAXN];

int main()
{
    while(scanf("%d",&N)==1)
    {
        A[0][0]=A[1][0]=0;
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d",A[i]+j);
                ORSUM[i][j]=ORSUM[i][j-1]|A[i][j];
            }
        }
        int ans=0;
        for(int l=1;l<=N;l++)
        {
            for(int r=l;r<=N;r++)
            {
                ans=max(ans,(ORSUM[0][r]^ORSUM[0][l-1])+(ORSUM[1][r]^ORSUM[1][l-1]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
