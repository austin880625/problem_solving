#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 105
using namespace std;

vector<int> G[MAXN];
int vis[MAXN];
int N;

int main()
{
    while(scanf("%d",&N)==1&&N){
        int u,v;
        while(scanf("%d",&u)){
            if(u==0)break;
            while(scanf("%d",&v)){
                if(v==0)break;
                G[u].push_back(v);
            }
        }
    }
    return 0;
}
