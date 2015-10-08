#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
string s;

int main() {
    // your code goes here
    int T;
    scanf("%d",&T);
    getline(cin,s);
    while(T--)
    {
        getline(cin,s);
        //cout<<s<<endl;
        int num=0,sum=0,l=s.length(),sign=1;
        for(int i=0;i<l;i++)
        {
            if(s[i]==' '){sum+=(sign*num);num=0;sign=1;}
            else if(s[i]=='-'){sign=-1;}
            else {
                num=num*10+(s[i]-'0');
                if(i==l-1){sum+=(sign*num);}
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}