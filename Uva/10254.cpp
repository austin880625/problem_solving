#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <assert.h>
#define MAXN 10000
using namespace std;
struct BINT
{
    vector<int> dig;
    BINT(){dig.clear();}
    BINT(string S)
    {
        int N=S.length();
        for(int i=N-1;i>=0;i--)
        {
            dig.push_back(S[i]-'0');
        }
    }
    void carry()
    {
        for(int i=0;i<dig.size()-1;i++)
        {
            dig[i+1]+=dig[i]/10;
            dig[i]%=10;
        }
        if(dig[dig.size()-1]>9)dig.push_back(dig[dig.size()-1]/10),dig[dig.size()-2]%=10;
    }
    void mcarry()
    {
        for(int i=0;i<dig.size()-1;i++)
        {
            if(dig[i]<0)dig[i+1]--,dig[i]+=10;
        }
        while(dig[dig.size()-1]==0)dig.pop_back();
        assert(dig[dig.size()-1]>=0);
    }
    bool operator <(const BINT &B)const{
        if(dig.size()!=B.dig.size())return dig.size()<B.dig.size();
        for(int i=dig.size()-1;i>=0;i--)
        {
            if(dig[i]!=B.dig[i])return dig[i]<B.dig[i];
        }
        return 0;
    }
    bool operator ==(const BINT &B)const{
        if(dig.size()!=B.dig.size())return false;
        for(int i=0;i<dig.size();i++)
        {
            if(dig[i]!=B.dig[i])return 0;
        }
        return 1;
    }
    bool operator >=(const BINT &B)const{
        return *this>B||*this==B;
    }
    bool operator >(const BINT &B)const{
        return !(*this==B||*this<B);
    }
    BINT operator =(BINT X)
    {
        dig.clear();
        for(int i=0;i<X.dig.size();i++)
            dig.push_back(X.dig[i]);
        return X;
    }
    BINT operator +(BINT X){
        BINT res;
        for(int i=0;i<max(X.dig.size(),dig.size());i++)
        {
            if(i<min(X.dig.size(),dig.size()))res.dig.push_back(X.dig[i]+dig[i]);
            else res.dig.push_back(max(*this,X).dig[i]);
        }
        res.carry();
        return res;
    }
    BINT operator -(BINT X){
        BINT res;
        for(int i=0;i<dig.size();i++)
        {
            if(i<X.dig.size())res.dig.push_back(dig[i]-X.dig[i]);
            else res.dig.push_back(dig[i]);
        }
        res.mcarry();
        return res;
    }
    BINT operator *(const BINT &X){
        BINT res;
        int n=0;
        for(int i=0;i<dig.size();i++)
        {
            for(int j=0;j<X.dig.size();j++)
            {
                if(i+j>=n)res.dig.push_back(dig[i]*X.dig[j]),n++;
                else res.dig[i+j]+=dig[i]*X.dig[j];
            }
        }
        res.carry();
        return res;
    }
};

void print(BINT X,int nl)
{
    for(int i=X.dig.size()-1;i>=0;i--)
    {
        printf("%d",X.dig[i]);
    }
    if(nl)puts("");
}

BINT G[MAXN];
BINT F[MAXN];
BINT ONE("1");
BINT TWO("2");

int N;
BINT calc(int n,int k)
{
    BINT res=(TWO*F[k])+G[n-k];
    //print(res,1);
    return res;
}
int rand()
{
    static int x=201511017;
    return x=x*0xdefaced+1;
}
int mabs(int x)
{
    return x>0 ? x : -x;
}
int ran(int l,int r)
{
    return l+mabs(((rand()>>16)^rand())%(r-l+1));
}
int main()
{
    G[1]=ONE;
    F[1]=ONE;
    int maxQ=-1;
    //print(BINT("64")*TWO,1);
    while(scanf("%d",&N)==1)
    {
        if(N<=maxQ){print(F[N],1);continue;}
        if(!N)printf("0");
        for(int i=2;i<=N;i++)
        {
            if(i<=maxQ)continue;
            G[i].dig.clear();
            //printf("mult");print(TWO,0);printf(" with ");print(G[i-1],1);
            G[i]=(TWO*G[i-1])+ONE;
            int kl=1,kr=i-1,a,b;
            BINT X,Y;
            while(kl<kr)
            {
                //if(kl==kr-1)break;
                a=ran(kl,kr-1);
                b=ran(a+1,kr);
                if(a>b)swap(a,b);
                X=calc(i,b);Y=calc(i,a);
                if(X>=Y)kr=b-1;
                else kl=a+1;
                //cout<<kl<<" "<<a<<" "<<b<<" "<<kr<<endl;
            }
            /*for(kl=1;kl<i-1;kl++)
            {
                //print(calc(i,kl+1),1);
                if(calc(i,kl+1)>calc(i,kl))break;
            }
            */
            F[i]=calc(i,kl);
            //print(F[i],0);printf(" ");
            //print(G[i],1);
        }
        print(F[N],1);
        maxQ=max(N,maxQ);
    }
    return 0;
}
