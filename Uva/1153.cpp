#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#define MAXN 800005
using namespace std;
struct task
{
    int cost,deadline;
    bool operator < (const task &rhs)const{
        return cost < rhs.cost;
    }
}TASKS[MAXN];
bool cmp(task A,task B)
{
    return A.deadline<B.deadline;
}
priority_queue<task> pq;
int N,T;
int sum,ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        while(!pq.empty())pq.pop();
        ans=0;sum=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d %d",&TASKS[i].cost,&TASKS[i].deadline);
        }
        sort(TASKS,TASKS+N,cmp);
        for(int i=0;i<N;i++)
        {
            sum+=TASKS[i].cost;
            ans++;
            pq.push(TASKS[i]);
            if(sum>TASKS[i].deadline)
            {
                ans--;
                sum-=pq.top().cost;
                pq.pop();
            }
        }
        printf("%d\n",ans);
        if(T)puts("");
    }
    return 0;
}
