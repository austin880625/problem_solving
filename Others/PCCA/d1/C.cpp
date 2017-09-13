#include <stdio.h>
#include <iostream>
#include <vector>

#define MAXN 3005

using namespace std;

vector<int> P;
int al[MAXN];

void pre()
{
    P.push_back(2);
    for(int i=3;i<MAXN;i++)
    {
        int f=1;
        for(int j=0;j<P.size()&&P[j]*P[j]<=i;j++){
            if(i%P[j]==0){f=0;break;}
        }
        if(f)P.push_back(i);
    }
    for(int i=1;i<MAXN;i++){
        int t=0;
        for(int j=0;j<P.size();j++){
            if(i%P[j]==0)t++;
        }
        if(t==2)al[i]++;
    }
    al[0]=0;
    for(int i=1;i<MAXN;i++)al[i]=al[i-1]+al[i];
}

int N;

int main()
{
    pre();
    while(scanf("%d",&N)==1){
        printf("%d\n",al[N]);
    }
    return 0;
}
