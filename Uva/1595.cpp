#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int T,n;

struct p
{
    int x,y;
    bool operator < (const p &rhs)const
    {
        return x<rhs.x;
    }
}P[1005];

double mabs(double x){
    return x>0 ? x : -x;
}

int isSym()
{
    double m=((double)P[0].x+(double)P[n-1].x)/2;
    for(int i=0;i<n;i++)
    {
        int f=0;
        for(int j=0;j<n;j++)
        {
            if(P[i].x==m){f=1;break;}
            if(i!=j)
            {
                p p1=P[i],p2=P[j];
                if(p1.y==p2.y&&mabs((double)m-(double)p1.x)==mabs((double)p2.x-(double)m))f=1;
            }
        }
        if(!f){return 0;}
    }
    return 1;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>P[i].x>>P[i].y;
        }
        sort(P,P+n);
        cout<<(isSym() ? "YES" : "NO")<<endl;
    }
    return 0;
}
