#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string s;
int c[52];

int main()
{
    while(cin>>s)
    {
        for(int i=0;i<52;i++)c[i]=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(c[s[i]-'a']==0)ans++;
            c[s[i]-'a']++;
        }
        printf(ans%2==1?"IGNORE HIM!":"CHAT WITH HER!");
        puts("");
    }
    return 0;
}
