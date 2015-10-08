#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include <stdio.h>
#include<string.h>

using namespace std;
int n,t;
char V[100005];
int main()
{
    string s1,s2;
    
    vector<int> same,diff;
    while(cin>>n)
    {
        cin>>t;
        cin>>s1;
        cin>>s2;
        same.clear();
        diff.clear();
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[i])same.push_back(i);
            else diff.push_back(i);
        }
        int d=diff.size();
        int r=t-((d/2)+(d%2));
        //cout<<d<<" "<<r<<endl;
        if(r<0||r>same.size()){cout<<-1<<endl;continue;}
        for(int i=0;i<d;i++)
        {
            if(i<d/2)V[diff[i]]=s1[diff[i]];
            else V[diff[i]]=s2[diff[i]];
            if(d%2&&i==d/2)
            {
                int j;
                for(j=0;j<26&&(s1[diff[d/2]]!=j+'a'&&s2[diff[d/2]]!=j+'a');)j++;
                V[diff[d/2]]=j+'a';
            }
        }
        int x=r;
        for(int i=0;i<same.size();i++)
        {
            if(x>0)
            {
                int j;
                for(j=0;j<26&&(s1[same[i]]==j+'a');)j++;
                V[same[i]]=j+'a';
                x--;
            }
            else
            {
                V[same[i]]=s1[same[i]];
            }
        }
        V[n]='\0';
        cout<<V<<endl;
        
    }
    return 0;
}