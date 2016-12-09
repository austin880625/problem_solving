#include <stdio.h>
#include <iostream>
#include <assert.h>

#define LL long long int

using namespace std;

LL N;
int max_div_cnt;
LL P[14]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
LL vis[204800];

void dfs(LL now,int div_cnt,int i)
{
    assert(now<=N);
    //if(i==11)cout<<now<<" "<<div_cnt<<endl;
    if(!vis[div_cnt]||vis[div_cnt]>now)
    {
        vis[div_cnt]=now;
    }
    max_div_cnt=max(max_div_cnt,div_cnt);
    if(now>2000000000)return ;
    for(LL k=1,j=P[i];now*j<=N;k++,j*=P[i])
    {
        dfs(now*j,div_cnt*(k+1),i+1);
    }
}

int main()
{
    while(scanf("%lld",&N)==1)
    {
        for(int i=0;i<204800;i++)vis[i]=0;
        max_div_cnt=0;
        dfs(1,1,0);
        printf("%lld\n",vis[max_div_cnt]);
    }
    return 0;
}
