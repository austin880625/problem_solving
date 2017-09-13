#include <stdio.h>
#include <iostream>

using namespace std;

int MAT[25][25];
int N,M;

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%d",&MAT[i][j]);
            }
        }
        
    }
    return 0;
}
