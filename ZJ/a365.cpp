#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
string in;
int N;
int edge[12][4]={
    {3,-1,-1,-1},
    {4,-1,-1,-1},
    {3,-1,-1,-1},
    {0, 2, 4, 7},
    {1, 3, 5, 8},
    {4,-1,-1,-1},
    {7,-1,-1,-1},
    {3, 6, 8, 10},
    {4, 7, 9, 11},
    {8,-1,-1,-1},
    {7,-1,-1,-1},
    {8,-1,-1,-1}
};
int F[8192];

int check(int state)
{
    //for(int i=11;i>=0;i--)printf("%d",(state>>i)&1);
    //puts("");
    if(F[state]!=-1)return F[state];
    int res=0;
    for(int i=0;i<12;i++)
    {
        //cout<<i<<" "<<((state>>i)^1)<<endl;
        int nxt=state;
        if((state>>i)&1)
        {
            nxt=(state)^(1<<i);
            res|=(!check(nxt));
        }
        for(int j=0;j<4;j++)
        {
            if(edge[i][j]==-1)break;
            if((nxt>>edge[i][j])&1)res|=(!check(nxt^(1<<edge[i][j])));
        }
    }
    return F[state]=res;
}

int main()
{
    scanf("%d",&N);
    while(N--)
    {
        for(int i=0;i<8192;i++)
        {
            F[i]=-1;
        }
        F[0]=1;
        cin>>in;
        int S=0;
        //cout<<in<<endl;
        for(int i=0;i<12;i++)
        {
            S<<=1;
            S|=(int)(in[i]-'0');
        }
        //for(int i=11;i>=0;i--)printf("%d",(S>>i)&1);
        //puts("");
        printf("%d",check(S));
    }
    puts("");

    return 0;
}
