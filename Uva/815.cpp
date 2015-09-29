#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;

double ans,ans2;
int m,n,water,area;
int region[35][35];

int canFill(double ele)
{
    int toFill=0,D=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(region[i][j]<ele)toFill+=100;
            if(region[i][j]<=ele-1)D+=100;
        }
    }
    if(water>=toFill){water-=toFill; return 1;}
    else
    {
        ans+=(double)water/(double)toFill;
        ans2=((double)D*100.0)/(double)area;
        return 0;
    }
}

int main()
{
    int T=0;
    while(cin>>m>>n)
    {
        T++;
        if(m==0&&n==0)break;
        area=m*n*100;
        int mini=2147483647;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>region[i][j];
                mini=min(mini,region[i][j]);
            }
        }
        cin>>water;
        ans=mini;
        while(canFill(ans+1)){ans+=1.0;}
        cout<<"Region "<<T<<endl;
        cout<<"Water level is "<<fixed<<setprecision(2)<<ans<<" meters."<<endl;
        cout<<ans2<<" percent of the region is under water."<<endl<<endl;
    }
    return 0;
}
