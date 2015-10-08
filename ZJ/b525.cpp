#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#define mod 100000007
#define ll unsigned long long int

using namespace std;

struct mat
{
    ll a11,a12,a21,a22;
    mat(ll a,ll b,ll c,ll d):a11(a),a12(b),a21(c),a22(d){}
    mat operator *(const mat &rhs)const
    {
        mat res(0,0,0,0);
        res.a11=(a11*rhs.a11)%mod+(a12*rhs.a21)%mod;
        res.a12=(a11*rhs.a12)%mod+(a12*rhs.a22)%mod;
        res.a21=(a21*rhs.a11)%mod+(a22*rhs.a21)%mod;
        res.a22=(a21*rhs.a12)%mod+(a22*rhs.a22)%mod;
        return res;
    }
    void print()
    {
        cout<<a11<<" "<<a12<<endl<<a21<<" "<<a22<<endl<<endl;
    }
};

ll F[2];

void powmat(int k)
{
    mat base(1,1,1,0);
    mat M(1,0,0,1);
    while(k)
    {
        //base.getmod();
        if(k&1)
        {
            //cout<<k<<endl;
            //M.getmod();
            M=M*base;
            
            //M.print();
        }
        base=base*base;
        k=k>>1;
    }
    F[0]=(M.a11+M.a12)%mod;
    F[1]=(M.a21+M.a22)%mod;
}

int main()
{
    int m,f,k,maxk=2;
    while(scanf("%d %d %d",&m,&f,&k)==3)
    {
        powmat(k);
        cout<<(F[0]*f+F[1]*m)%mod<<endl;
    }
    return 0;
}
