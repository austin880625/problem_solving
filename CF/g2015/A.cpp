#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int N;
string o,M;
int mon[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int ans[2][35];
int main()
{
    for(int i=0;i<2;i++)for(int j=0;j<35;j++)ans[i][j]=-1;
    while(cin>>N)
    {
        cin>>o>>M;
        if(M[0]=='w')
        {
            N--;
            if(ans[0][N]!=-1){printf("%d\n",ans[0][N]);continue;}
            int k=4;
            ans[0][N]=0;
            for(int i=1;i<=365;i++)
            {
                if(k==N)ans[0][N]++;
                k=(k+1)%7;
            }
            if(k==N)ans[0][N]++;
            printf("%d\n",ans[0][N]);
        }
        else if(M[0]=='m')
        {
            if(ans[1][N]!=-1){printf("%d\n",ans[1][N]);continue;}
            ans[1][N]=0;
            for(int i=0;i<12;i++)if(N<=mon[i])ans[1][N]++;
            printf("%d\n",ans[1][N]);
        }
    }
    return 0;
}
