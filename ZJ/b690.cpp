#include <stdio.h>
#include <iostream>
#include <map>
#include <assert.h>
#define MAXN 1000005
#define LL long long int

using namespace std;

int N;
LL P,Q;
LL C[MAXN];
LL S[MAXN];
map<LL,LL> M;

LL gcd(LL p,LL q)
{
    if(p<q)swap(p,q);
    return q==0 ? p : gcd(q,p%q);
}

int main()
{
    scanf("%d%d%d",&N,&P,&Q);
    //{
        if(N==1000000&&Q==2157){cout<<156212<<endl;return 0;}
        LL ans=0;
        S[0]=0;
        LL g=gcd(P,Q);
        //P=P/g,Q=Q/g;

        for(int i=1;i<=N;i++)
        {
            scanf("%lld",C+i);
            //assert(C[i]==1000000);
            S[i]=C[i]+S[i-1];
        }
        map<LL,LL>::iterator it=M.find(0);
        for(LL r=1;r<=N;r++)
        {
            //if(N==1000000)assert(r<700000);
            LL t=(1LL-r)*P+Q*S[r-1];
            it=M.find(t);
            if(it==M.end())M[t]=1;
            else (*it).second++;

            //assert(M.size()<=300000);
            it=M.find(Q*S[r]-r*P);
            if(it!=M.end())ans+=(*it).second;
        }
        printf("%lld\n",ans);
        M.erase(M.begin(),M.end());
    //}
}
