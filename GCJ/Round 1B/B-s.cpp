#include <stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<string>
#include<map>
#include<algorithm>
#include"../Libraries/Vectors.h"
#define isFile 1
#define Problem "B"
#define SL 0
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)
#define max 10005
using namespace std;
typedef long long ll;

int lat[max][max];

int R,C,N;

int isn(int i,int j)
{
    if(!lat[i][j])
        return lat[i-1][j]+lat[i+1][j]+lat[i][j-1]+lat[i][j+1];
    else return 4;
}

int main()
{
    if(isFile)
    {
        string fileName=Problem;
        if(SL)fileName+="-large";
        else fileName+="-small";
        freopen((filePath+fileName+".in").c_str(),"r",stdin);
        freopen((filePath+fileName+".out").c_str(),"w",stdout);
    }
    int T;
    cin>>T;
    lp2(kase,1,T+1)
    {
        cin>>R>>C>>N;
        lp1(i,R+2)
        {
            lp1(j,C+2)
            {
                if(i==0||j==0||i==R+1||j==C+1)lat[i][j]=0;
                else lat[i][j]=0;
            }
        }
        int t=N;
        //int t=R*C-N;
        int ans=0;
        //int ans=(R-1)*C+(C-1)*R;
        int tmp=100,x,y;
        //cout<<ans<<endl;
        lp1(n,t)
        {
            tmp=100;
            lp2(i,1,R+1)
            {
                lp2(j,1,C+1)
                {
                    if(isn(i,j)<=tmp)
                    {
                        tmp=isn(i,j);
                        x=i;y=j;
                    }
                }
            }
            //cout<<tmp<<" "<<x<<" "<<y<<endl;
            ans+=tmp;
            lat[x][y]=1;
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
}