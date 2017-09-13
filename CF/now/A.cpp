#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int F;
int H,M;
string TAT;

int main()
{
    while(scanf("%d",&F)==1)
    {
        scanf("%d:%d",&H,&M);
        int rounded=0;
        if(M>59)
        {
            rounded=1;
            M%=10;
        }

        if(F==12)
        {
            if(H==0)H=1;
            if(H>12)
            {
                if(H%10!=0)H%=10;
                else H=10;
            }
        }
        else if(F==24)
        {
            if(H>23)H%=10;
        }

        if(H<10)printf("0");
        printf("%d:",H);
        if(M<10)printf("0");
        printf("%d\n",M);
    }
    return 0;
}
