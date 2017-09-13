#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 100005

using namespace std;
int N,M;
int f[MAXN],b[MAXN],pos[MAXN];
int a[MAXN];
vector<int> cnt[MAXN];
vector<int> cnt2[MAXN];
int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<=N;i++){pos[i]=0;cnt[i].clear();cnt2[i].clear();}
        for(int i=0;i<N;i++)
        {
            scanf("%d",&f[i]);
            cnt[f[i]].push_back(i);
        }
        int ans=1,cur=0;
        for(int i=0;i<M;i++)
        {
            scanf("%d",&b[i]);
            cnt2[b[i]].push_back(i);
        }
        for(int i=0;i<M;i++)
        {
            if(cnt[b[i]].size()==0||cnt[b[i]].size()<cnt2[b[i]].size()){ans=0;break;}
            if(cnt[b[i]].size()>1){ans=2;}
            a[cur++]=cnt[b[i]][pos[b[i]]++];
        }

        if(ans==1)
        {
            printf("Possible\n");
            for(int i=0;i<M;i++)printf("%d ",a[i]+1);
        }
        else if(ans==0)printf("Impossible");
        else printf("Ambiguity");
        puts("");
    }
    return 0;
}
