#include <iostream>
#include <stdio.h>
#include <string.h>
#define LL long long int
#define MAXN 5005
#define MOD 1000000007
using namespace std;

int n;
char x[MAXN];
LL dp[MAXN][MAXN];

bool smaller(int l1,int r1,int l2,int r2)
{
    //printf("%d %d %d %d\n",l1,r1,l2,r2);
    if(l1==0)return true;
    if(x[l1]=='0'||x[l2]=='0')return false;
    if(r1-l1!=r2-l2)return r1-l1<r2-l2;
    for(int i=l1,j=l2;i<=r1;i++,j++)
    {
        if(x[i]!=x[j])return x[i]<x[j];
    }
    return false;
}

LL DP(int PL,int L)
{
    if(PL!=-1&&L!=-1&&dp[PL][L]!=0)return dp[PL][L];
    LL res=1;
    for(int i=L+1;i<n;i++)
    {
        //if(PL==0&&L==1&&i==3)cout<<smaller(PL,L,L+1,i)<<"Yee"<<endl;
        if(smaller(PL,L,L+1,i))
        {
            for(int &j=i;j<n;j++){if(smaller(L+1,j,j+1,n))res+=DP(L+1,j),res%=MOD;else break;}
            //break;
        }
        //else break;
    }
    return dp[PL][L]=res;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        scanf("%s",x+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            dp[i][j]=0;
        }
        printf("%I64d\n",DP(0,0)%MOD);
    }
    return 0;
}
