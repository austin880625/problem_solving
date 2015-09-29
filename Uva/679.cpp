#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int num,D;

int drop(int x,int ord,int depth)
{
    if(depth==D)
    {
        return x;
    }
    if(ord%2==1)
    {
        int xp=x*2;
        int ordp=(ord+1)/2;
        return drop(xp,ordp,depth+1);
    }
    else
    {
        int xp=x*2+1;
        int ordp=ord/2;
        return drop(xp,ordp,depth+1);
    }
}

int main()
{
    int T;
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        int I;
        cin>>D>>I;
        num=1;
        cout<<drop(num,I,1)<<endl;
    }
    int t;
    cin>>t;
    return 0;
}
