#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Building
{
    int id;
    double x,y,wid,hei;
    bool operator < (const Building &rhs)const
    {
        return x<rhs.x || (x==rhs.x&&y<rhs.y);
    }
}B[105];

int n;
double X[300];

int isVisible(int x,double interval)
{
    for(int i=0;i<n;i++)
    {
        if(B[i].y<B[x].y&&B[i].hei>=B[x].hei&&interval>=B[i].x&&interval<=B[i].x+B[i].wid)return 0; 
    }
    return 1;
}

int main()
{
    int kase=0;
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=0;i<n;i++)
        {
            double t;
            cin>>B[i].x>>B[i].y>>B[i].wid>>t>>B[i].hei;
            B[i].id=i+1;
            X[2*i]=B[i].x;
            X[2*i+1]=B[i].x+B[i].wid;
        }
        sort(B,B+n);
        sort(X,X+2*n);
        //for(int i=0;i<n;i++)cout<<B[i].id<<" ";
        int m=unique(X,X+2*n)-X;
        int f=1;
        if(kase)cout<<endl;
        cout<<"For map #"<<++kase<<", the visible buildings are numbered as follows:"<<endl;
        for(int j=0;j<n;j++)
        {
            //cout<<inter<<endl;
            for(int i=0;i<m-1;i++)
            {
                double inter = (X[i]+X[i+1])/2;
                if(inter>=B[j].x&&inter<=B[j].x+B[j].wid)
                {
                    if(isVisible(j,inter)){cout<<(f ? "" :" ")<<B[j].id;f=0;break;}
                }
            }
        }
        cout<<endl;
    }
}
