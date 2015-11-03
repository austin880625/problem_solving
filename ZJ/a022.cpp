#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
string s;
int main()
{
    int res=1;
    while(cin>>s)
    {
        res=1;
        
        int len=s.length();
        if(len&1)len--;
        for(int i=0;i<len/2;i++)
        {
            if(s[i]!=s[s.length()-i-1]){res=0;break;}
        }
        if(res)printf("yes\n");
        else printf("no\n");
    }
}
