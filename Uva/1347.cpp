#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

struct point
{
    double x,y;
};

const int MAX_N=10005;
point P[MAX_N];
double dp[MAX_N][MAX_N];

double dis(int i,int j)
{
    double x=P[i].x-P[j].x;
    double y=P[i].y-P[j].y;
    return sqrt(x*x+y*y);
}

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>P[i].x>>P[i].y;
        }
        dp[n-1][n-1]=0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(i!=n-1)
                    dp[i][j]=min(dp[i+1][j]+dis(i+1,i),dp[i+1][i]+dis(j,i+1));
                else
                    dp[i][j]=dp[i][j+1]+dis(j,j+1);
            }
        }
        dp[0][0]=dp[1][0]+dis(1,0);
        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<dp[i][j]<<"\t";
            cout<<endl;
        }*/
        printf("%.2f\n",dp[0][0]);
    }
    return 0;
}
