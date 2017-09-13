#include <stdio.h>
#include <iostream>
#include <vector>

#define MAXN 10005
#define LL long long
#define MOD 100000007

using namespace std;

vector<LL> C[MAXN];
int N;
LL ans[MAXN];

int main()
{
    C[1].push_back(1);C[1].push_back(1);C[1].push_back(0);
    for(int i=2;i<=10000;i++)
    {
        C[i].push_back(1);
        for(int j=1;j<=i;j++)C[i].push_back((C[i-1][j]+C[i-1][j-1])%MOD);
        C[i].push_back(0);
    }
    for(int i=0;i<MAXN;i++)ans[i]=0;ans[1]=1;
    puts("#include<stdio.h>");
    puts("int N;");
    N=10000;
    printf("long long int ans[10001]={0");
    for(int i=1;i<=N;i++)
    {
        ans[i]=1;
        for(int j=1;j<i;j++)
        {
            ans[i]=(ans[i]+ans[j]*C[i-1][j])%MOD;
        }
        printf(",%lld",ans[i]);
    }
    printf("};\n");
    puts("int main(){while(scanf(\"%d\",&N)==1){printf(\"%lld\\n\",ans[N]);}}");

    return 0;
}
