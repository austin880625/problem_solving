#include <stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<string>
#include<map>
#include<algorithm>
#include"../Libraries/Vectors.h"
#define isFile 0
#define Problem "A"
#define SL 0
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)

using namespace std;
typedef long long ll;

int C(int n,int m)
{
    if(n==m||m==0)return 1;
    else
    {
        ll P=1;
        for(int i=m+1;i<=n;i++)P*=i;
        for(int i=1;i<=n-m;i++)P/=i;
        return P;
    }
}

int fc(int n)
{
    int res=0,P;
    for(int i=0;i<=n/2;i++)
    {
        P=1;
        for(int j=0;j<n-2*i;j++)
        {
            P*=3;
        }
        int D=(i%2 ? -1 : 1)*C(n-i,i)*P;
        //cout<<D<<endl;
        res+=D;
    }
    return res;
}

int main()
{
    int K;
    while(cin>>K)
    {
        //cout<<C(10,3);
        cout<<fc(K)<<endl;
    }
}