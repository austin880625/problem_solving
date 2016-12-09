#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 50000006

using namespace std;

int N;
char s[MAXN];
int z[MAXN];

int main()
{
    while(scanf("%s",s)==1)
    {
        N=strlen(s);
        for(int i=0;i<N;i++)z[i]=0;
        z[0]=N;
        int L=0,R=0;
        int ans=-1;
        for(int i=1;i<N;i++)
        {
            int ii=i-L;

            if(i>R)
            {
                int x=i;
                while(s[x]==s[x-i])x++;
                z[i]=x-i;
                if(x>i)L=i,R=x-1;
            }
            else if(i+z[ii]-1>=R)
            {
                int x=R+1;
                while(s[x]==s[x-i]&&x<N)x++;
                z[i]=x-i;
                L=i;
                R=x-1;
            }
            else
            {
                z[i]=z[ii];
            }
            if(i+z[i]==N&&N%(N-z[i])==0){ans=i;break;}
        }
        if(ans!=-1)
            s[ans]='\0';
        printf("%s",s);
        puts("");
    }
    return 0;
}
