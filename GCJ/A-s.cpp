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
#define Problem "A"
#define SL 1
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)

using namespace std;
typedef long long ll;



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
    int R,C,W;
    cin>>T;
    lp2(kase,1,T+1)
    {
        cin>>R>>C>>W;
        int r=C/W;
        if(r*W!=C)r++;
        r*=R;
        r+=(W-1);
        cout<<"Case #"<<kase<<": "<<r<<endl;
    }
}