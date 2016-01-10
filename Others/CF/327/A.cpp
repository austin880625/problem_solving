#include<iostream>
#include<stdio.h>

using namespace std;
int L,a,b;
double ans,tmp;
int main()
{
    while(scanf("%d",&L)==1)
    {
        scanf("%d %d",&a,&b);
        printf("%f\n",(double)a*(double)L/((double)a+(double)b));
    }
}
