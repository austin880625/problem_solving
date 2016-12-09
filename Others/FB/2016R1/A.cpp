#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 100020

using namespace std;

int T;
int N;
int D[MAXN];
int C1[121];

int Get(int i,int cnt)
{
    C1[i]--;
    if(!cnt)return 0;
    for(int j=1;j<=10;j++)
    {
        if(C1[i+j])return Get(i+j,cnt-1);
    }
    printf("%d ",i+11);
    C1[i+11]++;
    return 1+Get(i+11,cnt-1);
}

int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0;i<121;i++)C1[i]=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&D[i]);
            //printf("%d ",D[i]);
            C1[D[i]]++;
        }
        D[N]=1000;
        //puts("");
        int ans=0;
        int cnt=1;
        for(int i=1;i<=N;i++)
        {
            //if(i==N&&cnt==1)continue;
            if(D[i]-D[i-1]>0&&D[i]-D[i-1]<=10)cnt++;
            else if(D[i]-D[i-1]<=0)
            {
                ans+=4-cnt;
                cnt=1;
            }
            else
            {
                int q=(D[i]-D[i-1])/10;
                if((D[i]-D[i-1])%10)q++;
                int d=min(4-cnt,q-1);
                ans+=d;
                if(cnt+d<4)i++;
                cnt=1;
            }
            if(cnt==4)cnt=1,i++;
        }
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
