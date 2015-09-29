#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

vector<int> p;
vector<int> s;
vector<int> h1;

int n,ans;

int main()
{
    int Z;
    cin>>Z;
    while(Z--)
    {
        ans=0;
        p.clear();
        s.clear();
        h1.clear();
        scanf("%d",&n);
        int tp,ts;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tp);
            p.push_back(tp);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ts);
            s.push_back(ts);
        }
        
        int level=s[0];
        for(int i=0;i<n;i++)
        {
            if(level>s[i])level=s[i];
            else if(level<p[i])level=p[i];
            h1.push_back(level);
        }
        level=s[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(level>s[i])level=s[i];
            else if(level<p[i])level=p[i];
            ans+=min(level,h1[i])-p[i];
        }

        printf("%d\n",ans);
    }
    return 0;
}
