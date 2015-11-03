#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
string in;
vector<string> S;
int main()
{
    int N;
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)
        {
            cin>>in;
            S.push_back(in);
        }
        for(int i=N-1;i>=0;i--)cout<<S[i]<<endl;
    }
}
