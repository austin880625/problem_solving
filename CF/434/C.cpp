#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

string s;

char vow[5]={'a','e','i','o','u'};
vector<int> v;
int isTypo(int pos)
{
    for(int i=0;i<5;i++)
    {
        if(s[pos]==vow[i]||s[pos-1]==vow[i]||s[pos-2]==vow[i])return 0;
    }
    if(s[pos]==s[pos-1]&&s[pos-1]==s[pos-2])return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>s)
    {
        v.clear();
        int im=-1;
        if(s.length()<=2){cout<<s<<endl;continue;}
        for(int i=2;i<s.length();i++)
        {
            if(isTypo(i)&&i>im)
            {
                v.push_back(i-1);im=i+1;
            }
        }
        int t=0;
        if(v.size()==0){cout<<s<<endl;continue;}
        for(int i=0;i<s.length();i++)
        {
            cout<<s[i];
            if(i==v[t])t++,cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
