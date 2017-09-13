#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 1005
using namespace std;
int N;
char S[MAXN];
int main()
{
    while(scanf("%d",&N)==1)
    {
        scanf("%s",S);
        for(int i=0;i<N;i++)
        {
            if(S[i]=='o')
            {
                int j=i+1;
                while(S[j]=='g'&&S[j+1]=='o')j+=2;
                if(j!=i+1)
                {
                    printf("***");
                    i=j-1;
                }
                else printf("o");
            }
            else printf("%c",S[i]);
        }
        puts("");
    }
    return 0;
}
