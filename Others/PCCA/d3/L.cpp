#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string B[15];
int n,m;
int c[15][15][2];

int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)c[i][j][0]=c[i][j][1]=0;
        for(int i=0;i<n;i++)
        {
            cin>>B[i];
            for(int j=0;j<m;j++)
            {
                if(B[i][j]=='S')
                {
                    for(int k=0;k<m;k++)c[i][k][0]++;
                    for(int k=0;k<n;k++)c[k][j][1]++;
                }
            }
        }
        int ans=n*m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)if(c[i][j][0]&&c[i][j][1])ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
