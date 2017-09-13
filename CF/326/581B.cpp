#include <stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int h[100005];
int main()
{
    int N;
    int maxh;
    while(scanf("%d",&N)!=EOF)
    {
        maxh=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&h[i]);
        }
        for(int i=N-1;i>=0;i--)
        {
            int t=h[i];
            h[i]=max(0 , maxh+1-h[i]);
            if(t>maxh){maxh=t;}
        }
        for(int i=0;i<N;i++)printf("%d ",h[i]);
        printf("\n");
    }
}