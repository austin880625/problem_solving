#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
char op[2];
int xy;
int x,y;
int main()
{
    while(scanf("%s",op)!=EOF)
    {
        if(op[0]=='B')
        {
            x=y=0;
            while(scanf("%s",op)!=EOF&&op[0]!='E')
            {
                scanf("%d",&xy);
                if(op[0]=='X')
                {
                    x=xy;
                }
                else if(op[0]=='Y')
                {
                    y=xy;
                }
                else if(op[0]=='U')
                {
                    y+=xy;
                }
                else if(op[0]=='D')
                {
                    y-=xy;
                }
                else if(op[0]=='R')
                {
                    x+=xy;
                }
                else if(op[0]=='L')
                {
                    x-=xy;
                }
            }
            printf("%d\n%d\n",x,y);
        }
    }
}
