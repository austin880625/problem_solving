#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int N,M;
int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        double ans=0.0;
        for(int i=1;i<N;i++)
        {
            double pos=(double)i/N * (N+M);
            ans+=fabs(pos-floor(pos+0.5))/(N+M);
        }
        printf("%.4lf\n",ans*10000);
    }

    return 0;
}
