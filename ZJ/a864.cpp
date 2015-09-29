#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>

using namespace std;

double classes[7]={-0.35,-0.25,0.0,0.25,0.5,1.0,1.5};
char classname[7]={'O','B','A','F','G','K','M'};

struct star
{
    string name;
    double b,v;
    void identify()
    {
        int i;
        for(i=0;i<7;i++)
        {
            if(b-v<classes[i])break;
        }
        cout<<name;
        printf(" %.2f ",b-v);
        cout<<classname[i-1]<<endl;
    }
};

int main()
{
    while(1)
    {
        star A;
        cin>>A.name;
        if(A.name=="END")break;
        cin>>A.b>>A.v;
        A.identify();
    }
}