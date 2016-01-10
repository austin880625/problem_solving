#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc,char *argv[])
{
    printf("%d\n",argc);
    if(argc==2)
    {
        if(argv[1][0]=='A')printf("Bello!");
        else if(argv[1][0]=='B')printf("Yeee!");
    }
    else
    {
        printf("No arguments");
    }
    puts("");
    return 0;
}
