#include <stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int used[10];
int N;

int main()
{
    while(scanf("%d",&N)==1&&N!=0)
    {
        gen_perm();
        
    }
    
    return 0;
}