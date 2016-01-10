#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 500005
using namespace std;
string T;
string P;
int f[MAXN];
int m;

void getfail()
{
    m=P.length();
    f[0]=0;f[1]=0;
    for(int i=1;i<m;i++)
    {
        int j=f[i];
        while(j&&P[i]!=P[j])j=f[j];
        if(P[i]==P[j])f[i+1]=j+1;
        else f[i+1]=0;
    }
}

void find()
{
    int n=T.length();
    int j=0;
    int fir=0;
    for(int i=0;i<n;i++)
    {
        while(j&&P[j]!=T[i])j=f[j];
        if(P[j]==T[i])j++;
        if(j==m)
        {
            if(fir++)printf(" %d",i-m+1);
            else printf("%d",i-m+1);
        }
    }
}

int main()
{
    while(cin>>P)
    {
        cin>>T;
        getfail();
        find();
        puts("");
    }
    return 0;
}
