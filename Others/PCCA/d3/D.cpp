#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<int> v;
int main()
{
    while(cin>>s)
    {
        v.clear();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='1'&&s[i]<='3')v.push_back(s[i]-'0');
        }
        sort(v.begin(),v.end());
        printf("%d",v[0]);
        for(int i=1;i<v.size();i++)
        {
            printf("+%d",v[i]);
        }
        puts("");
    }
    return 0;
}
