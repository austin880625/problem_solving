/*
 ID: austin81
 PROG: beads
 LANG: C++
 */
#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<string>
#include<map>

using namespace std;
int N;

int conv(int pos)
{
    if(pos<0)return conv(N+pos);
    else return pos%N;
}

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int ans=0,tmp;
    cin>>N;
    string s;
    cin>>s;
    for(int i=0;i<N;i++)
    {
        char c1,c2;
        int t1=0,t2=0,f=1;
        c1=s[conv(i)];
        c2=s[conv(i-1)];
        //cout<<c1<<" "<<c2<<endl;
        while(c1=='w')
        {
            c1=s[conv(i+t1)];
            t1++;
            if(t1>=N){f=0;break;}
        }
        while(c2=='w'&&f)
        {
            c2=s[conv(i-1-t2)];
            t2++;
        }
        while((c1==s[conv(i+t1)]||s[conv(i+t1)]=='w')&&f)
        {
            t1++;
            if(t1>=N)f=0;
        }
        while((c2==s[conv(i-1-t2)]||s[conv(i-1-t2)]=='w')&&f)
        {
            t2++;
        }
        tmp=t1+t2;
        ans=min(N,max(tmp,ans));
    }
    cout<<ans<<endl;
    return 0;
}