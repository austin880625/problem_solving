#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
string s[55];

int cmp(string a,string b)
{
    int lm=a.length(),ln=b.length();
    for(int i=0;i<lm+ln;i++)
    {
        if(i>=lm)
        {
            if(i<ln){if(b[i-lm]!=b[i])return b[i-lm]<b[i];}
            else {if(b[i-lm]!=a[i-ln])return b[i-lm]<a[i-ln];}
        }
        else
        {
            if(i<ln){if(a[i]!=b[i])return a[i]<b[i];}
            else {if(a[i]!=a[i-ln])return a[i]<a[i-ln];}
        }
    }
    return 0;
}

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)cin>>s[i];
        sort(s,s+n,cmp);
        for(int i=n-1;i>=0;i--)cout<<s[i];
        if(n==0)break;
        cout<<endl;
    }
}
