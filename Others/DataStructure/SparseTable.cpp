#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int d[1000][1000];
int n;

int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i][0];
        }
        for(int j=1;(1<<j)<=n;j++)
        {
            for(int i=1;i+(1<<(j-1))<=n;i++)
                d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
        int p,q;
        while(cin>>p>>q)
        {
            if(p==q&&p==0)break;
            int L=0;
            while((1<<(L+1))<=(q-p+1))L++;
            cout<<min(d[p][L],d[q-(1<<L)+1][L])<<endl;
        }
    }
    return 0;
}
