#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

string S;
map<string,int> CNT;
int N;

int main()
{
    while(scanf("%d",&N)==1)
    {
        CNT.clear();
        int ans=0;
        for(int i=0;i<N;i++)
        {
            cin>>S;
            ans=max(ans,++CNT[S]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
