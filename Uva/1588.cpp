#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
char top[105];
char bottom[105];
int ans;
int main()
{
    while(scanf("%s",bottom)!=-1&&scanf("%s",top)!=-1)
    {
        ans=10000000;

        int lt=strlen(top),lb=strlen(bottom);
        if(lt>lb){swap(top,bottom);swap(lt,lb);}
        //printf("%s\n",bottom);
        //printf("%s\n",top);
        for(int i=0;i<lb+lt-1;i++)
        {
            //for(int j=0;j<i;j++)printf(" ");
            //printf("%s\n",top);
            //for(int j=0;j<lt-1;j++)printf(" ");
            //printf("%s\n",bottom);
            int ok=1;
            for(int j=0;j<lt;j++)
            {
                int now=i-lt+1+j;
                //if(i>=60)cout<<i<<" "<<now<<endl;
                if(now<0||now>=lb)continue;
                if(top[j]-'0'+bottom[now]-'0'>3){ok=0;break;}
            }
            if(ok)
            {
                int tmp=lb+lt-(i+1>lt ? lt : i+1)+(i>=lb ? i-lb+1 : 0);
                ans=min(ans,tmp);
                //cout<<ans<<endl;
            }
        }
        if(ans==10000000)ans=lt+lb;
        printf("%d\n",ans);
        memset(top,0,sizeof(top));
        memset(bottom,0,sizeof(bottom));
    }
    return 0;
}
