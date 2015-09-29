#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
vector<int> v;
int match(int a)
{
    for(int i=0;i<v.size();i++)
    {
        if(a==v[i])return 0;
    }
    return 1;
}

int main()
{
    int a;
    int s;
    while(cin>>a)
    {
        int st=a;
        v.clear();
        
        do
        {
            v.push_back(a);
            s=0;
            while(a)
            {
                s+=(a%10)*(a%10);
                a/=10;
            }
            a=s;
            //cout<<a<<endl;
        }while(match(a)&&a!=1);
        if(a==1)cout<<st<<" is a happy number"<<endl;
        else cout<<st<<" is an unhappy number"<<endl;
    }
}