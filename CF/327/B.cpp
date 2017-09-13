#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int N,M;
int table[27];
char x[2],y[2];
int main()
{
    string S;
    while(scanf("%d %d",&N,&M)==2)
    {
        cin>>S;
        for(int i=0;i<27;i++)table[i]=i;
        for(int i=0;i<M;i++)
        {
            scanf("%s %s",x,y);
            for(int j=0;j<26;j++)
            {
                if(table[j]==x[0]-'a')table[j]=y[0]-'a';
                else if(table[j]==y[0]-'a')table[j]=x[0]-'a';
            }
            /*for(int i=0;i<S.length();i++)
            {
                cout<<(char)(table[S[i]-'a']+'a');
            }
            puts("");
            */
        }
        for(int i=0;i<S.length();i++)
        {
            cout<<(char)(table[S[i]-'a']+'a');
        }
        cout<<endl;
    }
}
