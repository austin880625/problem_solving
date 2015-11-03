#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int N;
    char a[5]={'U','G','Y','T','I'};
    while(scanf("%d",&N)==1)
    {
        cout<<a[N%5]<<endl;
    }
}
