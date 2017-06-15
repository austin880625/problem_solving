#include <stdio.h>
#include <iostream>
#include <string.h>
#define LL long long int

using namespace std;

int T;
LL N;
char S[20];
char ans[20];

bool test(char x,int i)
{
    for(int j=i;S[j]!='\0';j++)
    {
        if(S[j]<x)return false;
        if(S[j]>x)return true;
    }
    return true;
}

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%s",S);
        int len=strlen(S);
        int found=0;
        for(int i=0;i<len;i++)
        {
            for(char t=S[i];t>='0';t--)
            {
                if(test(t,i)){
                    ans[i]=t;
                    if(t<S[i])
                    {
                        found=1;
                        for(int j=i+1;j<len;j++)ans[j]='9';
                    }
                    break;
                }
            }
            if(found)break;
        }
        ans[len]='\0';
        int st;
        for(st=0;ans[st]=='0';st++);
        printf("Case #%d: %s\n",kase,ans+st);
    }
    return 0;
}
