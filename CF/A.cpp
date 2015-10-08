#include<iostream>
#include<queue>
#include<stack>
#include <stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int n,t;
    while(cin>>n>>t)
    {
        if(n>=6)
        {
            cout<<"362880";
            for(int i=0;i<n-6;i++)printf("0");
            printf("\n");
        }
        else
        {
            if(t==10&&n==1)cout<<-1<<endl;
            else{
                if(t==10&&n!=1)t=1;
                int x=1;
                for(int i=0;i<n-1;i++)x*=10;
                cout<<t*x<<endl;
            }
        }
    }
    return 0;
}