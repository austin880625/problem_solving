#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 1000005
#define LL long long int

using namespace std;

int N;
LL A,B,C;
LL X[MAXN];
LL S[MAXN];
LL dp[MAXN];

struct line
{
    LL m,b;
    line(LL _m,LL _b):m(_m),b(_b){}
    line():m(0),b(0){}
    LL val(LL x){return m*x+b;}
};

struct DQ
{
    line Q[MAXN];
    int fr,rr;
    void init(){fr=0,rr=-1;}
    DQ():fr(0),rr(-1){}
    void push(line x){Q[++rr]=x;}
    int sz(){return rr-fr+1;}
    void popback(){rr--;}
    void popfront(){fr++;}
    line back(){return Q[rr];}
    line back2(){return Q[rr-1];}
    line front(){return Q[fr];}
    line front2(){return Q[fr+1];}
};
DQ dq;
bool check(line x,line y,line z)
{
    //determine x-coordinate of the intersection of z and x,y is on the left or right of the x,y intersection
    //(y.b-x.b)/(x.m-y.m)>=(y.b-z.b)/(z.m-y.m)
    return (y.b-x.b)*(z.m-y.m)>=(y.b-z.b)*(x.m-y.m);
}

int main()
{
    scanf("%d",&N);
    scanf("%lld%lld%lld",&A,&B,&C);
    S[0]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%lld",X+i);S[i]=S[i-1]+X[i];
    }
    dp[0]=C;
    dq.init();
    //line = -2A*S[j] * S[i] +A*S[j]^2-B*S[j]+dp[j]+C
    dq.push(line(0,C));
    for(int i=1;i<=N;i++)
    {
        //cout<<i<<" "<<dq.sz()<<endl;
        while(dq.sz()>=2&&dq.front().val(S[i])<dq.front2().val(S[i]))dq.popfront();
        line L=dq.front();

        //cout<<dq.sz()<<" "<<L.m<<" "<<L.b<<endl;
        dp[i]=A*S[i]*S[i]+B*S[i]+L.val(S[i]);
        L=line(-2*A*S[i],A*S[i]*S[i]-B*S[i]+dp[i]+C);
        //cout<<L.m<<" "<<L.b<<endl;
        while(dq.sz()>=2&&check(dq.back(),dq.back2(),L))dq.popback();
        dq.push(L);
        //cout<<dp[i]<<endl;
    }
    printf("%lld\n",dp[N]);
    return 0;
}
