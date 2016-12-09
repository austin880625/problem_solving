#include <stdio.h>
#include <vector>
#define MAXN 1000005
#define MAXM 1000005


int N,M;
int op[MAXM];
bool started[MAXM];
std::vector<int> tags[MAXN];

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<=N;i++)tags[i].clear();
        for(int i=0;i<=M;i++)op[i]=started[i]=0;
        for(int i=0;i<M;i++)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            tags[x].push_back(i);
            tags[y+1].push_back(i);
            op[i]=k;
        }

        int v=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<tags[i].size();j++)
            {
                if(started[tags[i][j]])
                {
                    v-=op[tags[i][j]];
                }
                else
                {
                    v+=op[tags[i][j]];
                    started[tags[i][j]]=true;
                }
            }
            if(i!=1)printf(" ");
            printf("%d",v);
        }
        puts("");
    }
    return 0;
}
