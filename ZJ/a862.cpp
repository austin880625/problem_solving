#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    double a,b;
    while(cin>>a)
    {
        cin>>b;
        printf("%.4f\n",1000*a/b);
    }
}