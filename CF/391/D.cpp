#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAXN 100005
#define LL long long int

using namespace std;

int N,M;
vector<int> g[MAXN];
int group[MAXN*10];
int cnt[MAXN*10];
int gc;

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        gc=0;
        for(int i=0;i<N;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=0;j<x;j++)
            {
                int y;
                scanf("%d",&y);
                g[i].push_back(y);
                cnt[y]++;
            }
        }
    }
    return 0;
}
