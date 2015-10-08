#include <stdio.h>
#include<iostream>
#include<string.h>
#include<set>
using namespace std;

int mabs(int x)
{
    return x>0 ? x : -x;
}

int main()
{
    string ss;
    while(cin>>ss)
    {
        int ans=0,yeee=0;
        for(int i=0;i<ss.length();i++)
        {
            if(ss[i]=='y')
            {
                ans+=mabs(i-yeee);
                yeee+=3;
            }
        }
        cout<<ans<<endl;
    }
}