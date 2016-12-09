#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#define MAXN 2005
#define TT 60000

using namespace std;

int N;
int G[MAXN][MAXN];
map<int,int> M;
inline int ran(){static int x=713222;return x=x*0xdefaced+1;}

int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&G[i][j]);
            }
        }
        int Q;
        scanf("%d",&Q);
        int r1,r2,c1,c2;
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d%d%d",&r1,&r2,&c1,&c2);
            M.clear();
            int h=r2-r1+1,w=c2-c1+1;
            for(int i=0;i<TT;i++)
            {
                int r=r1+abs(ran())%h,c=c1+abs(ran())%w;
                if(M.find(G[r][c])==M.end())M[G[r][c]]=0;
                else M[G[r][c]]++;
            }
            int ans=-1;
            for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
            {
                if(it->second*2>TT-1000)
                {
                    int temp=0;
                    for(int i=r1;i<=r2;i++)
                    {
                        for(int j=c1;j<=c2;j++)if(G[i][j]==it->first)temp++;
                    }
                    if(temp*2>h*w){ans=it->first;break;}
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

/*
5
1 2 3 3 2
2 1 1 2 3
1 2 3 1 1
0 2 3 3 1
0 3 1 3 2
2
0 1 0 2
2 4 1 3
0
*/
