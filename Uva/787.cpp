#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{
    int all[1000];
    int num,len;
    while(1)
    {
       while(cin>>num)
       {
           if(num==-999999)break;
           all[len++]=num;
       }
    }
    return 0;
}
