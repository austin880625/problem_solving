#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char s[1000];
int F[1000];
void getFail()
{
    int m=strlen(s);
    F[0]=F[1]=0;
    for(int i=1;i<m;i++)
    {
        int j=F[i];
        while(1)
        {
            if(j==0&&s[j]!=s[i]){F[i+1]=0;break;}
            if(s[j]==s[i]){F[i+1]=j+1;break;}
            j=F[j];
            //cout<<j<<endl;
        }
    }
}

int main()
{
    while(cin>>s)
    {
        int m=strlen(s);
        getFail();
        for(int i=0;i<m;i++)printf("%d ",F[i]);
        puts("");
    }
    return 0;
}
