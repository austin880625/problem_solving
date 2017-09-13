#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int T,N;
char p[10]="Bulbasaur";
char s[100006];
int cnt[300];
int ans;
int len;

int main()
{
    while(scanf("%s",s)==1)
    {
        ans=100000000;
        for(int i=0;i<300;i++)cnt[i]=0;
        len=strlen(s);
        for(int i=0;i<len;i++)cnt[s[i]]++;
        for(int i=0;i<9;i++)
        {
            if(p[i]=='a'||p[i]=='u')ans=min(ans,cnt[p[i]]/2);
            else ans=min(ans,cnt[p[i]]);
            //cout<<ans<<" "<<p[i]<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
