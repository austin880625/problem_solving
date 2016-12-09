#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define INF 2147483647

using namespace std;

int C,N;
int W[MAXN];
int posx[MAXN],posy[MAXN];
int totD[MAXN];
int totW[MAXN];
int dp[MAXN];

struct DEQ
{
    int fr,rr;
    int V[MAXN];
    void clear(){rr=-1;fr=0;}
    int size(){return rr-fr+1;}
    void push_back(int v){V[++rr]=v;}
    int back(){return V[rr];}
    int front(){return V[fr];}
    void pop_back(){rr--;}
    void pop_front(){fr++;}
};

int get_cost(int j)
{
    return dp[j-1]-totD[j]+abs(posx[j])+abs(posy[j]);
}

DEQ STK;

int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        STK.clear();
        scanf("%d%d",&C,&N);
        totD[0]=totW[0]=posx[0]=posy[0]=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%d",posx+i,posy+i,W+i);
            totD[i]=totD[i-1]+abs(posx[i]-posx[i-1])+abs(posy[i]-posy[i-1]);
            if(i==1)totD[i]=0;
            totW[i]=totW[i-1]+W[i];
        }
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            dp[i]=INF;
            int base_cost=totD[i]+abs(posx[i])+abs(posy[i]);
            while(STK.size()>0&&get_cost(i)<=get_cost(STK.back()))
            {
                STK.pop_back();
            }
            while(STK.size()>0&&totW[i]-totW[STK.front()-1]>C)STK.pop_front();
            STK.push_back(i);
            dp[i]=min( dp[i], base_cost+get_cost(STK.front()) );

            /*
            for(int j=1;j<=i;j++)
            {
                if(totW[i]-totW[j-1]<=C)
                    dp[i]=min( dp[i], base_cost+get_cost(j) );
            }
            */
        }
        if(kase++)puts("");
        printf("%d\n",dp[N]);
    }
    return 0;
}
