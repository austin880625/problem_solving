#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>
#define MOD 1000000007
#define LL long long int
using namespace std;

LL N,K;
struct inter
{
    LL l,r;
    vector<LL> coff;
    LL len(){return r-l+1;}
    void resize(LL _l,LL _r){r=_r;l=_l;coff.clear();coff.resize(_r-_l+1);}
    inter operator =(inter A)
    {
        coff=A.coff;
        l=A.l,r=A.r;
        return A;
    }
    void print()
    {
        printf("%lld %lld\n",l,r);for(int i=0;i<coff.size();i++)printf("%lld ",coff[i]);puts("");
    }
};
inter mult(inter A,inter B)
{
    //expand
    assert(A.len()==B.len());
    //A.print();
    LL p=(N-A.r-1LL)/K,q=(N-B.r-1LL)/K;
    //cout<<p<<" "<<q<<endl;
    inter X;X.resize(N-(p+q+2LL)*K,N-(p+q)*K-2LL);
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<K;j++)
        {
            X.coff[i+j]+=(A.coff[i]*B.coff[j])%MOD;
            X.coff[i+j]%=MOD;
        }
    }
    //shrink
    for(int i=0;i<K-1;i++)
    {
        if(i==K-2)assert((N-X.r)%K==0);
        int d=X.coff[X.len()-1];
        for(int j=0;j<K;j++)
        {
            X.coff[X.len()-2-j]+=d;
            X.coff[X.len()-2-j]%=MOD;
        }
        X.coff.pop_back();X.r--;
    }
    //X.print();
    return X;
}
inter C;
vector<inter> Pow;
vector<LL> init;

int main()
{
    while(scanf("%lld%lld",&N,&K)==2)
    {
        N--;
        C.resize(N-K,N-1);
        Pow.clear();
        for(int i=0;i<K;i++)C.coff[i]=1LL;
        Pow.push_back(C);
        for(int i=1;Pow[i-1].l>=K;i++)Pow.push_back(mult(Pow[i-1],Pow[i-1]));
        //cout<<Pow.size()<<endl;
        init.resize(K);init[0]=1LL;
        for(int i=1;i<K;i++)
        {
            if(i<=N)init[i]=(init[i-1]<<1LL)%MOD;
        }
        if(N<K){printf("%lld\n",init[N]);continue;}
        //for(int i=1;i<K;i++)C.coff[i]=0;
        //for(int i=0;i<Pow.size();i++)Pow[i].print();
        for(int i=Pow.size()-1;i>=0;i--)
        {
            LL p=(N-C.r-1)/K,q=(N-Pow[i].r-1)/K;
            //cout<<p<<" "<<q<<endl;
            if(N-(p+q+2LL)*K>=0)C=mult(C,Pow[i]);
            //C.print();
        }
        //C.print();
        assert(C.l<K);
        LL ans=0LL;
        for(int i=K;i<=C.r;i++)
        {
            init.push_back(0LL);
            for(int j=i-K;j<i;j++)init[i]=(init[i]+init[j])%MOD;
        }
        //assert(0);
        //C.print();
        for(LL i=C.l;i<=C.r;i++)
        {
            ans+=(init[i]*C.coff[i-C.l])%MOD;
            ans%=MOD;
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
}
