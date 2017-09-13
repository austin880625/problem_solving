#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int A,B;

void extgcd(int a,int b,int &x,int &y)
{
    //cout<<a<<" "<<b<<endl;
    if(!b)
    {
        //ax=a
        x=1,y=0;return ;
    }
    int q=a/b,r=a-b*q;
    //ax-by=1
    //(bq+r)x-by=1
    //rx-b(y-qx)=1
    //b(qx-y)-r(-x)=1
    int x0,y0;
    extgcd(b,r,x0,y0);
    x=-y0;
    y=q*x-x0;
}

int inv(int a)
{
    //a*x=1(mod 9901)
    //ax-1=9901y
    //ax-9901y=1
    int x,y;
    extgcd(a,9901,x,y);
    return x;
}

int getp(int x,int p)
{
    if(x==1||x==0)return x;
    if(x%9901==1)return p+1;
    p++;
    int t=1;
    for(long long int m=x;p;m=m*m,m%=9901)
    {
        if(p&1)
        {
            t*=m;
            t%=9901;
        }
        p>>=1;
    }
    t--;t=(t+9901)%9901;
    t*=(inv(x -1)+9901)%9901;
    return (t+9901)%9901;
}

vector<long long int> prime;

int main()
{
    prime.push_back(2);
    for(long long int i=3;i*i<=50000000;i++)
    {
        int f=1;
        for(int j=0;j<prime.size()&&prime[j]*prime[j]<=i;j++)
        {
            if(i%prime[j]==0)f=0;
        }
        if(f)prime.push_back(i);
    }
    //cout<<"endl"<<endl;
    while(scanf("%d%d",&A,&B)==2)
    {
        if(A==0){printf("%d\n",A);continue;}
        if(A==1){printf("%d\n",A);continue;}
        int ans=1;
        for(int i=0,orig=A;i<prime.size()&&prime[i]*prime[i]<=orig;i++)
        {
            int power=0;
            while(A%prime[i]==0)A/=prime[i],power++;
            ans*=getp(prime[i],power*B);
            ans%=9901;
        }
        ans*=getp(A,B);
        printf("%d\n",ans%9901);
    }
    return 0;
}
