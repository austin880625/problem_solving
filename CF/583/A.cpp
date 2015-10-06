#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int T,N;
int r[2][100][100];
int h[10000];
int v[10000];
vector<int> done;

int main()
{
    while(scanf("%d",&N)==1)
    {
        memset(r,0,sizeof(r));
        done.clear();
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d %d",&h[i*N+j],&v[i*N+j]);
            }
        }
        
        for(int i=0;i<N*N;i++)
        {
            int row=h[i]-1,col=v[i]-1;
            //cout<<x<<" "<<y<<endl;
            if(!(r[0][row][col]||r[1][row][col]))
            {
                done.push_back(i);
                for(int j=0;j<N;j++)
                {
                    r[0][row][j]=r[1][j][col]=1;
                }
            }
        }
        for(int i:done)
        {
            printf("%d ",i+1);
        }
        printf("\n");
    }
    return 0;
}