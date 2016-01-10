#include <iostream>
#include <stdio.h>
#define MAXN 5005
#define LL long long int
using namespace std;

int dj[MAXN];
LL F[MAXN];
int find(int x){return x==dj[x]?x:dj[x]=find(dj[x]);}
LL T,N,a,b,c;
LL f(int x)
{
    return x*x*a+x*b+c;
}
LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&N,&a,&b,&c);
        int ans=N;
        for(int i=0;i<N;i++)dj[i]=i,F[i]=0;
        for(int i=0;i<N;i++)
        {
            F[i]=f(i);
            for(int j=0;j<i;j++)
            {
                int x=find(i),y=find(j);
                if(gcd(F[i],F[j])==1&&x!=y){dj[x]=y,ans--;break;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
