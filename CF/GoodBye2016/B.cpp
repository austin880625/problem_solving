#include <stdio.h>
#include <iostream>

using namespace std;

int N,ans;
int nowy;
char com[100];

int main()
{
    while(scanf("%d",&N)==1)
    {
        nowy=10000;int x;
        int ans=1;
        for(int i=0;i<N;i++)
        {
            scanf("%d %s",&x,com);
            if(com[0]=='E'||com[0]=='W')
            {
                if(nowy==10000||nowy==-10000)ans=0;
                continue;
            }
            if(com[0]=='S')
            {
                if(nowy-x<-10000){ans=0;continue;}
                nowy-=x;
            }
            else if(com[0]=='N')
            {
                if(nowy+x>10000){ans=0;continue;}
                nowy+=x;
            }
        }
        if(nowy!=10000)ans=0;
        printf(ans ? "YES" : "NO");
        puts("");
    }
    return 0;
}
