#include <iostream>
#include <stdio.h>
#include <string.h>
#define LL unsigned long long
#define MAXN 1000005
using namespace std;

const LL p=1111111111111111111;
const LL x=231;
LL xp[MAXN];
LL hashS[MAXN];
char S[MAXN];
char T[MAXN];
int N,M;

LL hash(int l,int r)
{
    //hash(l,r)=A[l]*xp[r-l]+A[l+1]*xp[r-l-1]+...+A[r-1]*xp[1]+A[r]
    return hashS[r]-xp[r-l+1]*hashS[l-1];
}

int main()
{
    while(1)
    {
        scanf("%s",S);
        N=strlen(S);
        xp[0]=1;hashS[0]=(LL)S[0];
        for(int i=1;i<=N;i++)xp[i]=xp[i-1]*x;
        //hashT[i]=T[0]*xi+T[1]*xi-1+...+T[i];
        for(int i=1;i<N;i++)hashS[i]=x*hashS[i-1]+(LL)S[i];
        scanf("%s",T);
        M=strlen(T);
        LL hashT=(LL)T[0];
        for(int i=1;i<M;i++)hashT=x*hashT+(LL)T[i];
        printf("%lld\n",hashT);

        for(int i=0;i<N;i++)
        {
            //printf("%lld\n",hash(i,i+M-1));
            if(hash(i,i+M-1)==hashT)printf("%d ",i);
        }
        puts("");
    }
    return 0;
}
