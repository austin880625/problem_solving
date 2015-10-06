#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>

#define inf 1073741824

using namespace std;

int n,hei,ans;
int h[1005];
int got[1005];

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
        memset(got,0,sizeof(got));
        ans=hei=0;
        
        while(hei!=n)
        {
            for(int i=0;i<n;i++)
            {
                if(hei>=h[i]&&!got[i])
                {
                    hei++;
                    got[i]=1;
                }
            }
            if(hei==n)break;
            
            ans++;
            for(int i=n-1;i>=0;i--)
            {
                if(hei>=h[i]&&!got[i])
                {
                    hei++;
                    got[i]=1;
                }
            }
            if(hei!=n)ans++;
            //cout<<ans<<endl;
        }
        
        printf("%d\n",ans);
    }
    return 0;
}