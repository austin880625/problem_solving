#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

long long int N,p;
string s;
long long int b,a;

int main()
{
    while(cin>>N)
    {
        if(N%2==0)cout<<N/2<<endl;
        else cout<<-N/2-1<<endl;
    }
    return 0;
}
