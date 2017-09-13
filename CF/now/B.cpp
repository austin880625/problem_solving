#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
char TAT;
int P[1000];
char vowel[6]={'a','e','i','o','u','y'};

int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>P[i];
        }
        int match=0;
        getchar();
        int i=0;
        int ans=0;
        while(TAT=getchar()){
            if(TAT=='\n')
            {
                if(ans==P[i])match++;
                if(i==N-1)break;
                else i++;ans=0;
            }
                for(int k=0;k<6;k++)
                    if(TAT==vowel[k])ans++;
        }
        puts(match==N ? "YES" : "NO");
    }
    return 0;
}
