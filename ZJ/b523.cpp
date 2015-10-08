#include <stdio.h>
#include<iostream>
#include<string.h>
#include<set>
using namespace std;

int main()
{
    string ss;
    set<string> s;
    while(getline(cin,ss))
    {
        if(s.find(ss)!=s.end())
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
            s.insert(ss);
        }
        cout<<endl;
    }
}