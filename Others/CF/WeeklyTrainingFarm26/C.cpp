#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
#include <assert.h>
#define poi pair<int,int>
using namespace std;

set<poi> S;
int ans;
char st[10];
char dir[4][2]={"N","E","S","W"};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs(int x,int y)
{
    ans++,S.insert(poi(x,y));
    for(int i=0;i<4;i++)
    {
        if(S.find( poi(x+dx[i],y+dy[i]))!=S.end() )continue;
        puts(dir[i]);
        fflush(stdout);
        scanf("%s",st);
        if(st[0]=='W')continue;
        dfs(x+dx[i],y+dy[i]);
        puts(dir[(i+2)%4]);
        fflush(stdout);
        scanf("%s",st);
        assert(st[0]=='O');
    }
}

int main()
{
    scanf("%s",st);
    S.clear();
    ans=0;
    dfs(0,0);
    printf("D %d\n",ans);
    fflush(stdout);
    return 0;
}
